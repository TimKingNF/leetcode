//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。 
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串
//反序列化为原始的树结构。 
//
// 示例: 
//
// 你可以将以下二叉树：
//
//    1
//   / \
//  2   3
//     / \
//    4   5
//
//序列化为 "[1,2,3,null,null,4,5]" 
//
// 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这
//个问题。 
//
// 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。 
// Related Topics 树 设计

#include "header.h"

namespace LeetCode297 {

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
    // TODO

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      ostringstream out;  // 使用 ostream 代替 string
      deque<TreeNode*> q;
      q.push_back(root);
      TreeNode* tmp;
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
      ans = ans.substr(0, ans.size()-1);
      return '[' + ans + ']';
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      istringstream input(data.substr(1, data.size()-2));  // 去掉 []
      string val;
      vector<TreeNode*> vec;
      while (getline(input, val, ',')) {
        if (val == "null")
          vec.push_back(nullptr);
        else
          vec.push_back(new TreeNode(stoi(val)));
      }
      // 构造成二叉树
      int j = 1;  // i每往后移动一位，j就移动两位
      for (int i = 0; j < vec.size(); ++i) {  // j先到达边界
        if (vec[i] == nullptr) continue;
        vec[i]->left = vec[j++];
        if (j < vec.size()) vec[i]->right = vec[j++];
      }
      return vec[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)

}