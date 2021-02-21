//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。 
//
// 示例 1: 
//
// 输入: 1->1->2
//输出: 1->2
// 
//
// 示例 2: 
//
// 输入: 1->1->2->3->3
//输出: 1->2->3 
// Related Topics 链表

#include "header.h"

namespace LeetCode83 {

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
    ListNode* deleteDuplicates(ListNode* head) {
      return solution2(head);
    }

    // 该写法会导致内存泄漏
    ListNode* solution1(ListNode* head) {
      if (!head) return head;
      ListNode* dummy = new ListNode(head->val == 0 ? -1 : 0);
      dummy->next = head;

      ListNode *pre = dummy;
      while (head) {
        if (!head->next || head->next->val != head->val) {  // head后面没有元素，或者head就是最后一个元素
          // 从pre 到 head 这中间的指针就没有变量指向他们了
          pre->next = head;
          pre = head;
        }
        head = head->next;
      }
      return dummy->next;
    }

    ListNode* solution2(ListNode* head) {
      if (!head) return head;
      ListNode* ptr = head;
      while (ptr->next) {
        if (ptr->val == ptr->next->val) {
          ListNode* p = ptr->next;
          ptr->next = p->next;
          delete p;  // 释放
        } else {
          ptr = ptr->next;
        }
      }
      return head;
    }

    ListNode* solution3(ListNode* head) {
      if (!head) return nullptr;
      ListNode *cur = head, *pre = cur;
      while (cur) {
        if (cur->val == pre->val) {
          pre->next = cur->next;
        } else {
          pre = cur;
        }
        cur = cur->next;
      }
      return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}