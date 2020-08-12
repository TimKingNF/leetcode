//
// Created by timking.nf@foxmail.com on 2020/8/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "75.sort-colors.h"

namespace LeetCode75 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode75Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode75Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode75::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  solution->sortColors(argument);
  ASSERT_EQ(argument, ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({2,0,2,1,1,0}, {0,0,1,1,2,2})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode75ParamTest, LeetCode75Test, values);

}