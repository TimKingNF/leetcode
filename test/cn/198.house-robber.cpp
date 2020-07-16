//
// Created by timking.nf@foxmail.com on 2020/7/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "198.house-robber.h"

namespace LeetCode198 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode198Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode198Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode198::Solution();
  ArgumentType arguments;
  int ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->rob(arguments), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({1,2,3,1}, 4),
  ParamType({2,7,9,3,1}, 12),
  ParamType({2,1,1,2}, 4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode198ParamTest, LeetCode198Test, values);

}