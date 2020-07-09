//给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。 
//
// 我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。 
//
// 如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。 
//
// 示例 1: 
//
// 
//输入: 
//nums = [1, 7, 3, 6, 5, 6]
//输出: 3
//解释: 
//索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
//同时, 3 也是第一个符合要求的中心索引。
// 
//
// 示例 2: 
//
// 
//输入: 
//nums = [1, 2, 3]
//输出: -1
//解释: 
//数组中不存在满足此条件的中心索引。 
//
// 说明: 
//
// 
// nums 的长度范围为 [0, 10000]。 
// 任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode724 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      return solution2(nums);
    }

    int solution1(vector<int>& nums) {
      // 头尾指针遍历, 需要遍历到刚好 i = j 的时候，两边和相等
      int len = nums.size();
      if (len < 1) return -1;

      int left_sum = 0, right_sum = 0;
      // 记录从第一个元素起右边所有元素之和
      for (int i = 1; i < len; ++i)
        right_sum += nums[i];

      // 从第一个元素开始遍历，直到倒数第二个，left_sum + nums[i], right_sum - nums[i]
      for (int i = 0; i < len - 1; ++i) {
        if (left_sum == right_sum) return i;
        left_sum += nums[i];
        right_sum -= nums[i+1];
      }
      // 判断最后一个元素是否为中心索引
      if (left_sum == right_sum)
        return len -1;
      return -1;
    }

    int solution2(vector<int>& nums) {
      int sum = 0, left_sum = 0;
      for (auto num : nums)
        sum += num;

      for (int i = 0; i < nums.size(); ++i) {
        if (left_sum == sum - left_sum - nums[i])
          return i;
        left_sum += nums[i];
      }
      return -1;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}