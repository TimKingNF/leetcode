//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 你的算法时间复杂度必须是 O(log n) 级别。 
//
// 如果数组中不存在目标值，返回 [-1, -1]。 
//
// 示例 1: 
//
// 输入: nums = [5,7,7,8,8,10], target = 8
//输出: [3,4] 
//
// 示例 2: 
//
// 输入: nums = [5,7,7,8,8,10], target = 6
//输出: [-1,-1] 
// Related Topics 数组 二分查找

#include "header.h"

namespace LeetCode34 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      return solution1(nums, target);
    }

    // 使用两次二分分别寻找上界和下界
    vector<int> solution1(vector<int>& nums, int target) {
      if (nums.empty()) return {-1, -1};
      int l = first(nums, target);
      if (l == -1) return {-1, -1};
      int r = last(nums, target);
      return {l, r};
    }

    int first(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1, middle;
      while (left <= right) {
        middle = (left + right) / 2;
        if (nums[middle] >= target)
          right = middle - 1;
        else
          left = middle + 1;
      }
      if (left >= nums.size() || nums[left] != target)
        return -1;
      return left;
    }

    int last(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1, middle;
      while (left <= right) {
        middle = (left + right) / 2;
        if (nums[middle] <= target)
          left = middle + 1;
        else
          right = middle - 1;
      }
      // 逼近到最后 left - right = 1, 且right就是元素的最后下界
      if (right < 0 || nums[left - 1] != target)
        return -1;
      return right;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}