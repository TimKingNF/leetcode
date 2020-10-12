//
// Created by timking.nf@foxmail.com on 2020/8/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_51.shu-zu-zhong-de-ni-xu-dui-lcof.h"

namespace LeetCode_51 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_51Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_51Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_51::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->reversePairs(argument), ret);
}

auto values = ::testing::Values(
  ParamType({7,5,6,4}, 5)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_51ParamTest, LeetCode_51Test, values);

}