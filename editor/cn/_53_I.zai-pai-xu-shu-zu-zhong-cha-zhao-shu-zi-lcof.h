//统计一个数字在排序数组中出现的次数。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [5,7,7,8,8,10], target = 8
//输出: 2 
//
// 示例 2: 
//
// 输入: nums = [5,7,7,8,8,10], target = 6
//输出: 0 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
//
// 
//
// 注意：本题与主站 34 题相同（仅返回值不同）：https://leetcode-cn.com/problems/find-first-and-last-
//position-of-element-in-sorted-array/ 
// Related Topics 数组 二分查找

#include "header.h"

namespace LeetCode_53_I {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO
    int search(vector<int>& nums, int target) {
      return solution3(nums, target);
    }

    int solution1(vector<int>& nums, int target) {
      int len = nums.size();
      if (len == 0) return 0;
      int left = 0, right = len - 1, middle, find = -1, ans = 1;

      while (left <= right) {
        middle = (left + right) / 2;
        if (nums[middle] == target) {
          find = middle;
          break;
        } else if (nums[middle] > target) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      }
      if (find == -1) return 0;

      left = right = 1;
      // 前后寻找, 极端情况如全部都相等的元素，则会退化为 O(N)
      while (find - left >= 0 && nums[find - left] == target) {
        ++left;
        ++ans;
      }
      while (find + right < len && nums[find + right] == target) {
        ++right;
        ++ans;
      }
      return ans;
    }

    int solution2(vector<int>& nums, int target) {
      if (nums.empty()) return 0;
      int l = first(nums, target);
      if (l == -1) return 0;
      int r = last(nums, target);
      return r - l + 1;
    }

    int first(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1, middle;
      while (left <= right) {
        middle = (left + right) / 2;
        if (nums[middle] == target)
          right = middle - 1;  //  让left逼近第一个元素
        else if (nums[middle] > target)
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
        if (nums[middle] == target)
          left = middle + 1;  // 让 right 逼近最后一个元素
        else if (nums[middle] > target)
          right = middle - 1;
        else
          left = middle + 1;
      }
      if (right < 0 || nums[left - 1] != target)
        return -1;
      return right;
    }

    int solution3(vector<int>& nums, int target) {
      return findRight(nums, target) - findRight(nums, target - 1);
    }

    int findRight(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1, middle;
      while (left <= right) {
        middle = (left + right) / 2;
        if (nums[middle] <= target)
          left = middle + 1;
        else
          right = right - 1;
      }
      return left;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}