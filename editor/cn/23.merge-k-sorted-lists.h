//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。 
//
// 示例: 
//
// 输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6 
// Related Topics 堆 链表 分治算法

#include "header.h"

namespace LeetCode23 {

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      return solution2(lists);
    }

    // 暴力求解 两两结合 O( KN )

    // 分治, 归并
    // O( NlogK )
    ListNode* solution1(vector<ListNode*>& lists) {
      if (lists.empty()) return nullptr;
      return helper(lists, 0, lists.size() - 1);
    }

    ListNode* helper(vector<ListNode*>& lists, int lo, int hi) {
      if (lo >= hi) return lists[lo];
      int mid = lo + (hi - lo) / 2;
      ListNode* left = helper(lists, lo, mid);
      ListNode* right = helper(lists, mid + 1, hi);
      return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;

      ListNode* ans;
      if (l1->val < l2->val) {
        ans = l1;
        ans->next = mergeTwoLists(l1->next, l2);
      } else {
        ans = l2;
        ans->next = mergeTwoLists(l1, l2->next);
      }
      return ans;
    }

 private:
    struct cmp {
      bool operator() (ListNode* first, ListNode* second) {
        return first->val > second->val;  // 从大到小
      }
    };

    // 优先队列
    // O( NlogK )
    ListNode* solution2(vector<ListNode*>& lists) {
      if (lists.empty()) return nullptr;
      int n = lists.size();
      priority_queue<ListNode*, vector<ListNode*>, cmp> pq;  // 小顶堆
      // 将 K 个元素放入堆中
      for (int i = 0; i < n; ++i) {
        if (lists[i]) pq.push(lists[i]);
      }
      ListNode* dummy = new ListNode(-1);
      ListNode* tmp = dummy;
      while (!pq.empty()) {
        ListNode* cur = pq.top();  // 拿到堆上最小值的元素
        pq.pop();
        tmp->next = cur;
        // 将 cur 的下一个元素放入堆中
        if (cur->next) pq.push(cur->next);
        tmp = tmp->next;
      }
      return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}