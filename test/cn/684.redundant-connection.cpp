//
// Created by timking.nf@foxmail.com on 2020/9/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "684.redundant-connection.h"

namespace LeetCode684 {

typedef vector<vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode684Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode684Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode684::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->findRedundantConnection(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{1,2}, {1,3}, {2,3}}, {2,3}),
  ParamType({{1,2}, {2,3}, {3,4}, {1,4}, {1,5}}, {1,4})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode684ParamTest, LeetCode684Test, values);

}