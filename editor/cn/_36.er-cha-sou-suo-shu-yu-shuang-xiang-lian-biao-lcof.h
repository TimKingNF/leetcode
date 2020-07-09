//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。 
//
// 
//
// 为了让您更好地理解问题，以下面的二叉搜索树为例： 
//
// 
//
// 
//
// 
//
// 我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是
//第一个节点。 
//
// 下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。 
//
// 
//
// 
//
// 
//
// 特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。 
//
// 
//
// 注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-
//to-sorted-doubly-linked-list/ 
//
// 注意：此题对比原题有改动。 
// Related Topics 分治算法

#include "header.h"

namespace LeetCode_36 {

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node* _left, Node* _right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
      return solution2(root);
    }

    Node* solution1(Node* root) {
      if (!root) return nullptr;
      Node* head = solution1core(root);
      Node* tail = head;
      // 将最后一步首位节点连接
      while (tail->right) {
        tail = tail->right;
      }
      head->left = tail;
      tail->right = head;
      return head;
    }

    Node* solution1core(Node* root) {
      if (!root) return nullptr;
      if (!root->left && !root->right) return root;  // 如果为叶子节点

      Node* left = root;

      // 获取排序后的左子树的最左点
      if (root->left) {
        left = solution1core(root->left);
        // 从left节点循环到最右节点
        Node* tmp = left;
        while (tmp->right) {
          tmp = tmp->right;
        }
        tmp->right = root;
        root->left = tmp;
      }

      // 获取排序后的右子树的最左点
      if (root->right) {
        Node* right = solution1core(root->right);
        root->right = right;
        right->left = root;
      }
      return left;
    }

    // 更简化一点的写法
    Node* solution2(Node* root) {
      if (!root) return nullptr;

      Node* linkList = nullptr;  // linkList 一直指向双向链表的尾节点
      solution2core(root, &linkList);
      // 返回头节点, 连接头尾节点
      Node* head = linkList;
      while (head && head->left)
        head = head->left;
      head->left = linkList;
      linkList->right = head;
      return head;
    }

    void solution2core(Node* root, Node** linkList) {
      if (!root) return;
      Node* current = root;

      if (current->left)
        solution2core(current->left, linkList);
      current->left = *linkList;
      if (*linkList != nullptr)
        (*linkList)->right = current;

      *linkList = current;
      if (current->right)
        solution2core(current->right, linkList);
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}