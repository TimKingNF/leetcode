//一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出
//这个数字。 
//
// 
//
// 示例 1: 
//
// 输入: [0,1,3]
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [0,1,2,3,4,5,6,7,9]
//输出: 8 
//
// 
//
// 限制： 
//
// 1 <= 数组长度 <= 10000 
// Related Topics 数组 二分查找

#include "header.h"

namespace LeetCode_53_II {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      return solution1(nums);
    }

    int solution1(vector<int>& nums) {
      int left = 0, right = nums.size() - 1, middle;
      while (left <= right) {
        middle = (left + right) / 2;
        if (middle == nums[middle])
          left = middle + 1;
        else {
          if (middle == 0 || nums[middle-1] == middle - 1)
            return middle;
          right = middle - 1;
        }
      }
      if (left == nums.size())
        return left;
      return -1;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}