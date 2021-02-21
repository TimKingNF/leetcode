//
// Created by timking.nf@foxmail.com on 2021/2/3.
//

#ifndef LEETCODE_CIG_1_2009_HPP
#define LEETCODE_CIG_1_2009_HPP

#include "header.h"

namespace CIG_1_2009 {

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
  ListNode* josephusKill(ListNode* head, int m) {
    return solution2(head, m);
  }

  // 普通解法 O( n*m )  n 是要删除的次数, m 是要遍历的次数
  ListNode* solution1(ListNode* head, int m) {
    if (!head) return nullptr;
    int cnt = m;
    // 不断遍历删除
    while (head != head->next) {
      if (--cnt == 1) {  // 删除下一个节点，并重新报数
        head->next = head->next->next;
        cnt = m;
      }
      head = head->next;
    }
    return head;
  }

  // O( N )
  ListNode* solution2(ListNode* head, int m) {
    if (!head) return nullptr;
    // 先遍历得链表总长度
    ListNode *cur = head->next;
    int n = 1;
    while (cur != head) {
      ++n;
      cur = cur->next;
    }

    // 直接计算最后留下来的节点的编号 ( 约瑟夫环计算 )
    cur = head;
    n = getLive(n, m) + 1;  // 得到留下来的节点的值, 其编号要 + 1
    while (--n > 0) {
      cur = cur->next;
    }
    // 此时 head 就是最后留下来的编号
    cur->next = cur;
    return cur;
  }

  int getLive(int n, int m) {
    if (n < 1 || m < 1) return -1;
    int last = 0;
    for (int i = 2; i <= n; ++i)
      last = (last + m) % i;
    return last;
  }
};

};

#endif  // LEETCODE_CIG_1_2009_HPP
