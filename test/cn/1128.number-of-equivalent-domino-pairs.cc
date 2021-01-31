//
// Created by timking.nf@foxmail.com on 2021/1/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1128.number-of-equivalent-domino-pairs.h"

namespace LeetCode1128 {

typedef vector<vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1128Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1128Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1128::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->numEquivDominoPairs(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{1,2},{2,1},{3,4},{5,6}}, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1128ParamTest, LeetCode1128Test, values);

}