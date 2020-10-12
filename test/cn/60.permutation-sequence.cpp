//
// Created by timking.nf@foxmail.com on 2020/9/5.
//

#include "gtest/gtest.h"
#include "header.h"
#include "60.permutation-sequence.h"

namespace LeetCode60 {

typedef tuple<int, int> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode60Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode60Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode60::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int n, k;
  tie(n, k) = arguments;
  ASSERT_EQ(solution->getPermutation(n, k), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType(3, 3), "213"),
  ParamType(ArgumentType(4, 9), "2314")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode60ParamTest, LeetCode60Test, values);

}