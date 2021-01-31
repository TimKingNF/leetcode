//给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。 
//
// 示例 1: 
//
// 
//输入: [1,2,3]
//输出: 6
// 
//
// 示例 2: 
//
// 
//输入: [1,2,3,4]
//输出: 24
// 
//
// 注意: 
//
// 
// 给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。 
// 输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。 
// 
// Related Topics 数组 数学

#include "header.h"

namespace LeetCode628 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
      return solution1(nums);
    }

    int solution1(vector<int>& nums) {
      // 最大的三数相乘， 或者最小的两数相乘再乘以最大的数
      int first_num, second_num, third_num, reverse_first_num, reverse_second_num;
      first_num = second_num = third_num = -1000;
      reverse_first_num = reverse_second_num = 1000;
      for (auto num : nums) {
        if (num > first_num) {
          third_num = second_num;
          second_num = first_num;
          first_num = num;
        } else if (num > second_num) {
          third_num = second_num;
          second_num = num;
        } else if (num > third_num) {
          third_num = num;
        }

        if (num < reverse_first_num) {
          reverse_second_num = reverse_first_num;
          reverse_first_num = num;
        } else if (num < reverse_second_num) {
          reverse_second_num = num;
        }
      }
      return max(first_num * second_num * third_num, reverse_first_num * reverse_second_num * first_num);
    }

    int solution2(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      // 两负一正 和 最大3个 比较
      return max(nums[0] * nums[1] * nums[n-1], nums[n-1] * nums[n-2] * nums[n-3]);
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}

