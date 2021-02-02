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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
      ListNode* dummy = new ListNode();
      dummy->next = head;

      ListNode *pre = dummy, *first = head, *second = head;
      // 先走 n 步
      for (int i = 0; i < n; ++i) first = first->next;

      // 获取倒数第 n 个节点
      while (first) {
        first = first->next;
        pre = second;
        second = second->next;
      }
      // 执行删除
      pre->next = second->next;
      return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}