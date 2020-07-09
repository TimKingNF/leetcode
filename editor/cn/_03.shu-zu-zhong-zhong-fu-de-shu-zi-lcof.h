//找出数组中重复的数字。 
//
// 
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请
//找出数组中任意一个重复的数字。 
//
// 示例 1： 
//
// 输入：
//[2, 3, 1, 0, 2, 5, 3]
//输出：2 或 3 
// 
//
// 
//
// 限制： 
//
// 2 <= n <= 100000 
// Related Topics 数组 哈希表

#include "header.h"

namespace LeetCode_03 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
      return solution3(nums);
    }

    // solution1 直接排序

    // solution2 利用一个 int[n] 大小的数组当作哈希表

    // O(N) 在原地进行交换，每个数都等于其下标，如果有重复的数，说明有的下标没有值
    int solution3(vector<int>& nums) {
      for (int i = 0; i < nums.size(); ++i) {
        while (nums[i] != i) {  // 只要当前数不与自己的下标一致，就再次执行交换
          // 判断是否与下标为该数的数相等
          if (nums[i] == nums[nums[i]]) return nums[i];
          // 与下标为该数的数进行交换位置
          swap(nums[i], nums[nums[i]]);
        }
      }
      return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}