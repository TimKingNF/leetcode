//
// Created by timking.nf@foxmail.com on 2020/12/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "659.split-array-into-consecutive-subsequences.h"

namespace LeetCode659 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode659Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode659Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode659::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isPossible(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({1,2,3,3,4,5}, true),
  ParamType({1,2,3,3,4,4,5,5}, true),
  ParamType({1,2,3,4,4,5}, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode659ParamTest, LeetCode659Test, values);

}