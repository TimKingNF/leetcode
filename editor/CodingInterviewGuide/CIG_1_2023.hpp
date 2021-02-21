//
// Created by timking.nf@foxmail.com on 2021/2/7.
//

#ifndef LEETCODE_CIG_1_2023_HPP
#define LEETCODE_CIG_1_2023_HPP

#include "header.h"

namespace CIG_1_2023 {

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* relocate(ListNode* head) {
    if (!head || !head->next) return head;
    // 先找到中心点
    ListNode *fast = head, *slow = head, *pre;
    while (fast && fast->next) {
      fast = fast->next->next;
      pre = slow;
      slow = slow->next;
    }
    // 断开两段链表
    pre->next = nullptr;

    // 调整链表
    ListNode *left = head, *right = slow;
    while (left->next) {
      fast = right->next;
      right->next = left->next;
      left->next = right;
      left = right->next;
      right = fast;
    }
    left->next = right;
    return head;
  }
};

}

#endif  // LEETCODE_CIG_1_2023_HPP
