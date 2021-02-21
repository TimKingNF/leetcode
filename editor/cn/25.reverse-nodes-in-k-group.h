//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。 
//
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 
//
// 示例： 
//
// 给你这个链表：1->2->3->4->5 
//
// 当 k = 2 时，应当返回: 2->1->4->3->5 
//
// 当 k = 3 时，应当返回: 3->2->1->4->5 
//
// 
//
// 说明： 
//
// 
// 你的算法只能使用常数的额外空间。 
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
// 
// Related Topics 链表 
// 👍 889 👎 0

#include "header.h"

namespace LeetCode25 {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      return solution1(head, k);
    }

    ListNode* solution1(ListNode* head, int k) {
      if (!head) return nullptr;
      ListNode *dummy = new ListNode();  // 作为停止节点
      dummy->next = head;
      ListNode *pre = dummy;
      bool next = true;
      while (next) {
        // 从 head 开始走 k 个进行翻转, 然后 head 继续指向下一个起点
        // bool 是否不满足 k 个元素
        next = reverse(&head, &pre, k);
      }
      return dummy->next;
    }

    bool reverse(ListNode **headPtr, ListNode **preEnd, int k) {
      // 先拿到原来的起点
      ListNode *cur = *headPtr;
      int n = k;
      // 先走一遍看是否满足 k
      while (cur && n > 0) {
        --n;
        cur = cur->next;
      }
      if (n != 0) return false;  // 说明无需操作, 直接返回

      cur = *headPtr;
      ListNode *pre = *preEnd;
      ListNode *next;
      while (cur && k > 0) {
        --k;
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
      // 最后处理
      (*preEnd)->next = pre;  // 上一段的终点指向新的起点
      (*headPtr)->next = cur;  // 本次起点，即翻转后的终点指向 cur
      *preEnd = *headPtr;  // 修改新段的终点
      *headPtr = cur; // headPtr 指向新的起点
      return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}