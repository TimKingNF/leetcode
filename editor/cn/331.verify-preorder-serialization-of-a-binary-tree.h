//序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。 
//
//      _9_
//    /   \
//   3     2
//  / \   / \
// 4   1  #  6
/// \ / \   / \
//# # # #   # #
// 
//
// 例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。 
//
// 给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。 
//
// 每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。 
//
// 你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。 
//
// 示例 1: 
//
// 输入: "9,3,4,#,#,1,#,#,2,#,6,#,#"
//输出: true 
//
// 示例 2: 
//
// 输入: "1,#"
//输出: false
// 
//
// 示例 3: 
//
// 输入: "9,#,#,1"
//输出: false 
// Related Topics 栈 
// 👍 193 👎 0

#include "header.h"

namespace LeetCode331 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValidSerialization(string preorder) {
      return solution1(preorder);
    }

    bool solution1(string &preorder) {
      if (preorder.empty()) return false;

      stack<pair<bool, bool>> stk;
      int i = 0, n = preorder.size();
      bool digit;

      for (; i < n; ++i) {
        if (preorder[i] == ',') continue;
        digit = false;  // #

        if (isdigit(preorder[i])) {
          while (i+1 < n && isdigit(preorder[i+1])) ++i;
          digit = true;
        }

        if (stk.empty()) {
          if (digit) stk.push({false, false});
          else stk.push({true, true});  // 写入一个表示空节点的节点
        } else if (!stk.top().first) {  // 左孩子不存在
          stk.top().first = true;
          if (digit) stk.push({false, false});  // push 一个新节点
        } else if (!stk.top().second) {  // 右孩子不存在
          stk.top().second = true;  // 不管是数字还是 #
          if (digit) stk.push({false, false});
        }

        while (!stk.empty() && stk.top().first && stk.top().second) {
          stk.pop();
          if (stk.empty()) return i == n-1;  // 一旦为空了就返回
        }
      }
      return stk.empty() && i == n;  // 栈为空，且已经遍历到最后
    }

    // 也能使用递归做
};
//leetcode submit region end(Prohibit modification and deletion)

}