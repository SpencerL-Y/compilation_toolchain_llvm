cmake_minimum_required(VERSION 3.10)

project(target_project_template)

find_package(LLVM REQUIRED CONFIG)

# 设置编译优化为 O0
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# 设置编译为 LLVM 字节码文件
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -emit-llvm -c")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -emit-llvm -c")

message(STATUS "CFLAGS: ${CMAKE_C_FLAGS}")
message(STATUS "CXXFLAGS: ${CMAKE_CXX_FLAGS}")

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/includes)

# 查找所有源文件
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.c)
message(STATUS "SOURCES: ${SOURCES}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

# 为每个源文件生成对应的 .bc 文件
set(BC_FILES "")
foreach(SOURCE ${SOURCES})
    get_filename_component(SOURCE_NAME ${SOURCE} NAME_WE)
    set(BC_FILE ${CMAKE_BINARY_DIR}/${SOURCE_NAME}.bc)
    list(APPEND BC_FILES ${BC_FILE})

    add_custom_command(
        OUTPUT ${BC_FILE}
        COMMAND clang -emit-llvm -c ${SOURCE} -I ${PROJECT_SOURCE_DIR}/includes -o ${BC_FILE}
        COMMENT "Compiling ${SOURCE} to LLVM .bc file"
    )
endforeach()

# 定义 LLVM Pass 动态库路径
set(MY_PASS_SO_PATH "${CMAKE_SOURCE_DIR}/../pass_template/build/libMyPass.so")
message(STATUS "Path of libMyPass.so: ${MY_PASS_SO_PATH}")

# 自定义目标：为每个 .bc 文件运行 LLVM Pass
add_custom_target(
    run_opt_pass
    COMMAND ${CMAKE_COMMAND} -E echo "Running custom LLVM pass on .bc files"
    COMMENT "Running custom LLVM pass on .bc files"
)

# 为每个 .bc 文件执行 opt
foreach(BC_FILE ${BC_FILES})
    get_filename_component(BC_FILE_NAME ${BC_FILE} NAME_WE)
    add_custom_command(
        TARGET run_opt_pass
        POST_BUILD
        COMMAND opt --load-pass-plugin=${MY_PASS_SO_PATH} --passes=mypass ${BC_FILE} -o ${CMAKE_BINARY_DIR}/${BC_FILE_NAME}_passed.bc
        COMMENT "Running opt on ${BC_FILE} with my pass"
    )
endforeach()

# 自定义目标：链接处理后的 .bc 文件生成可执行文件
add_custom_target(
    my_program ALL
    COMMAND sh -c "clang ${CMAKE_BINARY_DIR}/*_passed.bc -o ${CMAKE_BINARY_DIR}/my_program"
    COMMENT "Linking .bc files into executable"
    DEPENDS run_opt_pass
)