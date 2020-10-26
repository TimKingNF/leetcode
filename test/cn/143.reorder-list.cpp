//
// Created by timking.nf@foxmail.com on 2020/10/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "143.reorder-list.h"

namespace LeetCode143 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode143Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode143Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode143::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode *head = construct_link_list<ListNode>(argument);
  solution->reorderList(head);
  ListNode *retHead = construct_link_list<ListNode>(ret);
  // link_list_print(head);
  // link_list_print(retHead);

  ASSERT_TRUE(link_list_cmp(head, retHead));
}

auto values = ::testing::Values(
  ParamType({1,2,3,4}, {1,4,2,3}),
  ParamType({1,2,3,4,5}, {1,5,2,4,3}),
  ParamType({1,2}, {1,2}),
  ParamType({1,2,3,4,5,6,7,8}, {1,8,2,7,3,6,4,5})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode143ParamTest, LeetCode143Test, values);

}