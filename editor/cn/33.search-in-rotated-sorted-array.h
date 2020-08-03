//假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
//
// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。 
//
// 你可以假设数组中不存在重复的元素。 
//
// 你的算法时间复杂度必须是 O(log n) 级别。 
//
// 示例 1: 
//
// 输入: nums = [4,5,6,7,0,1,2], target = 0
//输出: 4
// 
//
// 示例 2: 
//
// 输入: nums = [4,5,6,7,0,1,2], target = 3
//输出: -1 
// Related Topics 数组 二分查找

#include "header.h"

namespace LeetCode33 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int search(vector<int>& nums, int target) {
      return solution2(nums, target);
    }

    // 先找最小值，然后再从局部区间中找 target
    // O(2 logN) = O(logN)
    int solution1(vector<int>& nums, int target) {
      if (nums.empty()) return -1;
      int left = 0, right = nums.size() - 1;
      int min_index = left, middle;
      while (nums[right] < nums[left]) {  // 不满足此条件说明是升序
        if (right - left == 1) {
          min_index = right;
          break;
        }
        middle = left + (right - left) / 2;
        if (nums[middle] >= nums[right]) left = middle;
        else right = middle;
      }
      // 求得最小值与索引之后，判读 target 的位置
      left = 0;
      right = nums.size() - 1;
      if (target <= nums[right]) left = min_index;
      else right = min_index - 1;
      while (left <= right) {
        middle = left + (right - left) / 2;
        if (nums[middle] == target) return middle;
        else if (nums[middle] > target) right = middle - 1;
        else left = middle + 1;
      }
      return -1;
    }

    // 判断左右两部分哪一步分是有序的，并不断修改上界和下界的值
    int solution2(vector<int>& nums, int target) {
      if (nums.empty()) return -1;
      int n = nums.size(), left = 0, right = n - 1, middle;
      while (left <= right) {
        middle = left + (right - left) / 2;
        if (nums[middle] == target) return middle;
        // 判断 0,middle 是否升序
        if (nums[0] <= nums[middle]) {
          if (nums[0] <= target && target < nums[middle]) right = middle - 1;
          else left = middle + 1;
        } else {
          if (nums[middle] < target && target <= nums[n-1]) left = middle + 1;
          else right = middle - 1;
        }
      }
      return -1;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}