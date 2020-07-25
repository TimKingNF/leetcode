//
// Created by timking.nf@foxmail.com on 2020/7/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "779.k-th-symbol-in-grammar.h"

namespace LeetCode779 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode779Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode779Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode779::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int N, K;
  tie(N, K) = arguments;

  ASSERT_DOUBLE_EQ(solution->kthGrammar(N, K), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType(1, 1), 0),
  ParamType(ArgumentType(2, 1), 0),
  ParamType(ArgumentType(2, 2), 1),
  ParamType(ArgumentType(4, 5), 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode779ParamTest, LeetCode779Test, values);

}