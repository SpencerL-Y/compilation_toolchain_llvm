cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(ClexmaLLVM)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)

# 设置 LLVM 路径（根据你的安装路径修改）
find_package(LLVM REQUIRED CONFIG)

# 设置 CMake 的 LLVM 库路径
list(APPEND CMAKE_PREFIX_PATH "${LLVM_DIR}")

# 设置共享库
set(CMAKE_BUILD_TYPE Release)

# 添加头文件目录
include_directories(includes ${LLVM_INCLUDE_DIRS})

# 将 LLVM 库链接到项目
link_directories(${LLVM_LIBRARY_DIRS})

# 设置源文件
set(SOURCES src/Clexma.cpp)

# 生成共享库 (.so 文件)
add_library(ClexmaPass MODULE ${SOURCES})

# 链接 LLVM 库
target_link_libraries(ClexmaPass PRIVATE ${LLVM_LIBRARIES})

# 如果你有其他依赖的库，可以在这里链接
# target_link_libraries(ClexmaPass PRIVATE some_other_library)