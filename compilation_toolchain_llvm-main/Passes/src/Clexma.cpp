
#include "llvm/IR/Instructions.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/Transforms/Utils/Clexma.h"
#include "llvm/IR/DebugInfo.h"
#include "llvm/IR/DebugProgramInstruction.h"
#include "llvm/Support/Debug.h"     
#include "llvm/BinaryFormat/Dwarf.h"


using namespace llvm;


void ClexmaPass::collectNameInfo(Function& F) {
    for(auto& BB : F) {
        for(auto& I : BB) {
            this->collectNameInfo(I);
        }
    }
}


bool ClexmaPass::is_stabbing_function_name(std::string func_name) {
    if(func_name.find("clexma_log") != std::string::npos) {
        return true;
    } else {
        return false;
    }
}


void ClexmaPass::collectNameInfo(Instruction& I){
    for(DbgRecord& DR : I.getDbgRecordRange()) {
        if(auto *ValueRecord = dyn_cast<DbgVariableRecord>(&DR)) {
            // the instruction contains dbgvariable records
            DILocalVariable* LocalVar = ValueRecord->getVariable();
            Value* Addr = ValueRecord->getAddress();
            bool isPointer = false;
            StringRef basedTypeName;
            StringRef scopeName = LocalVar->getScope()->getName();
            if(auto* DerivedType = dyn_cast<DIDerivedType>(LocalVar->getType())) {
                if(DerivedType->getTag() == dwarf::DW_TAG_pointer_type) {
                    isPointer = true;
                    if(!DerivedType->getBaseType()){
                        basedTypeName = "unknown";
                    } else {
                        if (auto *BaseType = dyn_cast<DIBasicType>(DerivedType->getBaseType())) {
                            if (BaseType->getTag() == dwarf::DW_TAG_unspecified_type) {
                                basedTypeName = "void";
                            } else {
                                basedTypeName = BaseType->getName();
                            }
                        }
                        else if (auto *DerivedBaseType = dyn_cast<DIDerivedType>(DerivedType->getBaseType())) {
                            basedTypeName = "recur_ptr";
                        }
                        else if (auto *CompositeType = dyn_cast<DICompositeType>(DerivedType->getBaseType())) {
                            basedTypeName = CompositeType->getName();
                        }
                        else {
                            basedTypeName = "unknown";
                        }
                    }
                }
                this->reg2Name[Addr] = LocalVar->getName().str() + " Function:" + scopeName.str();
            }

            if(LocalVar) {
                errs() << "Variable addr: " << *Addr << "\n";
                errs() << "Variable name: " << LocalVar->getName() << "\n";
                if(isPointer) {
                    errs() << "Pointer variable type: " << basedTypeName << "\n";
                } else {
                    errs() << "Variable type: " << LocalVar->getType()->getName() << "\n";
                }
                errs() << "Variable scope: " << scopeName << "\n";
            }
        }
    }
}

void ClexmaPass::createMallocMemlogStab(CallInst*    CI,
                                        Function&    F,
                                        BasicBlock&  BB,
                                        unsigned     line_num,
                                        StringRef    file_name) {
    if(CI->getCalledFunction()->getName() == "malloc") {
        // find the instruction that stores the malloced ptr value to the ptr variable in stack
        StringRef var_name;
        for(auto *iterI : CI->users()) {
            if(auto* iterSI = dyn_cast<StoreInst>(iterI)) {
                if(iterSI->getValueOperand() == CI) {
                    // find the instruction that store the malloced ptr to the stack variable
                    Value* stored_ptr = iterSI->getPointerOperand();
                    if(this->reg2Name.find(stored_ptr) != this->reg2Name.end()) {
                        var_name = this->reg2Name[stored_ptr];
                    } else {
                        errs() << "ERROR: malloc does not found source var name\n";
                    }
                }
            }
        }
        // begin stabbing
        for(auto itr = BB.begin(); itr != BB.end(); ++itr) {
            if(&*itr == CI){
                IRBuilder<> builder(&BB, std::next(itr));
                Function* log_malloc_func = F.getParent()->getFunction("clexma_log_malloc_result");
                if(!log_malloc_func) {
                    // If the function does not exist, create it
                    Type *Int8PtrTy = PointerType::get(Type::getInt8Ty(F.getContext()), 0);
                    FunctionType *FT = FunctionType::get(Type::getVoidTy(F.getContext()), {Int8PtrTy}, false);
                    log_malloc_func = Function::Create(FT, Function::ExternalLinkage, "clexma_log_malloc_result", F.getParent());
                }
            
                Value* malloc_result_arg = CI;
                Value* filename_arg = builder.CreateGlobalStringPtr(file_name);
                Value* line_arg = ConstantInt::get(Type::getInt32Ty(F.getContext()), line_num);
                Value* var_arg = builder.CreateGlobalStringPtr(var_name);
            
                std::vector<Value*> args;
                args.push_back(malloc_result_arg);
                args.push_back(filename_arg);
                args.push_back(line_arg);
                args.push_back(var_arg);
                builder.CreateCall(log_malloc_func, args);
                break;
            }
        }
    } else {
        errs() <<  "ERROR: createMallocMemlogStab for malloc function, instruction is not a malloc function call\n";
    }
}


