//
// Created by timking.nf@foxmail.com on 2020/7/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_17_10.find-majority-element-lcci.h"

namespace LeetCode_17_10 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_17_10Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_17_10Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_17_10::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->majorityElement(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({1,2,5,9,5,9,5,5,5}, 5),
  ParamType({3,2}, -1),
  ParamType({2,2,1,1,1,2,2}, 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_17_10ParamTest, LeetCode_17_10Test, values);

}