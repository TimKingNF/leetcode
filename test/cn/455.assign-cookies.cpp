//
// Created by timking.nf@foxmail.com on 2020/7/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "455.assign-cookies.h"

namespace LeetCode455 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode455Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode455Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode455::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> g, s;
  tie(g, s) = arguments;

  ASSERT_EQ(solution->findContentChildren(g, s), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3}, {1,1}), 1),
  ParamType(ArgumentType({1,2}, {1,2,3}), 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode455ParamTest, LeetCode455Test, values);

}