void ClexmaPass::createStorelogStab(StoreInst*        SI,
                                    Function&          F, 
                                    BasicBlock&       BB,
                                    unsigned    line_num,
                                    StringRef  file_name) {
    Value* stored_ptr = SI->getPointerOperand();
    if(this->reg2Name.find(stored_ptr) != this->reg2Name.end()) {
        std::string var_name = this->reg2Name[stored_ptr];
        // begin stabbing
        for(auto itr = BB.begin(); itr != BB.end(); ++itr) {
            if(&*itr == SI) {
                IRBuilder<> builder(&BB, std::next(itr));
                Function* log_store_func = F.getParent()->getFunction("clexma_log_store_result");
                if(!log_store_func) {
                    errs() << "ERROR: store logging function not found\n"; 
                }

                Value* stored_ptr_arg = SI->getPointerOperand();
                Value* file_name_arg = builder.CreateGlobalStringPtr(file_name);
                Value* line_arg = ConstantInt::get(Type::getInt32Ty(F.getContext()), line_num);
                Value* var_arg = builder.CreateGlobalStringPtr(var_name);

                std::vector<Value*> args;
                args.push_back(stored_ptr_arg);
                args.push_back(file_name_arg);
                args.push_back(line_arg);
                args.push_back(var_arg);
                builder.CreateCall(log_store_func, args);
                break;
            }
        }
    } else {
        // stored position does not corresponds to a pointer variable in source
    }                                 
}


void ClexmaPass::createAllocalogStab(AllocaInst*        AI,
                                     Function&           F,
                                     BasicBlock&        BB,
                                     unsigned     line_num,
                                     StringRef   file_name) {
    llvm::Type* type = AI->getType();
    errs() << "createAllocalogStab: " << *type << "\n";
    std::string var_name = "";
    bool has_ptr_var_name = false;
    if(type->isPointerTy()) {
        if(this->reg2Name.find(AI) != this->reg2Name.end()) {
            var_name = this->reg2Name[AI];
            has_ptr_var_name = true;
        }
    }
    if(has_ptr_var_name) {
        // begin stabbing
        for(auto itr = BB.begin(); itr != BB.end(); ++itr) {
            if(&*itr == AI) {
                IRBuilder<> builder(&BB, std::next(itr));
                Function* log_alloca_func = F.getParent()->getFunction("clexma_log_alloca_result");
                if(!log_alloca_func) {
                    errs() << "ERROR: alloca logging function not found\n";
                }
                Value* var_arg = builder.CreateGlobalStringPtr(var_name);
                Value* file_name_arg = builder.CreateGlobalStringPtr(file_name);
                Value* line_arg = ConstantInt::get(Type::getInt32Ty(F.getContext()), line_num);
            
                std::vector<Value*> args;
                args.push_back(var_arg);
                args.push_back(file_name_arg);
                args.push_back(line_arg);
                builder.CreateCall(log_alloca_func, args);
                break;
            }
        }
    } else {
        // if the alloca variable is not a pointer variable we skip the stabbing process
    }
}

