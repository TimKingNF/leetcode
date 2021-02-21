//
// Created by timking.nf@foxmail.com on 2021/2/3.
//

#ifndef LEETCODE_CIG_1_2007_HPP
#define LEETCODE_CIG_1_2007_HPP

#include "header.h"

namespace CIG_1_2007 {

struct ListNode {
  int val;
  ListNode *prev;
  ListNode *next;
  ListNode() : val(0), prev(nullptr), next(nullptr) {}
  ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
  ListNode(int x, ListNode *prev, ListNode *next) : val(x), prev(prev), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;
    ListNode *pre = nullptr, *next;
    while (head) {
      next = head->next;
      head->prev = next;  // 修改前指向
      head->next = pre;  // 修改后指向
      pre = head;
      head = next;
    }
    return pre;
  }
};

};

#endif  // LEETCODE_CIG_1_2007_HPP
