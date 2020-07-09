//输入两个链表，找出它们的第一个公共节点。 
//
// 如下面的两个链表： 
//
// 
//
// 在节点 c1 开始相交。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, s
//kipB = 3
//输出：Reference of the node with value = 8
//输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1
//,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
// 
//
// 
//
// 示例 2： 
//
// 
//
// 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB =
// 1
//输出：Reference of the node with value = 2
//输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4
//]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
// 
//
// 
//
// 示例 3： 
//
// 
//
// 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
//输出：null
//输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而
// skipA 和 skipB 可以是任意值。
//解释：这两个链表不相交，因此返回 null。
// 
//
// 
//
// 注意： 
//
// 
// 如果两个链表没有交点，返回 null. 
// 在返回结果后，两个链表仍须保持原有的结构。 
// 可假定整个链表结构中没有循环。 
// 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。 
// 本题与主站 160 题相同：https://leetcode-cn.com/problems/intersection-of-two-linked-lis
//ts/ 
// 
// Related Topics 链表

#include "header.h"

namespace LeetCode_52 {

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      return solution2(headA, headB);
    }

    // 先各自求长度，求diff之差
    // 然后用快慢指针，快指针走较长的串，先走 diff 步， 然后快慢指针同时走，并比较是否相同， 相同则为相交点
    // 这种方法需要遍历的时间度大概为 m+n
    ListNode* solution1(ListNode *headA, ListNode *headB) {
      if (headA == nullptr || headB == nullptr) return nullptr;

      ListNode *headAStart = headA, *headBStart = headB;
      int m = getLinkListLength(headA), n = getLinkListLength(headB), diff = abs(m-n);
      if (n > m) {
        headAStart = headB;
        headBStart = headA;
      }
      // 长的串先走 diff 步
      while (diff--)
        headAStart = headAStart->next;
      // 两个同时走
      while (headAStart && headBStart && headAStart != headBStart) {  // 遍历直到第一个公共结点
        headAStart = headAStart->next;
        headBStart = headBStart->next;
      }
      return headAStart;
    }

    int getLinkListLength(ListNode* head) {
      int ans = 0;
      while (head) {
        ++ans;
        head = head->next;
      }
      return ans;
    }

    // 如果存在相交，则有 A 的长度 + B 相交前的长度 = B 的长度 + A 相交前的长度
    ListNode* solution2(ListNode* headA, ListNode* headB) {
      ListNode* h1 = headA, *h2 = headB;
      while (h1 != h2) {  // 存在相交则为相遇交点，如果不存在则是 链表尾端空指针
        if(h1) h1 = h1->next;
        else h1 = headB;
        if(h2) h2 = h2->next;
        else h2 = headA;
      }
      return h1;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}