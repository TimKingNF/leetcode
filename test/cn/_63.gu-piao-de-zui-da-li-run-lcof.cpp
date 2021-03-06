//
// Created by timking.nf@foxmail.com on 2020/6/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_63.gu-piao-de-zui-da-li-run-lcof.h"

namespace LeetCode_63 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_63Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_63Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_63::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->maxProfit(argument), ret);  // 断言结果
}

ArgumentType p1{7,1,5,3,6,4};
ArgumentType p2{7,6,4,3,1};

ResultType r1 = 5;
ResultType r2 = 0;

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_63ParamTest, LeetCode_63Test, values);

}