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
        StringRef getDbgDeclareNameFromInst(Instruction *SI);

        // function to construct table 
        void collectNameInfo(Function& F);
        void collectNameInfo(Instruction& I);
        

        // register 2 source name table
        DenseMap<Value*, StringRef> reg2Name;

    };

    
} // namespace llvm


#endif