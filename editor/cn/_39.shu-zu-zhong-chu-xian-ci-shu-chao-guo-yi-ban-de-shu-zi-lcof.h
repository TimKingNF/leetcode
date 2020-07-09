//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。 
//
// 
//
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。 
//
// 
//
// 示例 1: 
//
// 输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
//输出: 2 
//
// 
//
// 限制： 
//
// 1 <= 数组长度 <= 50000 
//
// 
//
// 注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/ 
//
// 
// Related Topics 位运算 分治算法

#include "header.h"

namespace LeetCode_39 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      return solution1(nums);
    }

    // solution1 排序之后在中位数的元素, O(N logN)
    int solution1(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      return nums[nums.size() / 2];
    }

    // solution2 用候选数的方式, O(N)
    int solution2(vector<int>& nums) {
      int count = 0, candidate;
      for (auto v : nums) {
        if (count == 0) candidate = v;
        if (v == candidate) ++count;
        else --count;
      }
      return candidate;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}