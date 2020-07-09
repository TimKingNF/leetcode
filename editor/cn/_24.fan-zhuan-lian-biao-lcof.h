//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。 
//
// 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 206 题相同：https://leetcode-cn.com/problems/reverse-linked-list/ 
// Related Topics 链表

#include "header.h"

namespace LeetCode_24 {

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
    ListNode* reverseList(ListNode* head) {
      return solution2(head);
    }

    ListNode* solution1(ListNode* head) {
      if (head == nullptr) return nullptr;
      stack<ListNode*> stk;
      while (head) {
        stk.push(head);
        head = head->next;
      }
      // 从栈顶取出元素，并修改next
      ListNode* preTop = stk.top();  // 取出第一个元素
      ListNode* ans = preTop;
      stk.pop();
      while (!stk.empty()) {
        preTop->next = stk.top();
        preTop = stk.top();
        stk.pop();
      }
      preTop->next = nullptr;  // 修改最后一个元素的next指针
      return ans;
    }

    ListNode* solution2(ListNode* head) {
      ListNode* reversedHead;
      ListNode* node = head;
      ListNode* pre = nullptr;
      while (node) {
        reversedHead = node->next;
        node->next = pre;
        pre = node;
        node = reversedHead;
      }
      return pre;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}