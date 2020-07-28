//删除链表中等于给定值 val 的所有节点。 
//
// 示例: 
//
// 输入: 1->2->6->3->4->5->6, val = 6
//输出: 1->2->3->4->5
// 
// Related Topics 链表

#include "header.h"

namespace LeetCode203 {

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
    ListNode* removeElements(ListNode* head, int val) {
      return solution1(head, val);
    }

    ListNode* solution1(ListNode* head, int val) {
      if (!head) return nullptr;
      ListNode* root = new ListNode(0);
      root->next = head;

      ListNode* pre = root;
      while (head) {
        if (head->val == val) pre->next = head->next;
        else pre = head;
        head = head->next;
      }
      return root->next;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}