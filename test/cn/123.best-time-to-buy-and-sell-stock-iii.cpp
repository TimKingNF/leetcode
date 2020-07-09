//
// Created by timking.nf@foxmail.com on 2020/5/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "123.best-time-to-buy-and-sell-stock-iii.h"

namespace LeetCode123 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode123Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode123Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode123::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->maxProfit(argument), ret);  // 断言结果
}

ArgumentType p1{3,3,5,0,0,3,1,4};
ArgumentType p2{1,2,3,4,5};
ArgumentType p3{7,6,4,3,1};
ArgumentType p4{2,1,2,0,1};

ResultType r1 = 6;
ResultType r2 = 4;
ResultType r3 = 0;
ResultType r4 = 2;

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3),
  ParamType(p4, r4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode123ParamTest, LeetCode123Test, values);

}
