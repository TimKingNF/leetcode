//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例: 
//
// 给定 1->2->3->4, 你应该返回 2->1->4->3.
// 
// Related Topics 链表

#include "header.h"

namespace LeetCode24 {

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
    ListNode* swapPairs(ListNode* head) {
      return solution2(head);
    }

    // 递归: O(N), O(N)
    ListNode* solution1(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode* first = head;
      ListNode* second = head->next;
      first->next = solution1(second->next);
      second->next = first;
      return second;
    }

    // 循环: O(N), O(1)
    ListNode* solution2(ListNode* head) {
      if (!head || !head->next) return head; // list length is 0 or 1

      ListNode *cur = head, *dummy = new ListNode(0), *pre = dummy, *next;
      while (cur && cur->next) {
        next = cur->next;

        // swap
        cur->next = next->next;
        next->next = cur;
        pre->next = next;  // 原来的前一个节点，指向两两调换后的节点

        pre = cur;
        cur = cur->next;  // 指向下下个元素
      }
      return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}