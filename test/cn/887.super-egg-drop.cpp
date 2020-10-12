//
// Created by timking.nf@foxmail.com on 2020/8/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "887.super-egg-drop.h"

namespace LeetCode887 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode887Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode887Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode887::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int K, N;
  tie(K, N) = arguments;

  ASSERT_EQ(solution->superEggDrop(K, N), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType(1, 2), 2),
  ParamType(ArgumentType(2, 6), 3),
  ParamType(ArgumentType(3, 14), 4)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode887ParamTest, LeetCode887Test, values);

}