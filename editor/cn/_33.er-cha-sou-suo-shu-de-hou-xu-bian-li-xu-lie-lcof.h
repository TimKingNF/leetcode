//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。 
//
// 
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
// 输入: [1,6,3,2,5]
//输出: false 
//
// 示例 2： 
//
// 输入: [1,3,2,6,5]
//输出: true 
//
// 
//
// 提示： 
//
// 
// 数组长度 <= 1000 
// 
//

#include "header.h"

namespace LeetCode_33 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
      return solution1(postorder);
    }

    bool solution1(vector<int>& postorder) {
      return solution1core(postorder, 0, postorder.size() - 1);
    }

    bool solution1core(vector<int>& postorder, int start, int end) {
      if (postorder.empty() || start >= end) return true;
      // 依照二叉搜索树的性质，后序遍历中最后一个元素为根节点，前面左子树的元素都比根节点小，后面右子树的元素都比根节点大
      int root = postorder[end];
      // 遍历 postorder 找到第一个比根节点大的元素
      int i, split_index;
      for (i = start; i <= end; ++i) {
        if (postorder[i] >= root)
          break;
      }
      split_index = i;
      // 后续的所有元素应当都大于root, 直到等于root时停止
      while (i <= end && postorder[i] > root) {
        ++i;
      }
      if (i != end)
        return false;
      // 判断左子树是否是二叉搜索树
      // 判断右子树是否是二叉搜索树
      return solution1core(postorder, start, split_index-1) && solution1core(postorder, split_index, end-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}