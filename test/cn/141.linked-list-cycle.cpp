//
// Created by timking.nf@foxmail.com on 2020/7/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "141.linked-list-cycle.h"

namespace LeetCode141 {

typedef tuple<vector<int>, int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

ListNode* getNthNode(ListNode* head, int n) {
  if (n < 0) return nullptr;
  while (n-- > 0) {
    head = head->next; 
  } 
  return head;
}

class LeetCode141Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode141Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode141::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> inputs;
  int n;
  tie(inputs, n) = arguments;
  ListNode* head = construct_link_list<ListNode, int>(inputs);
  ListNode* tail = getNthNode(head, inputs.size()-1);
  ListNode* cycleEnterNode = getNthNode(head, n);
  tail->next = cycleEnterNode;  // 构造环

  ASSERT_EQ(solution->hasCycle(head), ret);
  // link_list_print<ListNode>(head);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({3,2,0,-4}, 1), true),
  ParamType(ArgumentType({1,2}, 0), true),
  ParamType(ArgumentType({1}, -1), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode141ParamTest, LeetCode141Test, values);

}