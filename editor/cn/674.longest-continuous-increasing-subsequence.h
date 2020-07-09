//给定一个未经排序的整数数组，找到最长且连续的的递增序列。 
//
// 示例 1: 
//
// 
//输入: [1,3,5,4,7]
//输出: 3
//解释: 最长连续递增序列是 [1,3,5], 长度为3。
//尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
// 
//
// 示例 2: 
//
// 
//输入: [2,2,2,2,2]
//输出: 1
//解释: 最长连续递增序列是 [2], 长度为1。
// 
//
// 注意：数组长度不会超过10000。 
// Related Topics 数组

#include "header.h"

namespace LeetCode674 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
      return solution3(nums);
    }

    // O(N) dp
    int solution1(vector<int>& nums) {
      if (nums.size() <= 1) return nums.size();

      int dp[2];  // key记录天数， val记录包含自己在内的最大长度
      dp[0] = 1;

      int x, y, res = 0;
      for (int i = 1; i < nums.size(); ++i) {
        x = i % 2;
        y = (i-1) % 2;
        if (nums[i] > nums[i-1])
          dp[x] = dp[y] + 1;
        else
          dp[x] = 1;
        res = max(res, dp[x]);
      }
      return res;
    }

    int solution2(vector<int>& nums) {
      int len = nums.size();
      if (len <= 1)  return len;

      int res = 0;
      int temp = 1;
      for (int i = 1; i < len; ++i)
      {
        if (nums[i] > nums[i-1])
          temp++;
        else
          temp=1;
        res = max(res, temp);
      }
      return res;
    }

    // 滑动窗口
    int solution3(vector<int>& nums) {
       int ans = 0, anchor = 0;  // anchor 表示一个连续递增序列的起始位置
       for (int i = 0; i < nums.size(); ++i) {
         if (i > 0 && nums[i-1] >= nums[i])
           anchor = i;  // 重置起始位置
         ans = max(ans, i - anchor + 1);  // 每次循环都计算
       }
       return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}