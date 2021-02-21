//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2005.hpp"

namespace CIG_1_2005 {

typedef tuple<vector<int>, int, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_2005_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2005_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2005::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> args;
  int a, b;
  tie(args, a, b) = arguments;

  ListNode* head = construct_link_list<ListNode>(args);
  ListNode* result = construct_link_list<ListNode>(ret);
  ListNode* asserted = solution->removeRatioNode(head, a, b);
  ASSERT_TRUE(link_list_cmp(asserted, result));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,4,5}, 3, 5), {1,2,4,5}),
  ParamType(ArgumentType({1,2,3,4,5,6}, 2, 3), {1,2,3,5,6}),
  ParamType(ArgumentType({1,2}, 10, 5), {1,2}),
  ParamType(ArgumentType({1}, 0, 1), {1})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2005_ParamTest, CIG_1_2005_Test, values);

}