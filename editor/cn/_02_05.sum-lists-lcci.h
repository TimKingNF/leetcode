//给定两个用链表表示的整数，每个节点包含一个数位。 
//
// 这些数位是反向存放的，也就是个位排在链表首部。 
//
// 编写函数对这两个整数求和，并用链表形式返回结果。 
//
// 
//
// 示例： 
//
// 输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
//输出：2 -> 1 -> 9，即912
// 
//
// 进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢? 
//
// 示例： 
//
// 输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
//输出：9 -> 1 -> 2，即912
// 
// Related Topics 链表 数学 
// 👍 37 👎 0

#include "header.h"

namespace LeetCode_02_05 {

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      return solution1(l1, l2);
    }

    ListNode* solution1(ListNode* l1, ListNode* l2) {
      if (!l1) return l2;
      if (!l2) return l1;
      int carry = 0, sum;
      ListNode *ans = l1, *prev;
      while (l1 && l2) {
        sum = l1->val + l2->val + carry;
        l1->val = sum % 10;
        carry = sum / 10;
        prev = l1;
        l1 = l1->next;
        l2 = l2->next;
      }
      ListNode *l = l1 ? l1 : l2;
      if (l2) prev->next = l2;

      while (l) {
        sum = l->val + carry;
        l->val = sum % 10;
        carry = sum / 10;
        prev = l;
        l = l->next;
      }
      if (carry) prev->next = new ListNode(carry);
      return ans;
    }

    // 正向链表，先翻转2个链表，再进行求和
};
//leetcode submit region end(Prohibit modification and deletion)

}