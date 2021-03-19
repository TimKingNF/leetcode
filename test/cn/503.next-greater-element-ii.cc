//
// Created by timking.nf@foxmail.com on 2021/3/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "503.next-greater-element-ii.h"

namespace LeetCode503 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode503Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode503Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode503::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->nextGreaterElements(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({1,2,1}, {2,-1,2}),
  ParamType({1,2,3,4,5}, {2,3,4,5,-1}),
  ParamType({1}, {-1}),
  ParamType({1,1,1,1,1}, {-1,-1,-1,-1,-1}),
  ParamType({5,4,3,2,1}, {-1,5,5,5,5}),
  ParamType({1,2,3,2,1}, {2,3,-1,3,2})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode503ParamTest, LeetCode503Test, values);

}