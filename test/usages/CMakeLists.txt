# 查找当前目录下的所有源文件, 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 指定 include 目录
include_directories(
  ../../editor/base
  /usr/local/opt/openssl/include
  ../../editor/usages
)

# 指定链接目录
link_directories(
  /usr/local/opt/openssl/lib
)

add_executable(unit_tests_usages ${DIR_LIB_SRCS})

target_link_libraries(unit_tests_usages gtest_main baseLib EditorUsages ssl crypto)