//给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。 
//
// 两棵树重复是指它们具有相同的结构以及相同的结点值。 
//
// 示例 1： 
//
//         1
//       / \
//      2   3
//     /   / \
//    4   2   4
//       /
//      4
// 
//
// 下面是两个重复的子树： 
//
//       2
//     /
//    4
// 
//
// 和 
//
//     4
// 
//
// 因此，你需要以列表的形式返回上述重复子树的根结点。 
// Related Topics 树

#include "header.h"

namespace LeetCode652 {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      return solution2(root);
    }

    // 遇到链表形式且值全部相同的二叉树时，会重复比较，导致超时
    // 遍历所有节点，将具有相同的值的 TreeNode 记录在一个数组中
    vector<TreeNode*> solution1(TreeNode* root) {
      if (!root) return {};
      deque<TreeNode*> q{root};
      set<TreeNode*> ans;
      map<int, vector<TreeNode*>> dict;
      while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop_front();
        auto find = dict.find(cur->val);
        if (find != dict.end()) {  // 存在相同的val的 TreeNode*
          bool flag = false;
          for (auto v = find->second.begin(); v != find->second.end(); ++v) {
            if (sameOfTree(cur, *v)) {  // 如果树相同
              ans.insert(*v);  // 插入在链表内的值，并利用set去重
              flag = true;
              break;
            }
          }
          // 如果同样的val树不一样, 则追加进去
          if (!flag) find->second.push_back(cur);
        } else {
          dict[cur->val] = vector<TreeNode*>{cur};
        }
        // bfs
        if (cur->left) q.push_back(cur->left);
        if (cur->right) q.push_back(cur->right);
      }
      return vector<TreeNode*>{ans.begin(), ans.end()};
    }

    bool sameOfTree(TreeNode* first, TreeNode* second) {
      if (!first && !second) return true;
      if ((!first && second) || (first && !second)) return false;
      if (first->val != second->val) return false;
      return sameOfTree(first->left, second->left) &&
             sameOfTree(first->right, second->right);
    }

    // 利用序列化来做键
    vector<TreeNode*> solution2(TreeNode* root) {
      if (!root) return {};
      unordered_map<string, TreeNode*> dict;
      deque<TreeNode*> q{root};
      set<TreeNode*> ans;
      while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop_front();
        string key = treeSerialize(cur);
        auto find = dict.find(key);
        if (find != dict.end()) {
          ans.insert(find->second);
        } else dict[key] = cur;
        // bfs
        if (cur->left) q.push_back(cur->left);
        if (cur->right) q.push_back(cur->right);
      }
      return vector<TreeNode*>(ans.begin(), ans.end());
    }

    template<typename T>
    string treeSerialize(T* root) {
      ostringstream out;  // 使用 ostream 代替 string
      deque<T*> q;
      q.push_back(root);
      T* tmp;
      int curNum = 1;  // 用该变量记录实际的元素
      while (!q.empty()) {
        tmp = q.front();
        q.pop_front();
        if (tmp) {
          out << tmp->val << ',';
          --curNum;
          q.push_back(tmp->left);
          if (tmp->left) ++curNum;
          q.push_back(tmp->right);
          if (tmp->right) ++curNum;
        } else if (curNum) out << "null,";
      }
      string ans = out.str();
      return ans.substr(0, ans.size()-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}