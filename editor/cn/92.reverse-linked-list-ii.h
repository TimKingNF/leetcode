//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。 
//
// 说明: 
//1 ≤ m ≤ n ≤ 链表长度。 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
//输出: 1->4->3->2->5->NULL 
// Related Topics 链表 
// 👍 660 👎 0

#include "header.h"

namespace LeetCode92 {

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      return solution2(head, m, n);
    }

    ListNode* solution1(ListNode* head, int m, int n) {
      if (!head || m == n) return head;  // 无需操作

      // 已知 m, n 都小于链表长度
      int cnt = 0;
      ListNode *pre, *next, *reverseTail, *reverseHeadPre;
      ListNode *dummy = new ListNode();  // 构造一个假节点
      pre = dummy;
      pre->next = head;

      while (head) {
        ++cnt;
        next = head->next;
        // 判断是否需要反转
        if (cnt > m && cnt < n) {
          head->next = pre;
        } else if (cnt == m) {
          reverseTail = head;  // 反转之后的尾节点
          reverseHeadPre = pre;
        } else if (cnt == n) {
          head->next = pre;
          reverseHeadPre->next = head;  // 连上反转之后的起点
          reverseTail->next = next;  // 指向原来的下一个节点
        }
        pre = head;
        head = next;
      }
      return dummy->next;
    }

    ListNode* solution2(ListNode* head, int m, int n) {
      int len = 0;
      ListNode *node1 = head, *fPre, *tPos;
      fPre = tPos = nullptr;

      // 先计算长度, 算出要反转的起点的前一个和终点的后一个
      while (node1) {
        ++len;
        if (len == m-1) fPre = node1;
        if (len == n+1) tPos = node1;
        node1 = node1->next;
      }

      if (m > n || m < 1 || n > len) return head;

      node1 = fPre ? fPre->next : head;  // 要翻转的起点
      ListNode *node2 = node1->next;
      node1->next = tPos;  // 先连上下一段链表
      ListNode *next;
      while (node2 != tPos) {
        next = node2->next;
        node2->next = node1;
        node1 = node2;
        node2 = next;
      }
      if (fPre) {  // 说明翻转链表前也有一段，返回开头 head
        fPre->next = node1;
        return head;
      }
      return node1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}