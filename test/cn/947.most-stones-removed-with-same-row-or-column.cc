//
// Created by timking.nf@foxmail.com on 2021/1/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "947.most-stones-removed-with-same-row-or-column.h"

namespace LeetCode947 {

typedef vector<vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode947Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode947Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode947::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->removeStones(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}}, 5),
  ParamType({{0,0},{0,2},{1,1},{2,0},{2,2}}, 3),
  ParamType({{0,0}}, 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode947ParamTest, LeetCode947Test, values);

}