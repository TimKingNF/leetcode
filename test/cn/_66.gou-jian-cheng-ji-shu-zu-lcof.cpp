//
// Created by timking.nf@foxmail.com on 2020/6/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_66.gou-jian-cheng-ji-shu-zu-lcof.h"

namespace LeetCode_66 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_66Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_66Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_66::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->constructArr(argument), ret);  // 断言结果
}

ArgumentType p1{1,2,3,4,5};
ResultType r1{120,60,40,30,24};

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_66ParamTest, LeetCode_66Test, values);

}