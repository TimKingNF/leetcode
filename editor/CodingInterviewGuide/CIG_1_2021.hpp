//
// Created by timking.nf@foxmail.com on 2021/2/7.
//

#ifndef LEETCODE_CIG_1_2021_HPP
#define LEETCODE_CIG_1_2021_HPP

#include "header.h"

namespace CIG_1_2021 {

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* insertCyclingLinkList(ListNode* head, int num) {
    if (!head) {
      head = new ListNode(num);
      head->next = head;
      return head;
    }

    // 遍历, 找到插入位置，如果没有找到，则插到 head 的前面
    auto cur = head->next, pre = head;
    while (cur != head) {
      if (pre->val <= num && cur->val >= num) {  // 说明在此处插入元素
        break;
      }
      pre = cur;
      cur = cur->next;
    }
    // 没有找到时，pre 会指向 head 的前一个节点
    pre->next = new ListNode(num);
    pre->next->next = cur;
    // 根据插入的值是最大还是最小，决定返回哪个节点
    return head->val < num ? head : pre->next;
  }
};

}
#endif  // LEETCODE_CIG_1_2021_HPP
