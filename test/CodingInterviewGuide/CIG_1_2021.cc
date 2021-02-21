//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2021.hpp"

namespace CIG_1_2021 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

ListNode* getNthNode(ListNode* head, int n) {
  if (n < 0) return nullptr;
  while (n-- > 0) {
    head = head->next;
  }
  return head;
}

bool link_list_cmp(ListNode* cyclingHead, ListNode* second) {
  ListNode *first = cyclingHead;
  while (first != nullptr && second != nullptr) {
    if (first->val != second->val) return false;
    first = first->next;
    second = second->next;
  }
  // 因为其中一个是环状链表
  return first == cyclingHead && !second;
}

class CIG_1_2021_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2021_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2021::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> args;
  int num;
  tie(args, num) = arguments;

  ListNode* head = construct_link_list<ListNode>(args);
  if (head) {  // 不为空节点时
    auto tail = getNthNode(head, args.size() - 1);  // 获取链表最后一个节点
    tail->next = head;  // 构成为环
  }

  ListNode* result = construct_link_list<ListNode>(ret);
  ListNode* asserted = solution->insertCyclingLinkList(head, num);
  // link_list_print(asserted);
  ASSERT_TRUE(link_list_cmp(asserted, result));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,3,4}, 5), {1,3,4,5}),
  ParamType(ArgumentType({}, 1), {1}),
  ParamType(ArgumentType({1,3,4}, 0), {0,1,3,4})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2021_ParamTest, CIG_1_2021_Test, values);

}