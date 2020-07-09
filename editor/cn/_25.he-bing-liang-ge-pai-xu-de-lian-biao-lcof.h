//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。 
//
// 示例1： 
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4 
//
// 限制： 
//
// 0 <= 链表长度 <= 1000 
//
// 注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/ 
// Related Topics 分治算法

#include "header.h"

namespace LeetCode_25 {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      return solution2(l1, l2);
    }

    ListNode* solution1(ListNode* l1, ListNode* l2) {
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;

      ListNode *tmp = new ListNode(0), *ans_pre = tmp;
      while (l1 && l2) {
        if (l1->val < l2->val) {
          tmp->next = l1;
          l1 = l1->next;
        } else {
          tmp->next = l2;
          l2 = l2->next;
        }
        tmp = tmp->next;
      }

      if (l1) {
        tmp->next = l1;
      }
      if (l2) {
        tmp->next = l2;
      }

      return ans_pre->next;
    }

    // 递归
    ListNode* solution2(ListNode* l1, ListNode* l2) {
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;

      ListNode* ans;
      if (l1->val < l2->val) {
        ans = l1;
        ans->next = solution2(l1->next, l2);
      } else {
        ans = l2;
        ans->next = solution2(l1, l2->next);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}