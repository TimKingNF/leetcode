//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一
//格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但
//它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？ 
//
// 
//
// 示例 1： 
//
// 输入：m = 2, n = 3, k = 1
//输出：3
// 
//
// 示例 2： 
//
// 输入：m = 3, n = 1, k = 0
//输出：1
// 
//
// 提示： 
//
// 
// 1 <= n,m <= 100 
// 0 <= k <= 20 
// 
//

#include "header.h"

namespace LeetCode_13 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int movingCount(int m, int n, int k) {
      return solution1(m, n, k);
    }

    // 常规解法，dfs
    int solution1(int m, int n, int k) {
      int ans = 0;
      // 创建一个矩阵是否走过
      vector<bool> tracks(m * n);
      solution1core(m, n, k, 0, 0, tracks, &ans);
      return ans;
    }

    void solution1core(int m, int n, int k, int r, int c, vector<bool>& tracks, int *ans) {
      int index = r * n + c;
      // 判断当前的格子是否能走
      if (r < 0 || r >= m || c < 0 || c >= n || tracks[index]) return;
      if (r / 100 + r / 10 % 10 + r % 10 + c / 100 + c / 10 % 10 + c % 10 > k) return;
      (*ans) += 1;  // 说明当前格子能走
      tracks[index] = true;
      solution1core(m, n, k, r - 1, c, tracks, ans);  // 上
      solution1core(m, n, k, r + 1, c, tracks, ans);  // 下
      solution1core(m, n, k, r, c - 1, tracks, ans);  // 左
      solution1core(m, n, k, r, c + 1, tracks, ans);  // 右
      // 无需还原 记录已经走过即可
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}