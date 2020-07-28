//给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。 
//
// 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。 
//
// 示例 1: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 1->3->5->2->4->NULL
// 
//
// 示例 2: 
//
// 输入: 2->1->3->5->6->4->7->NULL 
//输出: 2->3->6->7->1->5->4->NULL 
//
// 说明: 
//
// 
// 应当保持奇数节点和偶数节点的相对顺序。 
// 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。 
// 
// Related Topics 链表

#include "header.h"

namespace LeetCode328 {

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
    ListNode* oddEvenList(ListNode* head) {
      return solution1(head);
    }

    ListNode* solution1(ListNode* head) {
      if (!head) return nullptr;
      ListNode *node = head, *preOddNode;
      ListNode *evenHead = new ListNode(0), *evenNode = evenHead;

      while (node && node->next) {
        evenNode->next = node->next;  // 偶数
        evenNode = evenNode->next;
        node->next = node->next->next;
        preOddNode = node;
        node = node->next;
      }
      evenNode->next = nullptr;  // 防止链表长度是奇数，所以需要断开
      if (!node) preOddNode->next = evenHead->next;
      else if (!node->next) node->next = evenHead->next;
      return head;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}