//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。 
//
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。 
//
// 说明：不允许修改给定的链表。 
//
// 
//
// 示例 1： 
//
// 输入：head = [3,2,0,-4], pos = 1
//输出：tail connects to node index 1
//解释：链表中有一个环，其尾部连接到第二个节点。
// 
//
// 
//
// 示例 2： 
//
// 输入：head = [1,2], pos = 0
//输出：tail connects to node index 0
//解释：链表中有一个环，其尾部连接到第一个节点。
// 
//
// 
//
// 示例 3： 
//
// 输入：head = [1], pos = -1
//输出：no cycle
//解释：链表中没有环。
// 
//
// 
//
// 
//
// 进阶： 
//你是否可以不用额外空间解决此题？ 
// Related Topics 链表 双指针

#include "header.h"

namespace LeetCode142 {

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
    ListNode *detectCycle(ListNode *head) {
      return solution1(head);
    }

    // 证明:
    // 设当 slow 在环入口时，此时 fast 距离环入口的距离为 d
    // 则可知 起点到环入口的距离 k = d + n * R, R 为环的大小
    // 有公式 2k = k + n * R 可以验证
    // 再计算, 要想 slow 和 fast 相遇， fast 还需要比 slow 多走 R - d 的距离才可以相遇
    // 因为 fast 一次走两步，所以 fast 还需要在 2(R-d) 步，即相遇的位置为 d + 2(R-d) = 2R - d
    // 即离环入口为 -d 的位置相遇，此时将 fast 重新从头结点开始走，速度为一次一步，与慢指针相同。
    // 可知，fast 走到环入口时，所需步数为k。刚好，k == delta + n * R，这也是 slow 在环中所走的距离。
    // 所以此时 slow 刚好走到环入口，并与 fast 相遇。
    ListNode *solution1(ListNode *head) {
      if (!head) return nullptr;
      // 首先验证是否有环
      ListNode *slow = head, *fast = head;
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;  // 2R - d 处
      }
      if (!fast || !fast->next) return nullptr;  // 到达链表尾部, 说明无环
      fast = head;
      while (fast != slow) {
        slow = slow->next;
        fast = fast->next;
      }
      return fast;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}