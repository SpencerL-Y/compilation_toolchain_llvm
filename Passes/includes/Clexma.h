#ifndef LLVM_TRANSFORMS_UTILS_CLEXMA_H
#define LLVM_TRANSFORMS_UTILS_CLEXMA_H

#include "llvm/IR/PassManager.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"



namespace llvm
{
    class ClexmaPass : public PassInfoMixin<ClexmaPass> {
        public:
        PreservedAnalyses run(Function& F, FunctionAnalysisManager& FA);
        private:


        void createFreeMemlogStabs(CallInst*     CI, 
                                   Function&     F,
                                   BasicBlock&   BB, 
                                   unsigned      line_num, 
                                   StringRef     file_name);
        
        void createMallocMemlogStab(CallInst*    CI,
                                    Function&    F,
                                    BasicBlock&  BB,
                                    unsigned     line_num,
                                    StringRef    file_name);
                                
        // function to construct table 
        void collectNameInfo(Function& F);
        void collectNameInfo(Instruction& I);
        // register 2 source name table
        DenseMap<Value*, std::string> reg2Name;

    };

    
} // namespace llvm


#endif