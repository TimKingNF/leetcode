//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。 
//
// 示例 1: 
//
// 输入: 4->2->1->3
//输出: 1->2->3->4
// 
//
// 示例 2: 
//
// 输入: -1->5->3->4->0
//输出: -1->0->3->4->5 
// Related Topics 排序 链表

#include "header.h"

namespace LeetCode148 {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
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
    ListNode* sortList(ListNode* head) {
      return solution3(head);
    }

    // 快速排序
    ListNode* solution1(ListNode* head) {
      if (!head) return nullptr;
      ListNode* first = head;
      ListNode *leftDummy = new ListNode(), *rightDummy = new ListNode();
      ListNode *left = leftDummy, *right = rightDummy;
      head = head->next;
      // 将大于 first 的节点 和 小于 first 的节点的值，放在两个单独的链表中
      while (head) {
        if (head->val >= first->val) {
          right->next = head;
          right = right->next;
        } else {
          left->next = head;
          left = left->next;
        }
        head = head->next;
      }
      // 遍历结束之后断开 left 和 right
      left->next = right->next = nullptr;
      leftDummy->next = solution1(leftDummy->next);  // 将 left 继续排序
      rightDummy->next = solution1(rightDummy->next);

      if (leftDummy->next) {
        // 取得 left 链表的最后一个节点
        left = leftDummy->next;
        while (left->next) {
          left = left->next;
        }
        // 连接排序后的链表
        left->next = first;
      } else {
        leftDummy->next = first;
      }
      first->next = rightDummy->next;
      return leftDummy->next;
    }

    // 归并排序, 递归法, 从上到下合并
    ListNode* solution2(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode *slow = head, *fast = head->next;  // fast 从 head->next 开始，防止2节点递归
      while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
      }
      // 获取链表的中点, 从中点断开
      ListNode *mid = slow->next;
      slow->next = nullptr;

      // 分别排序
      ListNode *left = solution2(head);
      ListNode *right = solution2(mid);

      // 合并
      ListNode *dummy = new ListNode(), *cur = dummy;
      while (left && right) {
        if (left->val < right->val) {
          cur->next = left;
          left = left->next;
        } else {
          cur->next = right;
          right = right->next;
        }
        cur = cur->next;
      }
      cur->next = left ? left : right;
      return dummy->next;
    }

    // 归并排序，从下到上，迭代法
    // 每次合并相邻 1, 2, 4, 8... 个节点
    ListNode* solution3(ListNode* head) {
      int n = 0, intv = 1;

      // 计算链表长度
      ListNode *h = head, *dummy = new ListNode();
      while (h) { ++n; h = h->next; }

      dummy->next = head;
      // 合并相邻 intv 个节点
      while (intv < n) {
        ListNode *pre = dummy;
        h = dummy->next;
        while (h) {
          // 获取需要合并的两个链表头节点
          ListNode *h1 = h;
          int i = intv;
          while (i && h) {
            h = h->next;
            --i;
          }
          if (i > 0) break;  // 没有 h2, 所以不需要合并了
          ListNode *h2 = h;
          i = intv;

          // 继续往下读，这里为了取到在 h1 h2 合并之后的 下一个节点，即新一轮合并的 h1
          while (i && h) {
            h = h->next;
            --i;
          }

          // 获取 h1 和 h2 的链表长度
          int c1 = intv, c2 = intv - i;

          // 开始合并
          while (c1 && c2) {
            if (h1->val < h2->val) {
              pre->next = h1;
              h1 = h1->next;
              --c1;
            } else {
              pre->next = h2;
              h2 = h2->next;
              --c2;
            }
            pre = pre->next;
          }
          pre->next = c1 ? h1 : h2;
          // 将 pre 指针移动到合并之后的最后一个元素
          while (c1 > 0 || c2 > 0) {
            pre = pre->next;
            --c1;
            --c2;
          }

          pre->next = h;
        }
        intv *= 2;
      }
      return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}