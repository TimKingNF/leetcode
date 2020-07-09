# 查找当前目录下的所有源文件, 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

add_executable(unit_tests ${DIR_LIB_SRCS})

target_link_libraries(unit_tests gtest_main EditorCN)
