//
// Created by timking.nf@foxmail.com on 2020/6/16.
//

// TODO：使用有限状态机的解法

#include "gtest/gtest.h"
#include "header.h"
#include "_56_II.shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof.h"

namespace LeetCode_56_II {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_56_IITest : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_56_IITest, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_56_II::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->singleNumber(argument), ret);
}

ArgumentType p1{3,4,3,3};
ArgumentType p2{9,1,7,9,7,9,7};

auto values = ::testing::Values(
  ParamType(p1, 4),
  ParamType(p2, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_56_IIParamTest, LeetCode_56_IITest, values);

}