//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指
//向链表中的任意节点或者 null。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
// 
//
// 示例 2： 
//
// 
//
// 输入：head = [[1,1],[2,1]]
//输出：[[1,1],[2,1]]
// 
//
// 示例 3： 
//
// 
//
// 输入：head = [[3,null],[3,0],[3,null]]
//输出：[[3,null],[3,0],[3,null]]
// 
//
// 示例 4： 
//
// 输入：head = []
//输出：[]
//解释：给定的链表为空（空指针），因此返回 null。
// 
//
// 
//
// 提示： 
//
// 
// -10000 <= Node.val <= 10000 
// Node.random 为空（null）或指向链表中的节点。 
// 节点数目不超过 1000 。 
// 
//
// 
//
// 注意：本题与主站 138 题相同：https://leetcode-cn.com/problems/copy-list-with-random-point
//er/ 
//
// 
// Related Topics 链表

#include "header.h"

namespace LeetCode_35 {

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
      return solution2(head);
    }

    // 时间 O(N). 空间 O(N)
    Node* solution1(Node* head) {
      if (!head) return nullptr;
      // 遍历两次，第一遍构造新的 Node，第二遍指定 random
      unordered_map<int, Node*> copyMap;
      unordered_map<Node*, int> origMap;
      Node *pre = new Node(head->val), *ans = pre, *p = head->next;
      int i = 0;
      copyMap.insert(pair<int, Node*>(i, pre));
      origMap.insert(pair<Node*, int>(head, i));
      while (p) {
        pre->next = new Node(p->val);
        ++i;
        copyMap.insert(pair<int, Node*>(i, pre->next));
        origMap.insert(pair<Node*, int>(p, i));
        pre = pre->next;
        p = p->next;
      }
      // 遍历第二遍，从源链表中 find 到 orig对应的Index，然后在 ans 中指定
      p = ans;
      while (p && head) {
        auto search = origMap.find(head->random);
        if (search != origMap.end())
          p->random = copyMap.find(search->second)->second;
        else
          p->random = nullptr;
        p = p->next;
        head = head->next;
      }
      return ans;
    }

    // 时间 O(N)
    Node* solution2(Node* head) {
      if (!head) return nullptr;
      // 将每一个clone出来的节点挂载到原有节点的后方
      // 形成 A -> A' -> B -> B'  的链
      cloneNodes(head);
      // 从0开始 将每个偶数节点(即原节点)的 next(即新节点) 的random 指向原节点的的 random的 next
      connectRandomNodes(head);
      // 只返回奇数节点的新链表
      return reconnectNodes(head);
    }

    void cloneNodes(Node* head) {
      Node *copyNode;
      while (head) {
        copyNode = new Node(head->val);
        copyNode->next = head->next;
        head->next = copyNode;
        head = copyNode->next;
      }
    }

    void connectRandomNodes(Node* head) {
      while (head && head->next) {
        if (head->random) {
          head->next->random = head->random->next;  // 指向新的节点
        }
        head = head->next->next;
      }
    }

    // 这里需要重新拆回原来的两个链表
    Node* reconnectNodes(Node* head) {
      if (!head) return nullptr;
      Node* ans = head->next;
      Node* tmp;
      while (head) {
        if (!head->next)
          break;
        tmp = head->next;
        head->next = head->next->next;
        head = tmp;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}