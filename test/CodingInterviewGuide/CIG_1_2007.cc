//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2007.hpp"

namespace CIG_1_2007 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

// 验证是否有效的双向链表
bool validDoubleLinkedList(ListNode* head) {
  if (!head) return true;
  if (head->prev) return false;
  ListNode *pre = new ListNode(), *origHead = head;
  pre->next = head;
  head->prev = pre;
  while (head) {
    if (head->prev != pre) return false;
    if (pre->next != head) return false;
    pre = head;
    head = head->next;
  }
  origHead->prev = nullptr;  // 恢复原状
  return true;
}

class CIG_1_2007_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2007_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2007::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ListNode* head = construct_double_link_list<ListNode>(argument);
  ListNode* result = construct_double_link_list<ListNode>(ret);
  ASSERT_TRUE(validDoubleLinkedList(head));
  ASSERT_TRUE(validDoubleLinkedList(result));

  ListNode* asserted = solution->reverseList(head);
  ASSERT_TRUE(link_list_cmp(asserted, result));
}

auto values = ::testing::Values(
  ParamType({1,2,3,4,5}, {5,4,3,2,1}),
  ParamType({1}, {1}),
  ParamType({}, {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2007_ParamTest, CIG_1_2007_Test, values);

}