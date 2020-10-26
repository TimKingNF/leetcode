//
// Created by timking.nf@foxmail.com on 2020/10/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "763.partition-labels.h"

namespace LeetCode763 {

typedef string ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode763Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode763Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode763::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->partitionLabels(argument), ret);
}

auto values = ::testing::Values(
  ParamType("ababcbacadefegdehijhklij", {9,7,8})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode763ParamTest, LeetCode763Test, values);

}