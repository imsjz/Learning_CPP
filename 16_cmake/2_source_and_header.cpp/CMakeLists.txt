cmake_minimum_required(VERSION 2.8)

project(2_source_and_header)


# 下面这样子做不好，如果.cpp文件多的话，繁杂
# add_executable(Demo main.cpp fun.cpp)

# 使用命令找当前目录的所有 源 文件
aux_source_directory(. DIR_SRCS)

add_executable(Demo ${DIR_SRCS})