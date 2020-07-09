//
// Created by timking.nf@foxmail.com on 2020/5/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "169.majority-element.h"

namespace LeetCode169 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode169Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode169Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode169::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->majorityElement(argument), ret);  // 断言结果
}

ArgumentType p1{3,2,3};
ArgumentType p2{2,2,1,1,1,2,2};

ResultType r1 = 3;
ResultType r2 = 2;

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode169ParamTest, LeetCode169Test, values);

}
