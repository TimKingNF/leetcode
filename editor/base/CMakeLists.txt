# 查找当前目录下的所有源文件, 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成可执行文件
add_executable(EditorBase ${DIR_LIB_SRCS})

# 生成动态库
add_library(baseLib SHARED ${DIR_LIB_SRCS})
target_link_libraries(EditorBase baseLib)