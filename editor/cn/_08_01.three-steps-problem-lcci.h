//三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模100
//0000007。 
//
// 示例1: 
//
// 
// 输入：n = 3 
// 输出：4
// 说明: 有四种走法
// 
//
// 示例2: 
//
// 
// 输入：n = 5
// 输出：13
// 
//
// 提示: 
//
// 
// n范围在[1, 1000000]之间 
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode_08_01 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int waysToStep(int n) {
      return solution1(n);
    }

    // dp
    int solution1(int n) {
      unsigned int dp[4] = {0, 1, 2, 4};
      int mod = 1000000007;
      for (int i = 4; i <= n; ++i) {
        dp[i%4] = (dp[(i-1)%4] + (dp[(i-2)%4] + dp[(i-3)%4]) % mod) % mod;
      }
      return dp[n % 4];
    }

    // 变种: 相邻的步数不能相同
    // dp
    int waysToDiffStep(int n) {
      int mod = 1000000007;
      int dp[4][3];  // 第一维表示步数%4, 第二维表示上一步走的步数, 0 表示1步，1 表示2步
      // 构建初值
      dp[0][0] = dp[0][1] = dp[0][2] = 0;
      dp[1][0] = 1; dp[1][1] = 0; dp[1][2] = 0;
      dp[2][0] = 0; dp[2][1] = 1; dp[2][2] = 0;
      dp[3][0] = 1; dp[3][1] = 1; dp[3][2] = 1;
      for (int i = 4; i <= n; ++i) {
        int x = i % 4, y = (i-1) % 4, z = (i-2) % 4, k = (i-3) % 4;
        dp[x][0] = (dp[y][1] + dp[y][2]) % mod;  // 由 i-1 级台阶，走 1 步上来
        dp[x][1] = (dp[z][0] + dp[z][2]) % mod;  // 由 i-2 级台阶，走 2 步上来
        dp[x][2] = (dp[k][0] + dp[k][1]) % mod;  // 由 i-3 级台阶，走 3 步上来
      }
      int key = n % 4;
      return dp[key][0] + dp[key][1] + dp[key][2];
    }


    // 变种：相邻的步数不能相同，打印步伐
    // dfs
    vector<vector<int>> printWaysToDiffStep(int n) {
      vector<int> path;
      vector<vector<int>> steps;
      _dfs(n, 0, path, steps);
      return steps;
    }

    void _dfs(int n, int prev, vector<int> path, vector<vector<int>>& steps) {
      if (n == 0) {
        steps.push_back(path);
        return;
      }
      for (int step = 1; step <= 3; ++step) {  // 3种步数
        if (n >= step && step != prev) {
          path.push_back(step);
          _dfs(n - step, step, path, steps);
        }
      }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}