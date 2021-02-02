//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#ifndef LEETCODE_CIG_1_2004_HPP
#define LEETCODE_CIG_1_2004_HPP

#include "header.h"

namespace CIG_1_2004 {

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
 public:
  ListNode* removeMidNode(ListNode* node) {
    if (!node || !node->next) return node;  // 单节点的情况
    if (!node->next->next) return node->next;  // 两个节点的情况

    ListNode *dummy = new ListNode();
    dummy->next = node;
    ListNode *slow = node, *pre = dummy;

    while (node && node->next) {
      node = node->next->next;
      pre = slow;
      slow = slow->next;
    }
    pre->next = slow->next;
    return dummy->next;
  }
};

};


#endif  // LEETCODE_CIG_1_2004_HPP
