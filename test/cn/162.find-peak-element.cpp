//
// Created by timking.nf@foxmail.com on 2020/7/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "162.find-peak-element.h"

namespace LeetCode162 {

typedef vector<int> ArgumentType;
typedef set<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode162Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode162Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode162::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_TRUE(ret.count(solution->findPeakElement(argument)));  // 可以有多个结果
}

auto values = ::testing::Values(
  ParamType({1,2,3,1}, {2}),
  ParamType({1,2,1,3,5,6,4}, {1,5}),
  ParamType({1,2,3,4,5,6}, {5}),
  ParamType({2,3,4,3,2,1}, {2})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode162ParamTest, LeetCode162Test, values);

}