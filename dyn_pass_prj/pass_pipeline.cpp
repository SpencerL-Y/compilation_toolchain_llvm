#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Bitcode/BitcodeReader.h"
#include "llvm/Transforms/Utils/Clexma.h"

#include <stdlib.h>
#include <memory>

using namespace llvm;
int main(int argc, char** argv) {
    if (argc != 3) {
      errs() << "Usage: <program> <input_IR_file> <output_IR_file>\n";
      return 1;
    }

    LLVMContext Context;
    SMDiagnostic Err;
    std::unique_ptr<Module> M = parseIRFile(argv[1], Err, Context);
    if(!M) {
        Err.print("Error reading IR", errs());
        return 1;
    }
    // Create the analysis managers.
    // These must be declared in this order so that they are destroyed in the
    // correct order due to inter-analysis-manager references.
    LoopAnalysisManager LAM;
    FunctionAnalysisManager FAM;
    CGSCCAnalysisManager CGAM;
    ModuleAnalysisManager MAM;

    // Create the new pass manager builder.
    // Take a look at the PassBuilder constructor parameters for more
    // customization, e.g. specifying a TargetMachine or various debugging
    // options.
    PassBuilder PB;

    // Register all the basic analyses with the managers.
    PB.registerModuleAnalyses(MAM);
    PB.registerCGSCCAnalyses(CGAM);
    PB.registerFunctionAnalyses(FAM);
    PB.registerLoopAnalyses(LAM);
    PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);

    ModulePassManager MPM = PB.buildPerModuleDefaultPipeline(OptimizationLevel::O0);
    FunctionPassManager FPM;
    FPM.addPass(ClexmaPass());

    MPM.addPass(createModuleToFunctionPassAdaptor(std::move(FPM)));

    MPM.run(*M, MAM);

    // 将优化后的 IR 输出到文件
    std::error_code EC;
    raw_fd_ostream output(argv[2], EC);
    if (EC) {
        errs() << "Error opening output file: " << EC.message() << "\n";
        return 1;
    }
    M->print(output, nullptr);
  
    return 0;
    
}