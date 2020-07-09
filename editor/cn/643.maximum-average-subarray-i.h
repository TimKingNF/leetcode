//给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。 
//
// 示例 1: 
//
// 输入: [1,12,-5,-6,50,3], k = 4
//输出: 12.75
//解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
// 
//
// 
//
// 注意: 
//
// 
// 1 <= k <= n <= 30,000。 
// 所给数据范围 [-10,000，10,000]。 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode643 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      return solution2(nums, k);
    }

    double solution1(vector<int>& nums, int k) {
      double res = INT_MIN, sum;
      for (int i = k - 1; i < nums.size(); ++i) {
        sum = 0;
        for (int j = 0; j < k; ++j) {
          sum += nums[i-k+j+1];
        }
        res = max(res, sum);
      }
      return res / k;
    }

    double solution2(vector<int>& nums, int k) {
      double sum = 0;
      for (int i = 0; i < k; ++i)
        sum += nums[i];

      double max_sum = sum;
      for (int i = k; i < nums.size(); ++i) {
        sum += nums[i] - nums[i-k];
        max_sum = max(sum, max_sum);
      }
      return max_sum / k;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}