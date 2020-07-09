//
// Created by timking.nf@foxmail.com on 2020/5/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "674.longest-continuous-increasing-subsequence.h"

namespace LeetCode674 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode674Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode674Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode674::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->findLengthOfLCIS(argument), ret);  // 断言结果
}

ArgumentType p1{1,3,5,4,7};
ArgumentType p2{2,2,2,2,2};

auto values = ::testing::Values(
  ParamType(p1, 3),
  ParamType(p2, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode674ParamTest, LeetCode674Test, values);

}
