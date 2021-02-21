//
// Created by timking.nf@foxmail.com on 2021/2/4.
//

#ifndef LEETCODE_CIG_1_2011_HPP
#define LEETCODE_CIG_1_2011_HPP

#include "header.h"

namespace CIG_1_2011 {

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* listPartition(ListNode* head, int m) { return solution1(head, m); }

  ListNode* solution1(ListNode* head, int m) {
    if (!head) return nullptr;
    ListNode *leftDummy = new ListNode(), *left = leftDummy;
    ListNode *middleDummy = new ListNode(), *middle = middleDummy;
    ListNode *rightDummy = new ListNode(), *right = rightDummy;
    ListNode *next;
    while (head) {
      next = head->next;
      head->next = nullptr;  // 置空
      if (head->val < m) {
        left->next = head;
        left = left->next;
      } else if (head->val > m) {
        right->next = head;
        right = right->next;
      } else {
        middle->next = head;
        middle = middle->next;
      }
      head = next;
    }
    if (middleDummy->next) {
      left->next = middleDummy->next;
      middle->next = rightDummy->next;
    } else {
      left->next = rightDummy->next;
    }
    return leftDummy->next;
  }
};

}
#endif  // LEETCODE_CIG_1_2011_HPP
