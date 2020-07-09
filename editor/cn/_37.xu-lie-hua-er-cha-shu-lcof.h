//请实现两个函数，分别用来序列化和反序列化二叉树。 
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
// 注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-b
//inary-tree/ 
// Related Topics 树 设计

#include "header.h"

namespace LeetCode_37 {

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
class solution1 {
 public:
  static string serialize(TreeNode* root) {
    if (!root) return "";
    deque<TreeNode*> q;
    q.push_back(root);
    string ans = to_string(root->val) + ',';
    TreeNode* pop;
    int nullCount = 0;
    while (!q.empty()) {
      pop = q.front();
      q.pop_front();
      if (pop->left) {
        ans += to_string(pop->left->val) + ',';
        q.push_back(pop->left);
        nullCount = 0;
      } else {
        ans += "null,";
        ++nullCount;
      }
      if (pop->right) {
        ans += to_string(pop->right->val) + ',';
        q.push_back(pop->right);
        nullCount = 0;
      } else {
        ans += "null,";
        ++nullCount;
      }
    }
    // 消除末端所有的 null,
    return '[' + ans.substr(0, ans.size()-nullCount*5-1) + ']';
  }

  static TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;
    // 先split
    deque<string> splitData;
    int i, pre;
    for (i = 1, pre = 1; i < data.size()-1; ++i) {  // 去掉头尾的 [ ]
      if (data[i] == ',') {
        splitData.push_back(data.substr(pre, i-pre));
        pre = i+1;
      }
    }
    splitData.push_back(data.substr(pre, data.size()-pre-1));
    if (splitData[0] == "null") return nullptr;
    // split 完成之后开始构造
    TreeNode* head = new TreeNode(stoi(splitData[0]));
    TreeNode* ans = head;
    splitData.pop_front();
    deque<TreeNode*> tmp;
    tmp.push_back(head);
    string tmpString;
    int flag = 0;
    while (!splitData.empty()) {
      head = tmp.front();
      tmpString = splitData.front();
      splitData.pop_front();
      if (!flag) {
        if (tmpString != "null") {
          head->left = new TreeNode(stoi(tmpString));
          tmp.push_back(head->left);
        }
        ++flag;
      } else {
        if (tmpString != "null") {
          head->right = new TreeNode(stoi(tmpString));
          tmp.push_back(head->right);
        }
        flag = 0;
        tmp.pop_front();  // 弹出head
      }
    }
    return ans;
  }
};

class solution2 {
 public:
  static string serialize(TreeNode* root) {
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
      } else
        if (curNum) out << "null,";
    }
    string ans = out.str();
    ans = ans.substr(0, ans.size()-1);
    return '[' + ans + ']';
  }

  static TreeNode* deserialize(string data) {
    istringstream input(data.substr(1, data.size()-2));
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      return solution2::serialize(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      return solution2::deserialize(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)

}