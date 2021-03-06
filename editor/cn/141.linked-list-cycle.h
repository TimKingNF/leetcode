//给定一个链表，判断链表中是否有环。 
//
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。 
//
// 
//
// 示例 1： 
//
// 输入：head = [3,2,0,-4], pos = 1
//输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。
// 
//
// 
//
// 示例 2： 
//
// 输入：head = [1,2], pos = 0
//输出：true
//解释：链表中有一个环，其尾部连接到第一个节点。
// 
//
// 
//
// 示例 3： 
//
// 输入：head = [1], pos = -1
//输出：false
//解释：链表中没有环。
// 
//
// 
//
// 
//
// 进阶： 
//
// 你能用 O(1)（即，常量）内存解决此问题吗？ 
// Related Topics 链表 双指针

#include "header.h"

namespace LeetCode141 {

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
    bool hasCycle(ListNode *head) {
      return solution1(head);
    }

    bool solution1(ListNode *head) {
      ListNode *slow, *fast;
      slow = fast = head;
      // slow 一次走1步， fast 一次走2步，如果最终能相遇说明存在环
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
      }
      return false;
      // if (!fast || fast->next) return 0;  // 说明不存在环
      // 在第一次相遇之后继续往下在，到在此相遇，fast会比slow多走 R 步，即环的大小
      // int size = 1;
      // fast = fast->next->next;
      // slow = slow->next;
      // while (fast != slow) {
      //   ++size;
      //   fast = fast->next->next;
      //   slow = slow->next;
      // }
      // size即为环的大小
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}