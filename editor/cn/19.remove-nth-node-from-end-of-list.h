//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。 
//
// 示例： 
//
// 给定一个链表: 1->2->3->4->5, 和 n = 2.
//
//当删除了倒数第二个节点后，链表变为 1->2->3->5.
// 
//
// 说明： 
//
// 给定的 n 保证是有效的。 
//
// 进阶： 
//
// 你能尝试使用一趟扫描实现吗？ 
// Related Topics 链表 双指针

#include "header.h"

namespace LeetCode19 {

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      return solution2(head, n);
    }

    // 双指针解法
    ListNode* solution1(ListNode* head, int n) {
      if (!head) return nullptr;
      ListNode *remove = head, *ans = head, *pre = nullptr;
      int j = 0;
      while (head) {
        if (j >= n) {
          pre = remove;
          remove = remove->next;
        }
        head = head->next;
        ++j;
      }
      // 移除, 排除n为首节点的情况
      if (pre) pre->next = remove->next;
      else ans = ans->next;
      // delete remove;
      return ans;
    }

    // 更好理解的双指针法
    ListNode* solution2(ListNode* head, int n) {
      if (!head) return nullptr;
      // 新建一个节点指向 head
      ListNode* root = new ListNode(0);
      root->next = head;
      ListNode *slow, *fast;
      slow = fast = root;
      // fast 先走n步
      for (int i = 0; i <= n; ++i) fast = fast->next;
      while (fast) {
        fast = fast->next;
        slow = slow->next;
      }
      slow->next = slow->next->next;
      return root->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}