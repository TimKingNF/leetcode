//把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。 
//
// 
//
// 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。 
//
// 
//
// 示例 1: 
//
// 输入: 1
//输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
// 
//
// 示例 2: 
//
// 输入: 2
//输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0
//.05556,0.02778] 
//
// 
//
// 限制： 
//
// 1 <= n <= 11 
//

#include "header.h"

namespace LeetCode_60 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<double> twoSum(int n) {
      return solution1(n);
    }

    // 使用 DP 递推
    // 每一轮的骰子和 n 应为上一轮骰子的 n-1, n-2, n-3, n-4, n-5, n-6 概率之和
    // 注意: 这里不能直接使用 概率相乘 的方式，否则会因为精度问题导致计算出错
    vector<double> solution1(int n) {
      if (n < 1) return {};
      int max_value = n * 6 + 1;
      // double v = 1.0 / 6;
      int dp[2][max_value];  // 第一维表示轮数，第二维表示骰子和
      // 给所有值赋初值
      for (int j = 0; j < max_value; ++j)
        dp[0][j] = dp[1][j] = 0;
      // 给第一维赋初值, 每个面出现的概率都为 1
      for (int i = 1; i <= 6; ++i) {
        dp[0][i] = 1;
      }

      int x, y;
      for (int i = 1; i < n; ++i) {  // i 记下来当前第几轮，用于计算当前一共多少个骰子, 骰子数量应为 i + 1
        x = i % 2;
        y = (i-1) % 2;
        // 赋初值
        for (int j = 0; j < max_value; ++j)
          dp[x][j] = 0;

        for (int k = i + 1; k <= (i+1) * 6; ++k) {  // 从骰子的最小和到最大和, i+1为当前的骰子数
          for (int j = 1; j <= 6 && j < k; ++j) {
            dp[x][k] += dp[y][k-j];  // 为上一轮的骰子的概率之和
          }
        }
      }
      vector<double> ans;
      auto tmp = n & 1 ? dp[0] : dp[1];
      double total = pow(6.0, n);
      for (int i = n; i < max_value; ++i)  // 从n开始 去掉头骰子的个数
        ans.push_back( double(tmp[i]) / total);
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}