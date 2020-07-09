//输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [2,7,11,15], target = 9
//输出：[2,7] 或者 [7,2]
// 
//
// 示例 2： 
//
// 输入：nums = [10,26,30,31,47,60], target = 40
//输出：[10,30] 或者 [30,10]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= nums.length <= 10^5 
// 1 <= nums[i] <= 10^6 
// 
//

#include "header.h"

namespace LeetCode_57 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      return solution2(nums, target);
    }

    // 使用hash存储
    vector<int> solution1(vector<int>& nums, int target) {
      unordered_set<int> tmp;
      for (int num : nums) {
        if (tmp.find(target - num) != tmp.end())
          return {target-num, num};
        tmp.insert(num);
      }
      return {-1, -1};
    }

    // 利用排序的性质, 双指针解法。 O(N)
    vector<int> solution2(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1;
      int sum;
      while (left < right) {
        sum = nums[left] + nums[right];
        if (sum > target)
          right--;
        else if (sum < target)
          left++;
        else
          return {nums[left], nums[right]};
      }
      return {-1, -1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}