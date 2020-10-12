//
// Created by timking.nf@foxmail.com on 2020/8/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "416.partition-equal-subset-sum.h"

namespace LeetCode416 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode416Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode416Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode416::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->canPartition(arguments), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({1,5,11,5}, true),
  ParamType({1,2,3,5}, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode416ParamTest, LeetCode416Test, values);

}