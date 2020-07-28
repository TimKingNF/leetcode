//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。 
//
// 示例 1: 
//
// 输入: 1->2->3->4->5->NULL, k = 2
//输出: 4->5->1->2->3->NULL
//解释:
//向右旋转 1 步: 5->1->2->3->4->NULL
//向右旋转 2 步: 4->5->1->2->3->NULL
// 
//
// 示例 2: 
//
// 输入: 0->1->2->NULL, k = 4
//输出: 2->0->1->NULL
//解释:
//向右旋转 1 步: 2->0->1->NULL
//向右旋转 2 步: 1->2->0->NULL
//向右旋转 3 步: 0->1->2->NULL
//向右旋转 4 步: 2->0->1->NULL 
// Related Topics 链表 双指针

#include "header.h"

namespace LeetCode61 {

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
    ListNode* rotateRight(ListNode* head, int k) {
      return solution1(head, k);
    }

    // O(N)
    ListNode* solution1(ListNode* head, int k) {
      if (!head) return nullptr;
      int n = 0;  // 记录环的长度
      ListNode *cur = head, *tail;
      while (cur) {
        tail = cur;
        ++n;
        cur = cur->next;
      }
      if (k % n == 0) return head;
      tail->next = head;  // 构造出一个环形链表
      // 从tail开始走 n - k % n 的步数
      int step = n - k % n;
      for (int i = 0; i < step; ++i) tail = tail->next;
      head = tail->next;
      tail->next = nullptr;  // 断开环
      return head;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}