void ClexmaPass::createFreeMemlogStabs(CallInst* CI, 
                                       Function& F,
                                       BasicBlock& BB, 
                                       unsigned line_num, 
                                       StringRef file_name) {

    if(CI->getCalledFunction()->getName() == "free") {
        StringRef var_name;
        // obtain the value of freed ptr
        Value* freed_arg = CI->getArgOperand(0);
        // obtain name from reg2Name
        if(this->reg2Name.find(freed_arg) !=  this->reg2Name.end()) {
            var_name = this->reg2Name[freed_arg];
            errs() << "free_arg found: " << var_name << "\n";
        } else {
            var_name = "[no varname]";
            errs() << "Not direct source var name available\n";
        }

        // begin stabbing
        for(auto itr = BB.begin(); itr != BB.end(); ++itr) {
            if(&*itr == CI) {
                // insert the function call of clexma_log_before_free_result before free function
                errs() << "begin stabbing previous free\n";
                Value *freed_ptr_arg = freed_arg;
                Value *line_arg = ConstantInt::get(Type::getInt32Ty(F.getContext()), line_num);
                // building before
                IRBuilder<> before_builder(&BB, itr);
                Function* log_before_free_func = F.getParent()->getFunction("clexma_log_before_free_result");
                if(!log_before_free_func) {
                    errs() << "ERROR: cannot find clexma_log_before_free_result function\n";
                }
                Value* filename_arg_before = before_builder.CreateGlobalStringPtr(file_name);
                Value* variable_name_arg_before = before_builder.CreateGlobalStringPtr(var_name);
                std::vector<Value*> before_args;
                before_args.push_back(freed_ptr_arg);
                before_args.push_back(filename_arg_before);
                before_args.push_back(line_arg);
                before_args.push_back(variable_name_arg_before);
                before_builder.CreateCall(log_before_free_func, before_args);
                
                errs() << "begin stabbing after free\n";
                // insert the function call of clexma_log_after_free_result after free function
                IRBuilder<> after_builder(&BB, std::next(itr));
                Function* log_after_free_func = F.getParent()->getFunction("clexma_log_after_free_result");
                if(!log_after_free_func) {
                    errs() << "ERROR: cannot find clexma_log_after_free_result function" << "\n";
                }
                Value *filename_arg_after = after_builder.CreateGlobalStringPtr(file_name);
                Value *varible_name_arg_after = after_builder.CreateGlobalStringPtr(var_name);
            
                std::vector<Value*> after_args;
                after_args.push_back(freed_ptr_arg);
                after_args.push_back(filename_arg_after);
                after_args.push_back(line_arg);
                after_args.push_back(varible_name_arg_after);
                after_builder.CreateCall(log_after_free_func, after_args);
                break;
            }
        }
    } else {
        errs() << "ERROR: createFreeMemlogStabs for free function, instruction is not a free call\n";
    }
}

PreservedAnalyses ClexmaPass::run(Function& F,
                                  FunctionAnalysisManager &AM) {

    std::string passed_function_name = F.getName().str();
    if(this->is_stabbing_function_name(passed_function_name)) {
        return PreservedAnalyses::all();
    }
    this->collectNameInfo(F);
    errs() << "===== Function Name: " << passed_function_name<< "\n";
    for(auto &BB : F) {
        errs() << "\t----- BasicBlock Name: " << BB.getName() << "\n";
        
        for(auto &I : BB) {
            DILocation* debug_loc = I.getDebugLoc();
            unsigned line_num;
            StringRef file_name;
            StringRef var_name;
            if(debug_loc) {
                line_num = debug_loc->getLine();
                file_name = debug_loc->getFilename();
            }

            if(auto* BO = dyn_cast<BinaryOperator>(&I)) {
                errs() << "\t\t- Binary Operator: " << I << "\n";
            } else if(auto* CI = dyn_cast<CallInst>(&I)) {
                errs() << "\t\t- Call Instruction: " << I << "\n";
                if(auto *CalledFunc = CI->getCalledFunction()) {
                    if(CalledFunc->getName() == "malloc") {
                        this->createMallocMemlogStab(CI, F, BB, line_num, file_name);
                    } else if(CalledFunc->getName() == "free") {
                        this->createFreeMemlogStabs(CI, F, BB, line_num, file_name);
                    }
                }
            } else if(auto* LI = dyn_cast<LoadInst>(&I)) {
                errs() << "\t\t- Load Instruction: " << I << "\n";
            } else if(auto* SI = dyn_cast<StoreInst>(&I)) {
                errs() << "\t\t- Store Instruction: " << I << "\n";
                this->createStorelogStab(SI, F, BB, line_num, file_name);
            } else if(auto* AI = dyn_cast<AllocaInst>(&I)) {
                errs() << "\t\t- Alloca Instruction: " << I << "\n";
                this->createAllocalogStab(AI, F, BB, line_num, file_name);
            } 
            else {
                errs() << "\t\t- Unknown Instruction: " <<  I << "\n";
            }

        }
    }
    return PreservedAnalyses::all();
}

