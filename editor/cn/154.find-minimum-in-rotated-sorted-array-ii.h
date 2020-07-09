//假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
//
// 请找出其中最小的元素。 
//
// 注意数组中可能存在重复的元素。 
//
// 示例 1： 
//
// 输入: [1,3,5]
//输出: 1 
//
// 示例 2： 
//
// 输入: [2,2,2,0,1]
//输出: 0 
//
// 说明： 
//
// 
// 这道题是 寻找旋转排序数组中的最小值 的延伸题目。 
// 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？ 
// 
// Related Topics 数组 二分查找

#include "header.h"

namespace LeetCode154 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMin(vector<int>& nums) {
      return solution2(nums);
    }

    int solution1(vector<int>& nums) {
      int left = 0, right = nums.size() - 1;
      if (right == 0) return nums[right];

      int middle = left;
      while (nums[left] >= nums[right]) {  // 如果 nums[left] < nums[right] 说明是有序数组
        if (right - left == 1)
          return nums[right];

        middle = (left + right) / 2;
        if (nums[middle] == nums[right] && nums[middle] == nums[left]) {
          // 这种情况下无从知道如何确定下一步二分的范围，故只能顺序查找
          int res = INT_MAX;
          for (int i = left; i < right; ++i) {
            if (nums[i] < res) res = nums[i];
          }
          return res;
        }

        if (nums[middle] >= nums[left]) {
          left = middle;
        } else if (nums[middle] <= nums[right]) {
          right = middle;
        }
      }
      return nums[middle];
    }

    int solution2(vector<int>& nums) {
      int n = nums.size();
      while (n > 0 && nums[n - 1] == nums[0]) {
        --n;
      }
      int l = -1, r = n, m;
      while (r - l > 1) {
        m = (r + l) / 2;
        if (nums[m] >= nums[0]) {
          l = m;
        } else {
          r = m;
        }
      }
      return r == n ? nums[0] : nums[r];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}