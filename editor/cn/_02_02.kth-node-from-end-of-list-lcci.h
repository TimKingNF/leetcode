//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。 
//
// 注意：本题相对原题稍作改动 
//
// 示例： 
//
// 输入： 1->2->3->4->5 和 k = 2
//输出： 4 
//
// 说明： 
//
// 给定的 k 保证是有效的。 
// Related Topics 链表 双指针 
// 👍 54 👎 0

#include "header.h"

namespace LeetCode_02_02 {

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
    int kthToLast(ListNode* head, int k) {
      return solution1(head, k);
    }

    int solution1(ListNode* head, int k) {
      // k 保证有效，也即 k >= 1
      ListNode *first = head, *second = head;
      for (int i = 0; i < k; ++i) first = first->next;
      while (first) {
        first = first->next;
        second = second->next;
      }
      return second->val;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}