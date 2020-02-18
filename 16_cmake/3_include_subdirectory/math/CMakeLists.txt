aux_source_directory(. DIR_LIB_SRCS)

# 生成动态库
add_library(MathFunctions ${DIR_LIB_SRCS})