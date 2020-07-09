//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 示例： 
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
// 
// Related Topics 链表

#include "header.h"

namespace LeetCode21 {

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
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;

      ListNode* ans;
      if (l1->val < l2->val) {
        ans = l1;
        ans->next = mergeTwoLists(l1->next, l2);
      } else {
        ans = l2;
        ans->next = mergeTwoLists(l1, l2->next);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}