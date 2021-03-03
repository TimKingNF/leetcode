//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？ 
//
// 示例: 
//
// 输入: 3
//输出: 5
//解释:
//给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3 
// Related Topics 树 动态规划

#include "header.h"

namespace LeetCode96 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numTrees(int n) {
      return solution1(n);
    }

    int solution1(int n) {
      int G[n+1];
      G[0] = 1;
      G[1] = 1;
      for (int i = 2; i <= n; ++i) {
        G[i] = 0;
        for (int j = 1; j <= i; ++j) {  // 以某个j为头结点
          // 这里J指的是以J为根节点，其数量和为 左子树 G[j-1] * 右子树 G[i-j]
          G[i] += G[j - 1] * G[i-j];
        }
      }
      return G[n];
    }

    // 数学，上述推导的公式符合 卡塔兰数，有公式
    int solution2(int n) {
      long C = 1;
      for (int i = 0; i < n; ++i)
        C = C * 2 * (2 * i + 1) / (i + 2);
      return (int) C;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

}