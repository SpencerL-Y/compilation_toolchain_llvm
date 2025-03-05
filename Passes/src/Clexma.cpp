
#include "llvm/IR/Instructions.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/Transforms/Utils/Clexma.h"
#include "llvm/IR/DebugInfo.h"
#include "llvm/IR/DebugProgramInstruction.h"
#include "llvm/Support/Debug.h"     
#include "llvm/IR/LLVMContext.h"

using namespace llvm;


void ClexmaPass::collectNameInfo(Function& F) {
    for(auto& BB : F) {
        for(auto& I : BB) {

        }
    }
}


void ClexmaPass::collectNameInfo(Instruction& I){
    
}


StringRef ClexmaPass::getDbgDeclareNameFromInst(Instruction *II) {
    errs() << "\t\t\t!!! getDbgDeclareNameFromInst\n"; 
    for (DbgRecord &DR : II->getDbgRecordRange()) {
        if (auto *ValueRecord = dyn_cast<DbgVariableRecord>(&DR)) {
            DILocalVariable *LocalVar = ValueRecord->getVariable();
            if (LocalVar) {
                errs() << "Variable name: " << LocalVar->getName() << "\n";
                errs() << "Variable type: " << *LocalVar->getType() << "\n";
                errs() << "Variable scope: " << LocalVar->getScope()->getName() << "\n";
            }

            // 获取 DILocation
            if (DILocation *Loc = ValueRecord->getDebugLoc()) {
                errs() << "Debug location: " << Loc->getFilename() << ":" 
                       << Loc->getLine() << ":" << Loc->getColumn() << "\n";
            }
        }
    }
    return StringRef(); 
}

PreservedAnalyses ClexmaPass::run(Function& F,
                                  FunctionAnalysisManager &AM) {
    errs() << "===== Function Name: " << F.getName() << "\n";
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
                        // find the instruction that stores the malloced ptr value to the ptr variable in stack
                        
                        for(auto *iterI : CI->users()) {
                            if(auto* iterSI = dyn_cast<StoreInst>(iterI)) {
                                if(iterSI->getValueOperand() == CI) {
                                    // find the instruction that store the malloced ptr to the stack variable
                                    var_name = getDbgDeclareNameFromInst(iterSI);
                                }
                            }
                        }
                        
                        // insert log function call to the line after malloc
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
                    } else if(CalledFunc->getName() == "free") {
                        //TODO
                        // obtain the value of freed ptr
                        Value* freed_arg = CalledFunc->getOperand(0);
                        // insert the function call of clexma_log_before_free_result before free function

                        // insert the function call of clexma_log_after_free_result after free function
                        for(auto itr = BB.begin(); itr != BB.end(); ++itr) {
                            if(&*itr == CI) {
                                IRBuilder<> builder(&BB, std::next(itr));
                                Function* log_free_func = F.getParent()->getFunction("clexma_log_after_free_result");
                                if(!log_free_func) {
                                    errs() << "ERROR: cannot find clexma_log_free_result function" << "\n";
                                }
                                Value *filename_arg = builder.CreateGlobalStringPtr(file_name);
                                Value *line_arg = ConstantInt::get(Type::getInt32Ty(F.getContext()), line_num);
                                
                            }
                        }

                    }
                }
            } else if(auto* LI = dyn_cast<LoadInst>(&I)) {
                errs() << "\t\t- Load Instruction: " << I << "\n";
            } else if(auto* SI = dyn_cast<StoreInst>(&I)) {
                errs() << "\t\t- Store Instruction: " << I << "\n";
            } else if(auto* AI = dyn_cast<AllocaInst>(&I)) {
                errs() << "\t\t- Alloca Instruction: " << I << "\n";
            } 
            else {
                errs() << "\t\t- Unknown Instruction: " <<  I << "\n";
            }

        }
    }
    return PreservedAnalyses::all();
}

