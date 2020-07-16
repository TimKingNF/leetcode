//请判断一个链表是否为回文链表。 
//
// 示例 1: 
//
// 输入: 1->2
//输出: false 
//
// 示例 2: 
//
// 输入: 1->2->2->1
//输出: true
// 
//
// 进阶： 
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？ 
// Related Topics 链表 双指针

#include "header.h"

namespace LeetCode234 {

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

    // 找到中点再断开，反转后半部分链表，再进行比较，最后再恢复链表
    bool solution1(ListNode* head) {
      ListNode *slow, *fast, *pre, *reverseHead;
      slow = fast = head;
      // 找到中点
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      // 从 middle 之后的链表进行反转
      pre = nullptr;
      while (slow) {
        reverseHead = slow->next;
        slow->next = pre;
        pre = slow;
        slow = reverseHead;
      }
      // 翻转之后的链表开头是 pre，和 head 进行依次比较, 有一个较长也没关系, 记录 ans
      reverseHead = pre;  // 记录下来
      bool ans = true;
      while (head && pre) {
        if (head->val != pre->val) {
          ans = false;
          break;
        }
        head = head->next;
        pre = pre->next;
      }
      // 恢复链表, 从middle开始，重新反转一次即可
      pre = nullptr;
      while (reverseHead) {
        slow = reverseHead->next;
        reverseHead->next = pre;
        pre = reverseHead;
        reverseHead = slow;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}