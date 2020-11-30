//对链表进行插入排序。 
//
// 
//插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。 
//每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。 
//
// 
//
// 插入排序算法： 
//
// 
// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。 
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。 
// 重复直到所有输入数据插入完为止。 
// 
//
// 
//
// 示例 1： 
//
// 输入: 4->2->1->3
//输出: 1->2->3->4
// 
//
// 示例 2： 
//
// 输入: -1->5->3->4->0
//输出: -1->0->3->4->5
// 
// Related Topics 排序 链表 
// 👍 259 👎 0

#include "header.h"

namespace LeetCode147 {

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
    ListNode* insertionSortList(ListNode* head) {
      return solution1(head);
    }

    // O( n^2 )
    ListNode* solution1(ListNode* head) {
      if (!head) return nullptr;

      auto* ans = new ListNode(0);
      ans->next = head;
      head = head->next;
      ans->next->next = nullptr;  // 断开链表

      while (head) {
        auto* tmp = head->next;  // 记录原来的下一个元素
        insertItem(ans, head);
        head = tmp;
      }
      return ans->next;
    }

    void insertItem(ListNode* head, ListNode* item) {
      ListNode* prv = head;
      head = head->next;
      // 找到插入位置
      while (head && item->val >= head->val) {
        prv = head;
        head = head->next;
      }
      prv->next = item;
      item->next = head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}