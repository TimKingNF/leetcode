//
// Created by timking.nf@foxmail.com on 2020/6/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_61.bu-ke-pai-zhong-de-shun-zi-lcof.h"

namespace LeetCode_61 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_61Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_61Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_61::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isStraight(argument), ret);
}

ArgumentType r1{1,2,3,4,5};
ArgumentType r2{0,0,1,2,5};
ArgumentType r3{13,0,9,10,8};
ArgumentType r4{0,0,2,2,5};

auto values = ::testing::Values(
  ParamType(r1, true),
  ParamType(r2, true),
  ParamType(r3, false),
  ParamType(r4, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_61ParamTest, LeetCode_61Test, values);

}