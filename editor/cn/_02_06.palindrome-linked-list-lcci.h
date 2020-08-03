//编写一个函数，检查输入的链表是否是回文的。 
//
// 
//
// 示例 1： 
//
// 输入： 1->2
//输出： false 
// 
//
// 示例 2： 
//
// 输入： 1->2->2->1
//输出： true 
// 
//
// 
//
// 进阶： 
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？ 
// Related Topics 链表

#include "header.h"

namespace LeetCode_02_06 {

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
    bool isPalindrome(ListNode* head) {
      return solution1(head);
    }

    bool solution1(ListNode* head) {
      if (!head) return true;
      bool ans = true;
      // 先找到中间点
      ListNode *fast = head, *slow = head;
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode *middle = slow, *pre = nullptr, *tmp;
      // 从 middle 之后的链表开始翻转
      while (middle) {
        tmp = middle->next;
        middle->next = pre;
        pre = middle;
        middle = tmp;
      }
      // 翻转之后开头时 pre， 与 head 依次比较
      tmp = pre;
      while (pre && head) {
        if (pre->val != head->val) {
          ans = false;
          break;
        }
        pre = pre->next;
        head = head->next;
      }
      // 恢复链表
      pre = nullptr;
      while (tmp) {
        slow = tmp->next;
        tmp->next = pre;
        pre = tmp;
        tmp = slow;
      }
      return ans;
    }

    // solution2:
    // 使用快慢两个指针找到链表中点，慢指针每次前进一步，快指针每次前进两步。
    // 在慢指针前进的过程中，同时修改其 next 指针，使得链表前半部分反序。
    // 最后比较中点两侧的链表是否相等。
  };
//leetcode submit region end(Prohibit modification and deletion)

}