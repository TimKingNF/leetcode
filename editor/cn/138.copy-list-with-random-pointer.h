//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。 
//
// 要求返回这个链表的 深拷贝。 
//
// 我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示： 
//
// 
// val：一个表示 Node.val 的整数。 
// random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为 null 。 
// 
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
// Related Topics 哈希表 链表

#include "header.h"

namespace LeetCode138 {

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
      return solution1(head);
    }

    // 核心的思路就是要节约定位每个新clone节点的位置，这里利用了原有节点
    Node* solution1(Node* head) {
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
      Node* cur;
      while (head) {
        cur = head->next;  // 新节点
        head->next = cur->next;
        head = head->next;
        if(head) cur->next = head->next;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}