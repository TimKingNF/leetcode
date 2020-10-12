//给定一个无序的整数数组，找到其中最长上升子序列的长度。 
//
// 示例: 
//
// 输入: [10,9,2,5,3,7,101,18]
//输出: 4 
//解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。 
//
// 说明: 
//
// 
// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。 
// 你算法的时间复杂度应该为 O(n2) 。 
// 
//
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗? 
// Related Topics 二分查找 动态规划

#include "header.h"

namespace LeetCode300 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      return solution2(nums);
    }

    // dp
    // O( N^2 )
    int solution1(vector<int>& nums) {
      if (nums.empty()) return 0;
      int n = nums.size(), ans = 0;
      int dp[n];
      fill(dp, dp+n, 1);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
      }
      return ans;
    }

    // 动态规划二分
    // 新建数组 cell，用于保存最长上升子序列。(该序列严格递增，但不一定是正确的顺序，和在原数组中的顺序无关)
    // 对原序列进行遍历，将每位元素二分插入 cell 中。
    // 1. 如果 cell 中元素都比它小，将它插到最后
    // 2. 否则，用它覆盖掉比它大的元素中最小的那个。
    // 只有当新加入的元素都大于所有元素，才会扩充 cell 长度，即满足最长上升子序列
    int solution2(vector<int>& nums) {
      vector<int> cell(nums.size(), 0);
      int ans = 0;
      for (int num : nums) {
        int i = 0, j = ans;  // j 为当前 cell 的长度
        while (i < j) {
          int mid = (i + j) / 2;
          if (cell[mid] < num) i = mid + 1;
          else j = mid;
        }
        cell[i] = num;
        if (j == ans) ++ans;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}