//
// Created by timking.nf@foxmail.com on 2021/2/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1004.max-consecutive-ones-iii.h"

namespace LeetCode1004 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1004Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1004Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1004::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> A;
  int K;
  tie(A, K) = arguments;

  ASSERT_EQ(solution->longestOnes(A, K), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,1,1,0,0,0,1,1,1,1,0}, 2), 6),
  ParamType(ArgumentType({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3), 10),
  ParamType(ArgumentType({0,0,1,1,1,0,0}, 0), 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1004ParamTest, LeetCode1004Test, values);

}