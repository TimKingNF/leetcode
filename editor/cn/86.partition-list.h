//给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。 
//
// 你应当保留两个分区中每个节点的初始相对位置。 
//
// 
//
// 示例： 
//
// 
//输入：head = 1->4->3->2->5->2, x = 3
//输出：1->2->2->4->3->5
// 
// Related Topics 链表 双指针 
// 👍 319 👎 0

#include "header.h"

namespace LeetCode86 {

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
    ListNode* partition(ListNode* head, int x) {
      return solution1(head, x);
    }

    ListNode* solution1(ListNode* head, int x) {
      if (!head) return head;
      ListNode* first = new ListNode(0), *ans = first;
      ListNode* second = new ListNode(0), *tmp = second;

      while (head) {
        if (head->val < x) {
          first->next = head;
          first = first->next;
        } else {
          second->next = head;
          second = second->next;
        }
        head = head->next;
      }
      second->next = nullptr;
      first->next = tmp->next;
      return ans->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}