//给定一个单链表 L：L0→L1→…→Ln-1→Ln ， 
//将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→… 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 示例 1: 
//
// 给定链表 1->2->3->4, 重新排列为 1->4->2->3. 
//
// 示例 2: 
//
// 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3. 
// Related Topics 链表 
// 👍 361 👎 0

#include "header.h"

namespace LeetCode143 {

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
    void reorderList(ListNode* head) {
      return solution1(head);
    }

    // O( N ), O( 1 )
    void solution1(ListNode* head) {
      if (!head) return;
      // 先获取到中点
      ListNode *slow = head, *fast = head;
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode *mid = slow;  // 当前中点

      // 从中点处下一个节点开始翻转链表
      ListNode *tail = reverseList(mid->next);
      mid->next = nullptr;  // 断开中点处

      fast = new ListNode, slow = fast;
      while (head && tail) {
        slow->next = head;
        head = head->next;
        slow = slow->next;

        slow->next = tail;
        tail = tail->next;
        slow = slow->next;
      }
      slow->next = head ? head : tail;
      delete fast;
    }

    ListNode* reverseList(ListNode* head) {
      if (!head || !head->next) return head;

      ListNode *pre = nullptr;
      while (head) {
        ListNode* next = head->next;
        head->next = pre;
        pre = head;
        head = next;
      }
      return pre;
    }

    // solution2: 直接使用一个 vector 存下所有节点，然后在重建链表即可
};
//leetcode submit region end(Prohibit modification and deletion)

}