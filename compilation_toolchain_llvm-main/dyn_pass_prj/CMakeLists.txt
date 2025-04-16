cmake_minimum_required(VERSION 3.10)
project(MyPass)

find_package(LLVM REQUIRED CONFIG)

# 添加源代码文件
add_executable(main_pass pass_pipeline.cpp)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 链接 LLVM 库
target_link_libraries(main_pass PRIVATE LLVMCore LLVMSupport LLVMTarget LLVMPasses)

# 添加 LLVM 头文件路径
include_directories(${LLVM_INCLUDE_DIRS})
