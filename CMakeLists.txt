cmake_minimum_required(VERSION 3.15)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

# 添加 googletest
include(cmake/googletest.cmake)
fetch_googletest(
  ${PROJECT_SOURCE_DIR}/cmake
  ${PROJECT_BINARY_DIR}/googletest
)
enable_testing()

add_subdirectory(editor/base)
add_subdirectory(editor/cn)
add_subdirectory(test/cn)
add_subdirectory(editor/CodingInterviewGuide)
add_subdirectory(test/CodingInterviewGuide)
add_subdirectory(editor/usages)
add_subdirectory(test/usages)
