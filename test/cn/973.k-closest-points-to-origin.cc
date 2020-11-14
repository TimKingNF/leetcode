//
// Created by timking.nf@foxmail.com on 2020/11/9.
//

#include "gtest/gtest.h"
#include "header.h"
#include "973.k-closest-points-to-origin.h"

namespace LeetCode973 {

typedef tuple<vector<vector<int>>, int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode973Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode973Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode973::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<vector<int>> points;
  int K;
  tie(points, K) = arguments;

  ResultType asserted = solution->kClosest(points, K);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({{1,3}, {-2,2}}, 1), {{-2,2}}),
  ParamType(ArgumentType({{3,3}, {5,-1}, {-2,4}}, 2), {{3,3}, {-2,4}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode973ParamTest, LeetCode973Test, values);

}