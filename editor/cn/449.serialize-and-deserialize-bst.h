//序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。 
//
// 设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序
//列化为最初的二叉搜索树。 
//
// 编码的字符串应尽可能紧凑。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [2,1,3]
//输出：[2,1,3]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数范围是 [0, 104] 
// 0 <= Node.val <= 104 
// 题目数据 保证 输入的树是一棵二叉搜索树。 
// 
//
// 
//
// 注意：不要使用类成员/全局/静态变量来存储状态。 你的序列化和反序列化算法应该是无状态的。 
// Related Topics 树 
// 👍 157 👎 0

#include "header.h"

namespace LeetCode449 {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      // 直接前序遍历
      ostringstream os;
      stack<TreeNode*> stk;
      while (!stk.empty() || root) {
        while (root) {
          stk.push(root);
          os << root->val << ",";
          root = root->left;
        }
        root = stk.top();
        stk.pop();
        root = root->right;
      }
      auto oss = os.str();
      if (oss.empty()) return oss;
      return oss.substr(0, oss.size()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      if (data.empty()) return nullptr;
      vector<int> preorder, inorder;
      string v;
      istringstream input(data);
      // 读取字符串，刚好就是前序遍历的结果
      while (getline(input, v, ',')) {
        preorder.push_back(stoi(v));
      }
      inorder.resize(preorder.size());
      copy(preorder.begin(), preorder.end(), inorder.begin());
      sort(inorder.begin(), inorder.end());  // 排序之后即为中序遍历的结果

      // 根据前序遍历和中序遍历构造树
      return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder, int pre_start, int pre_end,
                        vector<int>& inorder, int in_start, int in_end) {
      if (pre_start > pre_end || in_start > in_end) return nullptr;
      TreeNode* root = new TreeNode(preorder[pre_start]);
      // 找到 preorder[pre_start] 在 inorder[in_start:in_end] 之前的下标
      auto f = find(inorder.begin() + in_start, inorder.begin() + in_end, preorder[pre_start]);
      auto leftItems = f - inorder.begin() - in_start - 1;  // 左子树的元素个数
      root->left = buildTree(preorder, pre_start + 1, pre_start + 1 + leftItems,
                             inorder, in_start, in_start + leftItems);
      root->right = buildTree(preorder, pre_start + leftItems + 2, pre_end,
                              inorder, in_start + leftItems + 2, in_end);
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
//leetcode submit region end(Prohibit modification and deletion)

}