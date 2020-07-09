//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。 
//
// 
//
// 示例： 
//
// 输入：nums = [1,2,3,4]
//输出：[1,3,2,4]
//注：[3,1,2,4] 也是正确的答案之一。 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 50000 
// 1 <= nums[i] <= 10000 
// 
//

#include "header.h"

namespace LeetCode_21 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
      return solution2(nums);
    }

    // 双指针
    vector<int> solution1(vector<int>& nums) {
      int i = 0, j = nums.size() - 1;
      while (i < j) {
        // 找到偶数
        while (i < j && (nums[i] & 1))
          ++i;
        // 找到奇数
        while (i < j && !(nums[j] & 1))
          --j;
        if (i < j)
          swap(nums[i], nums[j]);
      }
      return nums;
    }

    // 快慢指针
    vector<int> solution2(vector<int>& nums) {
      for (int i = 0, slow = 0; i < nums.size(); ++i) {
        if (nums[i] & 1)
          swap(nums[i], nums[slow++]);
      }
      return nums;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}