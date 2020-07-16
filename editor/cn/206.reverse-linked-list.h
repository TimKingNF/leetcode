//反转一个单链表。 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL 
//
// 进阶: 
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？ 
// Related Topics 链表

#include "header.h"

namespace LeetCode206 {

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
    ListNode* reverseList(ListNode* head) {
      ListNode *reversedHead, *pre = nullptr, *node=head;
      while (node) {
        reversedHead = node->next;
        node->next = pre;
        pre = node;
        node = reversedHead;
      }
      return pre;  // 直到 reversedHead 为 nullptr 的时候, 说明pre是首节点
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}