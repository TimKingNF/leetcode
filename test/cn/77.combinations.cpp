//
// Created by timking.nf@foxmail.com on 2020/9/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "77.combinations.h"

namespace LeetCode77 {

typedef tuple<int, int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode77Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode77Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode77::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int n, k;
  tie(n, k) = arguments;

  ResultType asserted = solution->combine(n, k);
  // ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType(ArgumentType(4, 2), {{2,4}, {3,4}, {2,3}, {1,2}, {1,3}, {1,4}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode77ParamTest, LeetCode77Test, values);

}