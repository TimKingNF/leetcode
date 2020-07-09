//
// Created by timking.nf@foxmail.com on 2020/5/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "66.plus-one.h"

namespace LeetCode66 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode66Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode66Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode66::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->plusOne(argument), ret);  // 断言结果
}

ArgumentType p1{1,2,3};
ArgumentType p2{4,3,2,1};
ArgumentType p3{9};

ResultType r1{1,2,4};
ResultType r2{4,3,2,2};
ResultType r3{1,0};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode66ParamTest, LeetCode66Test, values);

}