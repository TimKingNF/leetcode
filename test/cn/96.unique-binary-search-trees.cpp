//
// Created by timking.nf@foxmail.com on 2020/7/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "96.unique-binary-search-trees.h"

namespace LeetCode96 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode96Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode96Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode96::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->numTrees(argument), ret);
}

auto values = ::testing::Values(
  ParamType(3, 5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode96ParamTest, LeetCode96Test, values);

}