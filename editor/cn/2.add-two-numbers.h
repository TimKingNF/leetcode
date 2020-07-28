//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。 
//
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。 
//
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 示例： 
//
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
// 
// Related Topics 链表 数学

#include "header.h"

namespace LeetCode2 {

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      return solution2(l1, l2);
    }

    ListNode* solution1(ListNode* l1, ListNode* l2) {
      if (!l1) return l2;
      if (!l2) return l1;
      // 返回一个新的链表
      int sum = 0, borrow = 0;
      ListNode *ans, *cur, *pre;
      ans = pre = new ListNode(-1);
      while (l1 && l2) {
        sum = l1->val + l2->val + borrow;
        borrow = sum / 10;
        cur = new ListNode(sum % 10);
        pre->next = cur;
        pre = cur;
        l1 = l1->next;
        l2 = l2->next;
      }
      // 遍历剩下的位
      if (l2) swap(l1, l2);
      while (l1) {
        sum = l1->val + borrow;
        borrow = sum / 10;
        cur = new ListNode(sum % 10);
        pre->next = cur;
        pre = cur;
        l1 = l1->next;
      }
      // 如果 borrow 不为 0， 需要补上
      if (borrow) pre->next = new ListNode(borrow);
      return ans->next;
    }

    // 简化一下代码
    ListNode* solution2(ListNode* l1, ListNode* l2) {
      ListNode *head = new ListNode(-1), *pre = head, *cur;
      int carry = 0, sum = 0;
      while (l1 || l2 || carry) {
        sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        cur = new ListNode(sum % 10);
        pre->next = cur;
        pre = cur;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
      }
      return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}