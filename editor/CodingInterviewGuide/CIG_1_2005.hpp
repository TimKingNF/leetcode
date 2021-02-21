//
// Created by timking.nf@foxmail.com on 2021/2/3.
//

#ifndef LEETCODE_CIG_1_2005_HPP
#define LEETCODE_CIG_1_2005_HPP

#include "header.h"

namespace CIG_1_2005 {

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int v) : val(v), next(nullptr) {}
};

class Solution {
 public:
  // 删除位于 a/b 处的节点 ( 正数 )
  ListNode* removeRatioNode(ListNode* node, int a, int b) {
    if (a < 1 || a > b) return node;  // 参数无效

    // 记录 a/b 处是第几个节点，则需要先计算出整体的长度
    int n = 0;
    ListNode* cur = node;
    while (cur) {
      ++n;
      cur = cur->next;
    }

    int k = n * a / b;
    if (k == 1) return node->next;
    if (k > 1) {
      cur = node;
      while (--k > 1) cur = cur->next;
      // k == 1 即 要删除的节点的前一个节点
      cur->next = cur->next->next;
    }
    return node;
  }
};

};

#endif  // LEETCODE_CIG_1_2005_HPP
