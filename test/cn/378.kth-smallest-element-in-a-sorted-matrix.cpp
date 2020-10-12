//
// Created by timking.nf@foxmail.com on 2020/9/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "378.kth-smallest-element-in-a-sorted-matrix.h"

namespace LeetCode378 {

typedef tuple<vector<vector<int>>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode378Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode378Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode378::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<vector<int>> matrix;
  int k;
  tie(matrix, k) = arguments;

  ASSERT_EQ(solution->kthSmallest(matrix, k), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({{1,5,9}, {10, 11, 13}, {12, 13, 15}}, 8), 13)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode378ParamTest, LeetCode378Test, values);

}