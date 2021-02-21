// 和 ../cn/83.remove-duplicates-from-sorted-list.h 相比，是无序链表
// Created by timking.nf@foxmail.com on 2021/2/6.
//

#ifndef LEETCODE_CIG_1_2016_HPP
#define LEETCODE_CIG_1_2016_HPP

#include "header.h"

namespace CIG_1_2016 {

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    return solution2(head);
  }

  // hash
  // O( N ), O( N )
  ListNode* solution1(ListNode* head) {
    if (!head) return nullptr;
    set<int> dict{head->val};
    ListNode *ans = head, *pre = ans, *cur = head->next;
    // 从下一个元素开始
    while (cur) {
      if (!dict.count(cur->val)) {  // 该值没有出现过
        pre->next = cur;  // 指向下一个没有出现过的元素
        pre = cur;
        dict.insert(cur->val);
      }
      cur = cur->next;
    }
    pre->next = nullptr;  // 最后一个元素指向空
    return ans;
  }

  // 因为是无序，且只能是 O( 1 ) 的空间复杂度，则时间是 O( N^2 )
  ListNode* solution2(ListNode* head) {
    if (!head) return nullptr;
    ListNode *cur = head, *pre, *next;
    while (cur) {
      pre = cur; // 指向本次要检查的节点
      next = cur->next;
      while (next) {  // 将检查的节点 next 指向下一个不重复的节点, 然后一直循环直到结束
        if (next->val == cur->val) {
          pre->next = next->next;
        } else {
          pre = next;
        }
        next = next->next;
      }
      cur = cur->next;
    }
    return head;
  }
};

}
#endif  // LEETCODE_CIG_1_2016_HPP
