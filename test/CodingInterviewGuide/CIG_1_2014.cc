//
// Created by timking.nf@foxmail.com on 2021/2/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2014.hpp"

namespace CIG_1_2014 {

// 第一个参数用于构造链表 headA, 第四个参数用于构造链表 headB
// 第二和第五个参数指定 headA 第几个节点和 headB 第几个节点相交，如果为 -1，说明不相交
// 第三和第六个参数指定 headA 和 headB 中是否有环，如果有环，则尾节点指向此节点，为 -1 说明无环
typedef tuple<vector<int>, int, int, vector<int>, int, int> ArgumentType;
// 参数表示取 headA 还是 headB ( 第一个参数，-1 说明没有结果 ) 的第几个节点 （ 第二个参数 ）
typedef tuple<int, int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

ListNode* getNthNode(ListNode* head, int n) {
  if (n == 0) return head;
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

void linkCycle(ListNode* head, int cycle) {
  ListNode *cur = head;
  while (cur && cur->next) cur = cur->next;
  // 连接成环
  cur->next = getNthNode(head, cycle);
}

class CIG_1_2014Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2014Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2014::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> argsA, argsB;
  int skipA, skipB;
  int cycleA, cycleB;  // 必须大于0，等于0 说明起点就是环入口，就无法找到环入口节点
  tie(argsA, skipA, cycleA, argsB, skipB, cycleB) = arguments;

  ListNode *headA = construct_link_list<ListNode>(argsA);  // 先构造单向链表
  ListNode *headB = construct_link_list<ListNode>(argsB);
  if (skipA > 0 && skipB > 0)
    intersectionLinkList(headA, headB, skipA, skipB);  // 制作交点
  if (cycleA > 0)
    linkCycle(headA, cycleA);
  // 只有两个链表不存在交点时，制作 headB 的环才有效
  // 否则如果存在交点且 headA 有环，则 headB 也必有环
  if ((skipA < 0 || skipB < 0) && cycleB > 0)
    linkCycle(headB, cycleB);

  int resultHead, resultNth;
  tie(resultHead, resultNth) = ret;
  ListNode *assertHead = resultHead < 0 ? nullptr : (resultHead == 0 ? headA : headB);
  ListNode *assertNode = getNthNode(assertHead, resultNth);

  ASSERT_EQ(solution->getIntersectionNode(headA, headB), assertNode);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({4,1,8,4,5}, 2, -1, {5,0,1,8,4,5}, 3, -1), {0, 2}),
  ParamType(ArgumentType({2,6,4}, -1, 1, {1, 5, 10}, -1, 1), {-1, -1}),
  ParamType(ArgumentType({4,1,8,6,5,2,10}, 3, 1, {0,6}, 1, -1), {1, 1})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2014ParamTest, CIG_1_2014Test, values);

}