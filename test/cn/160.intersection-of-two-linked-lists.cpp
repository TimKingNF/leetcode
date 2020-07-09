//
// Created by timking.nf@foxmail.com on 2020/6/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "160.intersection-of-two-linked-lists.h"

namespace LeetCode160 {

typedef tuple<ListNode*, ListNode*, int, int> ArgumentType;
typedef ListNode* ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

ListNode* getNthNode(ListNode* head, int n) {
  while (head) {
    head = head->next;
    if (--n == 0) return head;
  }
  return nullptr;
}

void intersectionLinkList(ListNode* headA, ListNode* headB, int m, int n) {
  // 取到交点的前一个元素
  headA = getNthNode(headA, m-1);
  headB = getNthNode(headB, n-1);
  // 制作交点
  headB->next = headA->next;
}

void printLinkList(ListNode* head) {
  while (head) {
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
}

class LeetCode160Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode160Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode160::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  ListNode *headA, *headB;
  int skipA, skipB;
  tie(headA, headB, skipA, skipB) = arguments;

  if (skipA > 0 && skipB > 0)
    intersectionLinkList(headA, headB, skipA, skipB);  // 制作交点

  ASSERT_EQ(solution->getIntersectionNode(headA, headB), ret);  // 断言结果
}

vector<int> p1_0_0{4, 1, 8, 4, 5};
vector<int> p1_1_0{5, 0, 1, 8, 4, 5};
ListNode* p1_0 = construct_link_list<ListNode>(p1_0_0);
ListNode* p1_1 = construct_link_list<ListNode>(p1_1_0);
ArgumentType p1(p1_0, p1_1, 2, 3);
ResultType r1 = getNthNode(p1_0, 2);

vector<int> p2_0_0{1};
vector<int> p2_1_0{1};
ListNode* p2_0 = construct_link_list<ListNode>(p2_0_0);
ListNode* p2_1 = construct_link_list<ListNode>(p2_1_0);
ArgumentType p2(p2_0, p2_1, 0, 0);
ResultType r2 = getNthNode(p1_0, 0);

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode160ParamTest, LeetCode160Test, values);

}