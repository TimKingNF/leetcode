//给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。 
//
// 示例 1: 
//
// 输入: [3,0,1]
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [9,6,4,2,3,5,7,0,1]
//输出: 8
// 
//
// 说明: 
//你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现? 
// Related Topics 位运算 数组 数学

#include "header.h"

namespace LeetCode268 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      return solution2(nums);
    }

    int solution1(vector<int>& nums) {
      // n_sum 一定比nums_sum多出一个数字，差值刚好是nums缺失的数字
      int len = nums.size(), nums_sum = 0, n_sum = (len + 1) * len / 2;
      for (int i = 0; i < len; ++i) {
        nums_sum += nums[i];
      }
      return n_sum - nums_sum;
    }

    // 取 两相同数异或为0 的原则
    int solution2(vector<int>& nums) {
      int num = nums.size();
      for (int i = 0; i < nums.size(); ++i)
      {
        num ^= i ^ nums[i];
      }
      return num;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}