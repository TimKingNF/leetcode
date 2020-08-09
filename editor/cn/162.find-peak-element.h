//峰值元素是指其值大于左右相邻值的元素。 
//
// 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。 
//
// 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。 
//
// 你可以假设 nums[-1] = nums[n] = -∞。 
//
// 示例 1: 
//
// 输入: nums = [1,2,3,1]
//输出: 2
//解释: 3 是峰值元素，你的函数应该返回其索引 2。 
//
// 示例 2: 
//
// 输入: nums = [1,2,1,3,5,6,4]
//输出: 1 或 5 
//解释: 你的函数可以返回索引 1，其峰值元素为 2；
//     或者返回索引 5， 其峰值元素为 6。
// 
//
// 说明: 
//
// 你的解法应该是 O(logN) 时间复杂度的。 
// Related Topics 数组 二分查找

#include "header.h"

namespace LeetCode162 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      return solution1(nums);
    }

    // 取中位数的元素，判断两边元素，如果是递增数组则向右找, 反之则向左找
    int solution1(vector<int>& nums) {
      if (nums.empty()) return -1;
      int n = nums.size();
      if (n == 1) return 0;
      int left = 0, right = n - 1, middle, left_val, right_val;
      while (left < right) {
        if (right - left == 1) return nums[left] < nums[right] ? right : left;
        middle = left + (right - left) / 2;
        left_val = middle - 1 >= 0 ? nums[middle - 1] : INT_MIN;
        right_val = middle + 1 < n ? nums[middle + 1] : INT_MIN;

        if (left_val < nums[middle] && nums[middle] > right_val) return middle;
        else if (left_val <= nums[middle] && nums[middle] <= right_val) left = middle;  // 递增数组
        else right = middle;
      }
      return -1;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}