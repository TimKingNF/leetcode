//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
//

#include "header.h"

namespace LeetCode_06 {

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
    vector<int> reversePrint(ListNode* head) {
      return solution1(head);
    }

    vector<int> solution1(ListNode* head) {
      // 使用一个 stack 存储，然后遍历即可
      int count = 0;
      stack<ListNode*> stack_ptr;
      while (head != nullptr) {
        stack_ptr.push(head);
        head = head->next;
        ++count;
      }

      vector<int> res(count);
      count = 0;
      while (stack_ptr.size() != 0) {
        res[count++] = stack_ptr.top()->val;
        stack_ptr.pop();
      }
      return res;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}