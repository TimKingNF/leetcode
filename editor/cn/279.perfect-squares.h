//给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。 
//
// 示例 1: 
//
// 输入: n = 12
//输出: 3 
//解释: 12 = 4 + 4 + 4. 
//
// 示例 2: 
//
// 输入: n = 13
//输出: 2
//解释: 13 = 4 + 9. 
// Related Topics 广度优先搜索 数学 动态规划

#include "header.h"

namespace LeetCode279 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSquares(int n) {
      return solution3(n);
    }

    // 动态规划
    // O(n * sqrt(n)), O(n)
    int solution1(int n) {
      int max_i = sqrt(n);
      vector<int> dp(n+1, INT32_MAX);  // 组成每个数的最优解
      dp[0] = 0;
      vector<int> square_nums(max_i+1, 0);
      for (int i = 1; i <= max_i; ++i) square_nums[i] = i * i;

      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= max_i; ++j) {
          if (i < square_nums[j]) break;
          dp[i] = min(dp[i], dp[i - square_nums[j]] + 1);
        }
      }
      return dp[n];
    }

    // 贪心法
    int solution2(int n) {
      int max_i = sqrt(n);
      set<int> square_nums;
      for (int i = 1; i <= max_i; ++i) square_nums.insert(i * i);

      // 表示 n 能否由count个数组成
      for (int count = 1; count <= n; ++count)
        if (is_divided_by(square_nums, n, count)) return count;
      return 0;
    }

    int is_divided_by(set<int>& square_nums, int n, int count) {
      if (count == 1) return square_nums.find(n) != square_nums.end();
      for (int v : square_nums) {
        if (is_divided_by(square_nums, n - v, count - 1)) return true;
      }
      return false;
    };

    // 数学
    // 四平方定理: 任何数都可以表示为4个整数平方之和, 故上界为4
    // 三平方定理：如果 n = 4^k(8m + 7), 则 n 不能被分解为3个平方和
    // 如果n不能被分解为3个平方和，则 n 自然也不能分解为两个平方和
    // 因为 n = a^2 + b^2 + 0^2 与三平方定理矛盾
    int solution3(int n) {
      // 如果n不能满足 三平方定理，则n只能被分解为4个
      int nn = n;
      while (!(nn & 3)) nn >>= 2;
      if ((nn & 7) == 7) return 4;

      auto is_square = [&](int x) {
        int i = sqrt(x);
        return i * i == x;
      };

      if (is_square(n)) return 1;  // 如果n是平方数
      // 判断n是否能被分解为两个数的平方
      int max_i = sqrt(n);
      for (int i = 1; i <= max_i; ++i)
        if (is_square(n - i * i)) return 2;

      return 3;  // 返回三平方定理的结果
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}