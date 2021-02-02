//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#ifndef LEETCODE_CIG_1_2003_HPP
#define LEETCODE_CIG_1_2003_HPP

#include "header.h"

namespace CIG_1_2003 {

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head || n < 1) return nullptr;  // 无效参数

    ListNode *cur = head;
    while (cur) {
      cur = cur->next;
      --n;
    }
    if (n > 0) return head;  // 说明链表不够长, 没有倒数第 n 个节点
    if (n == 0) return head->next;  // 刚好就是头结点
    cur = head;
    while (++n != 0) {
      cur = cur->next;
    }
    // 此时 cur 就是要删除节点的前一个节点
    // 倒数第 n 个节点的前一个节点是正数 len-n 节点, 第一次遍历后 n = n - len < 0
    // 第二次遍历 ++n, 直到 n == 0, 此时会停在 len-n 节点
    ListNode *deleted = cur->next;
    if (deleted->next) {
      deleted->next->prev = cur;
    }
    cur->next = deleted->next;
    return head;
  }
};

};

#endif  // LEETCODE_CIG_1_2003_HPP