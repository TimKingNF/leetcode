//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上
//被小偷闯入，系统会自动报警。 
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。 
//
// 
//
// 示例 1： 
//
// 输入：[1,2,3,1]
//输出：4
//解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//     偷窃到的最高金额 = 1 + 3 = 4 。 
//
// 示例 2： 
//
// 输入：[2,7,9,3,1]
//输出：12
//解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 100 
// 0 <= nums[i] <= 400 
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode198 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int>& nums) {
      return solution1(nums);
    }

    int solution1(vector<int>& nums) {
      if (nums.empty()) return 0;
      int dp[2][2];  // 第一维表示第几间屋子，第二维表示下一间屋子是否会触动报警
      dp[0][0] = 0;
      dp[0][1] = nums[0];  // 表示偷了第一间屋子，下一间屋子会报警

      int ans = nums[0], x, y;
      for (int i = 1; i < nums.size(); ++i) {
        x = i % 2;
        y = (i-1) % 2;
        dp[x][1] = dp[y][0] + nums[i];  // 前一间屋子没偷 + 当前屋子的金额
        dp[x][0] = max(dp[y][1], dp[y][0]);  // 这一间都不偷
        ans = max(dp[x][1], dp[x][0]);
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}