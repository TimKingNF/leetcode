//数组中占比超过一半的元素称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回-1。 
//
// 示例 1： 
//
// 输入：[1,2,5,9,5,9,5,5,5]
//输出：5 
//
// 
//
// 示例 2： 
//
// 输入：[3,2]
//输出：-1 
//
// 
//
// 示例 3： 
//
// 输入：[2,2,1,1,1,2,2]
//输出：2 
//
// 
//
// 说明： 
//你有办法在时间复杂度为 O(N)，空间复杂度为 O(1) 内完成吗？ 
// Related Topics 位运算 数组 分治算法

#include "header.h"

namespace LeetCode_17_10 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      return solution1(nums);
    }

    // 候选数
    int solution1(vector<int>& nums) {
      int count = 0, candidate;
      for (int i : nums) {
        if (count == 0) candidate = i;
        if (i == candidate) ++count;
        else --count;
      }
      // 因为不一定存在 众数，所以还需要判断一遍
      count = 0;
      for (int i : nums) {
        if (i == candidate) ++count;
      }
      return count <= nums.size() / 2 ? -1 : candidate;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}