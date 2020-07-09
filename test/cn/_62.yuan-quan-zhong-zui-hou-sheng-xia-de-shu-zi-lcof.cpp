//
// Created by timking.nf@foxmail.com on 2020/6/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_62.yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof.h"

namespace LeetCode_62 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_62Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_62Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_62::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  int n, m;
  tie(n, m) = arguments;

  ASSERT_EQ(solution->lastRemaining(n, m), ret);
}

ArgumentType r1(5, 3);
ArgumentType r2(10, 17);

auto values = ::testing::Values(
  ParamType(r1, 3),
  ParamType(r2, 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_62ParamTest, LeetCode_62Test, values);

}