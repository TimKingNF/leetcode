//输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，
//它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。 
//
// 
//
// 示例： 
//
// 给定一个链表: 1->2->3->4->5, 和 k = 2.
//
//返回链表 4->5. 
// Related Topics 链表 双指针

#include "header.h"

namespace LeetCode_22 {

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
      return solution2(head, k);
    }

    ListNode* solution1(ListNode* head, int k) {
      if (head == nullptr || k == 0) return nullptr;

      // 如果总长度小于 k, 返回 nullptr
      ListNode* slow_ptr = head;
      ListNode* tmp = head;
      int quick = 0;
      while (tmp) {
        if (quick < k) {
          ++quick;
          tmp = tmp->next;
        } else {
          ++quick;
          tmp = tmp->next;
          slow_ptr = slow_ptr->next;
        }
      }

      return quick >= k ? slow_ptr : nullptr;
    }

    ListNode* solution2(ListNode* head, int k) {
      if (head == nullptr || k == 0) return nullptr;

      ListNode* pHead = head;
      ListNode* pBehind = head;
      for (int i = 0; i < k - 1; ++i) {
        if (pHead->next != nullptr)
          pHead = pHead->next;
        else
          return nullptr;
      }

      while (pHead->next != nullptr) {
        pHead = pHead->next;
        pBehind = pBehind->next;
      }
      return pBehind;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}