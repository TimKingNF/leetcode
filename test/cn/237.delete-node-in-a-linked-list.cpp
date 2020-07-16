//
// Created by timking.nf@foxmail.com on 2020/7/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "237.delete-node-in-a-linked-list.h"

namespace LeetCode237 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

ListNode* find_node(ListNode* head, int val) {
  while (head) {
    if (head->val == val) return head;
    head = head->next;
  }
  return nullptr;
}

class LeetCode237Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode237Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode237::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> inputs;
  int del_node_val;
  tie(inputs, del_node_val) = arguments;
  ListNode* head = construct_link_list<ListNode, int>(inputs);
  ListNode* del_node = find_node(head, del_node_val);
  solution->deleteNode(del_node);

  ListNode* ret_link_list = construct_link_list<ListNode, int>(ret);
  ASSERT_TRUE(link_list_cmp(head, ret_link_list));  // 因为值都是唯一，只比较值是否一样即可
}

auto values = ::testing::Values(
  ParamType(ArgumentType({4,5,1,9}, 5), {4,1,9}),
  ParamType(ArgumentType({4,5,1,9}, 1), {4,5,9})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode237ParamTest, LeetCode237Test, values);

}