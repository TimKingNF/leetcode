//给定一个二叉树 
//
// struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//} 
//
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。 
//
// 初始状态下，所有 next 指针都被设置为 NULL。 
//
// 
//
// 进阶： 
//
// 
// 你只能使用常量级额外空间。 
// 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。 
// 
//
// 
//
// 示例： 
//
// 
//
// 输入：root = [1,2,3,4,5,null,7]
//输出：[1,#,2,3,#,4,5,7,#]
//解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。 
//
// 
//
// 提示： 
//
// 
// 树中的节点数小于 6000 
// -100 <= node.val <= 100 
// 
//
// 
//
// 
// 
// Related Topics 树 深度优先搜索

#include "header.h"

namespace LeetCode117 {

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // TODO
    Node* connect(Node* root) {
      return solution4(root);
    }

    // bfs 但需要额外的空间
    Node* solution1(Node* root) {
      if (!root) return root;
      deque<Node*> q;
      q.push_back(root);
      Node *cur, *pre;
      int size;
      while (!q.empty()) {
        size = q.size();
        pre = nullptr;
        for (int i = 0; i < size; ++i) {
          cur = q.front();
          q.pop_front();
          if (pre) pre->next = cur;
          if (cur->left) q.push_back(cur->left);
          if (cur->right) q.push_back(cur->right);
          pre = cur;
        }
      }
      return root;
    }

    Node* solution2(Node* root) {
      if (!root) return root;
      Node *lineStart = root, *nextLineStart, *head, *nextRight, *next;
      nextLineStart = head = nextRight = next = nullptr;
      while (lineStart) {
        head = lineStart;
        while (head) {
          // 记录下一行的起点
          if (!nextLineStart) nextLineStart = head->left ? head->left : head->right;

          nextRight = head->right ? head->right : head->left;
          if (head->left && head->right) head->left->next = head->right;
          if (nextRight) {  // 如果是没有子节点的则在这里跳过
            next = head->next;
            while (next && !next->left && !next->right) next = next->next;  // 跳过没有子节点的next
            if (next) nextRight->next = next->left ? next->left : next->right;
          }
          head = head->next;
        }
        lineStart = nextLineStart;
        nextLineStart = nullptr;
      }
      return root;
    }

    // 对 solution2 的简化
    Node* solution3(Node* root) {
      Node *cur = root, *dummy = new Node(), *tail;  // dummy->next 指向下一层的开始
      while (cur) {
        tail = dummy;
        while (cur) {
          if (cur->left) {
            tail->next = cur->left;
            tail = tail->next;
          }
          if (cur->right) {
            tail->next = cur->right;
            tail = tail->next;
          }
          cur = cur->next;
        }
        cur = dummy->next;  // 指向下一层的开始
        if (tail == dummy) break;  // 说明本层没有元素了
      }
      return root;
    }

    // dfs
    Node* solution4(Node* root) {
      if (root && (root->left || root->right)) {
        if (root->left && root->right) root->left->next = root->right;
        Node* node = root->right ? root->right : root->left;
        Node* head = root->next;
        while (head && !head->left && !head->right) head = head->next;
        node->next = head ? (head->left ? head->left : head->right) : nullptr;

        solution4(root->right);  // 递归的顺序需要从右到左
        solution4(root->left);
      }
      return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}