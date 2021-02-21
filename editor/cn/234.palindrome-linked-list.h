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
      return solution2(head);
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

    // 对 solution1 进行函数拆分一下
    bool solution2(ListNode* head) {
      if (!head) return true;
      // 找到中点，翻转中点之后的链表，再依次比较。 最后恢复链表
      ListNode *mid = getMid(head);
      // 反转right
      ListNode *reverseRight = reverse(mid), *right = reverseRight;
      // 互相比较
      bool ans = true;
      ListNode *left = head;
      while (left && right) {
        if (left->val != right->val) {
          ans = false;
          break;
        }
        left = left->next;
        right = right->next;
      }

      // 从 reverseRight 处恢复链表
      reverse(reverseRight);
      return ans;
    }

    ListNode* getMid(ListNode* head) {
      ListNode *slow = head, *fast = head;
      while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
      }
      return slow;
    }

    ListNode* reverse(ListNode* head) {
      ListNode *pre = nullptr, *tmp;
      while (head) {
        tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
      }
      return pre;
    }

    // 普通解法，利用栈, 全部压入节点，空间是 O( N )
    bool solution3(ListNode* head) {
      if (!head) return true;
      stack<ListNode*> stk;
      ListNode* cur = head;

      while (cur) {
        stk.push(cur);
        cur = cur->next;
      }

      while (head) {
        if (head->val != stk.top()->val) return false;
        stk.pop();
        head = head->next;
      }
      return true;
    }

    // 利用栈，但空间只有 O( N/2 )
    bool solution4(ListNode* head) {
      if (!head) return true;
      ListNode *right = head, *cur = head;
      while (cur && cur->next) {
        cur = cur->next->next;
        right = right->next;
      }

      // 拿到链表右半部分起点之后, 压入栈，与左半部分一个一个比对
      stack<ListNode*> stk;
      while (right) {
        stk.push(right);
        right = right->next;
      }
      while (!stk.empty()) {
        if (head->val != stk.top()->val) return false;
        stk.pop();
        head = head->next;
      }
      return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}