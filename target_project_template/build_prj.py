import os
import subprocess
import glob
import sys

# 设置项目的路径
PROJECT_DIR = os.path.dirname(os.path.abspath(__file__))
SOURCE_DIR = os.path.join(PROJECT_DIR, 'src')
BUILD_DIR = os.path.join(PROJECT_DIR, 'build')
INCLUDE_DIR = os.path.join(PROJECT_DIR, 'includes')

# 确保构建目录存在
os.makedirs(BUILD_DIR, exist_ok=True)

# 找到所有的源文件（.c 文件）
source_files = glob.glob(os.path.join(SOURCE_DIR, "**", "*.c"), recursive=True)

# 编译每个源文件为 LLVM 中间表示（.ll 文件）
def compile_to_ll(source_file):
    # 获取源文件的相对路径（相对于 SOURCE_DIR）
    relative_path = os.path.relpath(source_file, SOURCE_DIR)
    
    # 获取文件名（没有扩展名）
    source_name = os.path.splitext(os.path.basename(source_file))[0]
    
    # 构建在 BUILD_DIR 中的目标文件路径
    # old source compiling does not consider folders
    # source_name = os.path.basename(source_file)
    # ll_file = os.path.join(BUILD_DIR, f"{source_name}.ll")
    ll_file = os.path.join(BUILD_DIR, os.path.dirname(relative_path), f"{source_name}.ll")
    os.makedirs(os.path.dirname(ll_file), exist_ok=True)


    # clang 命令行编译源文件为 .ll 文件，加入包含路径
    clang_command = [
        "clang",  "-emit-llvm", "-O0", "-g3", "-I", INCLUDE_DIR, "-S", source_file, "-o", ll_file
    ]
    print(f"Running command: {' '.join(clang_command)}")
    subprocess.run(clang_command, check=True)
    return ll_file

# 运行 LLVM Pass
def run_opt_pass(input_ll_file):
    output_ll_file = input_ll_file.replace(".ll", "_passed.ll")
    
    # 确保 opt 指定输出文件
    opt_command = [
        "opt", "--passes=clexma", input_ll_file, "-o", output_ll_file
    ]
    print(f"Running command: {' '.join(opt_command)}")
    subprocess.run(opt_command, check=True)
    
    return output_ll_file

# 链接生成的 .ll 文件为可执行文件
def link_to_executable(ll_files):
    output_exe = os.path.join(BUILD_DIR, "my_program")
    
    clang_command = [
        "clang", "-o", output_exe, *ll_files
    ]
    print(f"Running command: {' '.join(clang_command)}")
    subprocess.run(clang_command, check=True)

# 主构建流程
def build():
    print("Building project...")

    # 步骤1：编译源文件为 .ll 文件
    ll_files = []
    for source_file in source_files:
        ll_file = compile_to_ll(source_file)
        ll_files.append(ll_file)

    # 步骤2：运行 LLVM Pass 处理每个 .ll 文件
    passed_ll_files = []
    for ll_file in ll_files:
        passed_ll_file = run_opt_pass(ll_file)
        passed_ll_files.append(passed_ll_file)

    # 步骤3：链接生成可执行文件
    link_to_executable(passed_ll_files)

def build_ll():
    print("Building ll files... ")
    ll_files = []
    for source_file in source_files:
        print("compiling source file: " + source_file)
        ll_file = compile_to_ll(source_file)
        ll_files.append(ll_file)
    

if __name__ == "__main__":
    # build()
    build_ll()