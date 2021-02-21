//
// Created by timking.nf@foxmail.com on 2021/2/9.
//

#include "gtest/gtest.h"
#include "header.h"
#include "992.subarrays-with-k-different-integers.h"

namespace LeetCode992 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode992Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode992Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode992::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> A;
  int K;
  tie(A, K) = arguments;

  ASSERT_EQ(solution->subarraysWithKDistinct(A, K), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,1,2,3}, 2), 7),
  ParamType(ArgumentType({1,2,1,3,4}, 3), 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode992ParamTest, LeetCode992Test, values);

}