//
// Created by timking.nf@foxmail.com on 2021/2/6.
//

#ifndef LEETCODE_CIG_1_2017_HPP
#define LEETCODE_CIG_1_2017_HPP

#include "header.h"

namespace CIG_1_2017 {

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* removeValueNode(ListNode* head, int val) {
    ListNode *dummy = new ListNode(), *pre = dummy;
    dummy->next = head;
    while (head) {
      if (head->val != val) {
        pre->next = head;
        pre = head;
      }
      head = head->next;
    }
    return dummy->next;
  }
};

}

#endif  // LEETCODE_CIG_1_2017_HPP
