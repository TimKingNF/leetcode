//
// Created by timking.nf@foxmail.com on 2020/7/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "203.remove-linked-list-elements.h"

namespace LeetCode203 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode203Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode203Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode203::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> args;
  int val;
  tie(args, val) = arguments;
  ListNode* head = construct_link_list<ListNode, int>(args);
  ListNode* asserted = solution->removeElements(head, val);
  ListNode* resultHead = construct_link_list<ListNode, int>(ret);

  ASSERT_TRUE(link_list_cmp(asserted, resultHead));  // 断言结果

}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,6,3,4,5,6}, 6), {1,2,3,4,5}),
  ParamType(ArgumentType({1,2,3}, 1), {2, 3}),
  ParamType(ArgumentType({1,1,1}, 1), {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode203ParamTest, LeetCode203Test, values);

}