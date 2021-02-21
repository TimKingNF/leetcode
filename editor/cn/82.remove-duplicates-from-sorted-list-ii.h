//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。 
//
// 示例 1: 
//
// 输入: 1->2->3->3->4->4->5
//输出: 1->2->5
// 
//
// 示例 2: 
//
// 输入: 1->1->1->2->3
//输出: 2->3 
// Related Topics 链表 
// 👍 446 👎 0

#include "header.h"

namespace LeetCode82 {

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
    ListNode* deleteDuplicates(ListNode* head) {
      return solution1(head);
    }

    ListNode* solution1(ListNode* head) {
      if (!head) return nullptr;
      ListNode *dummy = new ListNode(), *cur;
      dummy->next = head;

      map<int, int> dict;
      // 第一遍遍历获取每个值出现的次数
      cur = head;
      while (cur) {
        ++dict[cur->val];
        cur = cur->next;
      }

      // 第二遍遍历
      ListNode *pre = dummy;
      cur = head;
      while (cur) {
        if (dict[cur->val] == 1) {
          pre->next = cur;
          pre = pre->next;
        }
        cur = cur->next;
      }
      pre->next = nullptr;  // 最后一个指向空
      return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}