cmake_minimum_required(VERSION 2.8)

project(3_include_subdirectory)

aux_source_directory(. DIR_SRCS)

add_subdirectory(math)


# 指定生成目标
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo MathFunctions)