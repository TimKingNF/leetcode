//
// Created by timking.nf@foxmail.com on 2021/2/1.
//

#ifndef LEETCODE_CIG_1_2001_HPP
#define LEETCODE_CIG_1_2001_HPP

#include "header.h"

namespace CIG_1_2001 {

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  vector<int> getCommonPart(ListNode* l1, ListNode* l2) {
    auto l1Pos = l1, l2Pos = l2;
    vector<int> ans;
    while (l1Pos && l2Pos) {
      if (l1Pos->val < l2Pos->val)
        l1Pos = l1Pos->next;
      else if (l1Pos->val > l2Pos->val)
        l2Pos = l2Pos->next;
      else {
        ans.push_back(l1Pos->val);
        l1Pos = l1Pos->next;
        l2Pos = l2Pos->next;
      }
    }
    return ans;
  }
};

};

#endif  // LEETCODE_CIG_1_2001_HPP
