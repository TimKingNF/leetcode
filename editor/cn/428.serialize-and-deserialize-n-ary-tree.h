//序列化是指将一个数据结构转化为位序列的过程，因此可以将其存储在文件中或内存缓冲区中，以便稍后在相同或不同的计算机环境中恢复结构。 
//
// 设计一个序列化和反序列化 N 叉树的算法。一个 N 叉树是指每个节点都有不超过 N 个孩子节点的有根树。序列化 / 反序列化算法的算法实现没有限制。你只需
//要保证 N 叉树可以被序列化为一个字符串并且该字符串可以被反序列化成原树结构即可。 
//
// 例如，你需要序列化下面的 3-叉 树。 
//
// 
//
// 
//
// 
//
// 为 [1 [3[5 6] 2 4]]。你不需要以这种形式完成，你可以自己创造和实现不同的方法。 
//
// 
//
// 注意： 
//
// 
// N 的范围在 [1, 1000] 
// 不要使用类成员 / 全局变量 / 静态变量来存储状态。你的序列化和反序列化算法应是无状态的。 
// 
// Related Topics 树

#include "header.h"

namespace LeetCode428 {

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
      return solution1_se(root);
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
      return solution1_de(data);
    }

    string solution1_se(Node* root) {
      if (!root) return "[]";
      ostringstream os;

      function<void(Node*)> dfs = [&](Node* node) {
        if (!node) return;
        os << node->val << ' ';
        if (node->children.size() > 0) {
          os.put('[');
          for (auto v : node->children) dfs(v);
          os << "] ";
        }
      };

      os.put('[');
      dfs(root);
      os.put(']');
      return os.str();
    }

    Node* solution1_de(string data) {
      int n = data.size();
      if (n == 0 || data == "[]") return nullptr;
      const string up_bracket = "[";

      stack<pair<int, void*>> stk;

      for (int i = 1; i < n-1; ++i) {  // 排除掉头尾 []
        if (data[i] == ' ') continue;
        else if (data[i] == '[') {
          stk.push({0, (void*) up_bracket.c_str()});
        } else if (isdigit(data[i])) {
          ostringstream os;
          os.put(data[i]);
          int size = 1;
          // 取到所有的数字
          while (i + 1 < n && isdigit(data[i+1])) {
            os.put(data[i+1]);
            ++i;
            ++size;
          }
          char* num = new char[size+1];
          os.str().copy(num, size);
          num[size] = '\0';
          stk.push({0, (void*) num});  // char* 转为 void*, 记下类型为 0
        } else {  // "]"
          // 从栈顶取出数据, 构造 vector
          vector<Node*> children;
          // 如果不是 Node* ，则需要 char* 判断不为 "["
          while (stk.top().first != 0 || ((char*) stk.top().second) != up_bracket.c_str()) {
            if (stk.top().first == 1) {
              children.push_back((Node*) stk.top().second);
            } else {
              children.push_back(new Node(stoi((char*) stk.top().second)));
            }
            stk.pop();
          }
          stk.pop();  // pop 掉 "[", 接下来是父节点
          // 要保证和原数组完全一样的话
          children = vector<Node*>(children.rbegin(), children.rend());
          Node* parent = new Node(stoi((char*) stk.top().second), children);
          stk.pop();  // pop 父节点字符串
          stk.push({1, (void*) parent});  // Node* 转为 void*, 记下类型为 1
        }
      }
      if (stk.top().first == 0) {  // 只有一个元素的时候
        return new Node(stoi((char*)stk.top().second));
      }
      return (Node*) stk.top().second;  // 最后一个元素一定是 root
    }

    string solution2_se(Node* root) {
      if (!root) return "";
      ostringstream os;
      os << root->val << '[';
      for (auto& child : root->children) {
        if (child) os << serialize(child);
      }
      os << ']';
      return os.str();
    }

    // 使用递归思想的简单做法
    Node* solution2_de(string data) {
      if (data.empty()) return nullptr;

      function<Node*(string&, int&)> dfs = [&](string& data, int& i) {
        int tmp = i;
        while (data[i++] != '[') {};  // 遍历 [ 位置
        Node* node = new Node(stoi(data.substr(tmp, i-tmp)));  // 根节点
        while (data[i] != ']') {
          node->children.push_back(dfs(data, i));
        }
        i++;  // 移动过 ]
        return node;
      };

      int i = 0;
      return dfs(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)

}