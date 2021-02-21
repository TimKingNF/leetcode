// 本题和 ../cn/160.intersection-of-two-linked-lists.h 相比需要考虑的情况更多
// 链表中有环无环是不确定的, 返回链表中第一个相交的节点，如果有多个结果，则返回离其头最近节点
//
// Created by timking.nf@foxmail.com on 2021/2/4.
//

#ifndef LEETCODE_CIG_1_2014_HPP
#define LEETCODE_CIG_1_2014_HPP

#include "header.h"

namespace CIG_1_2014 {

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;
    auto loopA = getLoopNode(headA);
    auto loopB = getLoopNode(headB);
    // if (loopA) cout << loopA->val << endl;
    // if (loopB) cout << loopB->val << endl;
    if (loopA && loopB) {  // 说明 两个链表都有环
      return bothLoop(headA, loopA, headB, loopB);
    }
    if (!loopA && !loopB) {  // 说明链表中无环
      return noLoop(headA, headB);
    }
    return nullptr;  // 如果一个有环，一个无环，说明必不相交
  }

  // 如果链表中有环，则返回环节点
  ListNode* getLoopNode(ListNode* head) {
    if (!head) return nullptr;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) break;
    }
    if (!fast || !fast->next) return nullptr;  // 说明无环
    fast = head;
    while (fast != slow) {
      slow = slow->next;
      fast = fast->next;
    }
    return fast;  // 最后相遇的点即为环入口
  }

  // 两个链表中无环，判断并返回相交节点
  ListNode* noLoop(ListNode* headA, ListNode* headB) {
    auto a = headA, b = headB;
    while (a != b) {
      if (a) a = a->next;
      else a = headB;
      if (b) b = b->next;
      else b = headA;
    }
    return a;
  }

  // 链表中有环，一共三种情况
  // 1. 两个链表是同一个环，且在环外就有交点
  // 2. 两个链表环并不相交
  // 3. 两个链表是同一个环，且各自在环上有一个 环入口点
  ListNode *bothLoop(ListNode *headA, ListNode *loopA, ListNode *headB, ListNode *loopB) {
    auto a = headA, b = headB;
    if (loopA == loopB) {  // 说明在环外就有交点, 通过类似 noLoop 的方式即可计算出来
      while (a != b) {
        if (a != loopA) a = a->next;
        else a = headB;
        if (b != loopA) b = b->next;
        else b = headA;
      }
      return a;  // 相交节点
    } else {
      // 分情况讨论 链表环是否相交
      a = loopA->next;
      while (a != loopA) {  // 在遍历 环A 时，是否能找到 loopB
        if (a == loopB) {  // 说明环相交
          // 需要返回离头最近的节点
          int cntA = 0, cntB = 0;
          a = headA;
          while (a != loopA) {
            ++cntA;
            a = a->next;
          }
          b = headB;
          while (b != loopB) {
            ++cntB;
            b = b->next;
          }
          return cntA < cntB ? loopA : loopB;
        }
        a = a->next;
      }
      return nullptr;  // 遍历环A ，说明环不相交
    }
  }
};

}
#endif  // LEETCODE_CIG_1_2014_HPP
