//
// Created by timking.nf@foxmail.com on 2020/7/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "142.linked-list-cycle-ii.h"

namespace LeetCode142 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

ListNode* getNthNode(ListNode* head, int n) {
  if (n < 0) return nullptr;
  while (n-- > 0) {
    head = head->next;
  }
  return head;
}

class LeetCode142Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode142Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode142::Solution();
  ArgumentType arguments = GetParam();
  // ResultType ret;
  // tie(arguments, ret) = GetParam();

  vector<int> inputs;
  int n;
  tie(inputs, n) = arguments;
  ListNode* head = construct_link_list<ListNode, int>(inputs);
  ListNode* tail = getNthNode(head, inputs.size()-1);
  ListNode* cycleEnterNode = getNthNode(head, n);
  tail->next = cycleEnterNode;  // 构造环

  ASSERT_EQ(solution->detectCycle(head), cycleEnterNode);
  // link_list_print<ListNode>(head);
}

auto values = ::testing::Values(
  ArgumentType({3,2,0,-4}, 1),
  ArgumentType({1,2}, 0),
  ArgumentType({1}, -1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode142ParamTest, LeetCode142Test, values);

}