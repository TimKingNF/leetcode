//给定一个整数数组，你需要验证它是否是一个二叉搜索树正确的先序遍历序列。 
//
// 你可以假定该序列中的数都是不相同的。 
//
// 参考以下这颗二叉搜索树： 
//
//      5
//    / \
//   2   6
//  / \
// 1   3 
//
// 示例 1： 
//
// 输入: [5,2,6,1,3]
//输出: false 
//
// 示例 2： 
//
// 输入: [5,2,1,3,6]
//输出: true 
//
// 进阶挑战： 
//
// 您能否使用恒定的空间复杂度来完成此题？ 
// Related Topics 栈 树 
// 👍 78 👎 0

#include "header.h"

namespace LeetCode255 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
      return solution2(preorder);
    }

    // 递归, 会超时
    // O( N^2 ), O( h )
    bool solution1(vector<int>& preorder) {
      if (preorder.empty()) return true;
      return isPre(preorder, 0, preorder.size()-1);
    }

    bool isPre(vector<int>& preorder, int start, int end) {
      if (start >= end) return true;
      int head = preorder[start];
      int less = start + 1;
      while (less <= end && preorder[less] < head) ++less;
      // 从 less 开始，如果出现比 head 小的数，则直接返回 false
      for (int i = less; i <= end; ++i) {
        if (preorder[i] < head) return false;
      }
      return isPre(preorder, start+1, less-1) &&
             isPre(preorder, less, end);
    }

    // 利用单调栈解
    bool solution2(vector<int>& preorder) {
      // minV 记录当前一个节点的父节点的最小值 ( 考虑右子树时 )
      int k = -1, minV = INT32_MIN;
      for (auto val : preorder) {
        if (val < minV) return false;  // 在当前最小值之后，如果遇到一个值比其大，说明不是 BST
        // 如果当前节点的值比栈顶元素大，则将栈内所有小于 当前节点值的元素 移除
        while (k >= 0 && preorder[k] < val) minV = preorder[k--];
        // 节点值比栈顶元素小，入栈, 此时 minV 是当前节点的父节点
        preorder[++k] = val;  // 使用原数组模拟栈，优化内存
      }
      return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}