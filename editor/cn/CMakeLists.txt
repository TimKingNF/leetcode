# 查找当前目录下的所有源文件, 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

#message(STATUS "${DIR_LIB_SRCS}")

# 生成链接库
add_library(EditorCN ${DIR_LIB_SRCS})

# 将 EditorCN 暴露出去
target_include_directories(
  EditorCN
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
