//
// Created by timking.nf@foxmail.com on 2020/8/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "300.longest-increasing-subsequence.h"

namespace LeetCode300 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode300Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode300Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode300::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->lengthOfLIS(argument), ret);
}

auto values = ::testing::Values(
  ParamType({10,9,2,5,3,7,101,18},4)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode300ParamTest, LeetCode300Test, values);

}