//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 示例: 
//
// 输入: [-2,1,-3,4,-1,2,1,-5,4],
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 
//
// 进阶: 
//
// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。 
// Related Topics 数组 分治算法 动态规划

#include "header.h"

namespace LeetCode53 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      return solution2(nums);
    }

    // 动态规划, O(n)
    int solution1(vector<int>& nums) {
      if (nums.empty()) return 0;
      int dp[2];
      dp[0] = nums[0];
      int res = nums[0];

      int x, y;  // x: n, y: n-1
      for (int i = 1; i < nums.size(); ++i) {
        x = i % 2;
        y = (i-1) % 2;
        dp[x] = max(dp[y]+nums[i], nums[i]);  // 只有两种情况，加元素；就本项
        res = max(dp[x], res);
      }
      return res;
    }

   private:
    struct Status {
      int lSum;
      int rSum;
      int mSum;  // 最大连续段之和
      int iSum;  // 区间总和
    };

    Status merge(Status l, Status r) {
      int iSum = l.iSum + r.iSum;
      int lSum = max(l.lSum, l.iSum + r.lSum);
      int rSum = max(r.rSum, l.rSum + r.iSum);
      int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
      return (Status) {lSum, rSum, mSum, iSum};
    }

    Status get(vector<int>& nums, int l, int r) {
      if (l == r) return (Status) {nums[l], nums[l], nums[l], nums[l]};  // 只有一个元素
      int m = (l + r) >> 1;
      Status lSub = get(nums, l, m);
      Status rSub = get(nums, m+1, r);
      return merge(lSub, rSub);  // 归并
    }

    // 分治
    int solution2(vector<int>& nums) {
      return get(nums, 0, nums.size()-1).mSum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}