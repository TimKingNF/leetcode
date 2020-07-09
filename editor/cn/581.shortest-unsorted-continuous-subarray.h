//给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。 
//
// 你找到的子数组应是最短的，请输出它的长度。 
//
// 示例 1: 
//
// 
//输入: [2, 6, 4, 8, 10, 9, 15]
//输出: 5
//解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
// 
//
// 说明 : 
//
// 
// 输入的数组长度范围在 [1, 10,000]。 
// 输入的数组可能包含重复元素 ，所以升序的意思是<=。 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode581 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      return solution1(nums);
    }

    // TODO: 后续再做一次
    int solution1(vector<int>& nums) {
      // 问题转化为，找左右连续的最大长度, 并要保证连续的最小值和最大值
      if (nums.empty()) return 0;
      int l = 0;
      int r = 0;
      int minNum = nums[nums.size() - 1];
      for (int i = nums.size() - 1; i >= 0; i--)  // 从右往左找最大值
      {
        l = (nums[i] > minNum) ? i : l;
        minNum = min(minNum, nums[i]);
      }
      int maxNum = nums[0];
      for (int i = 0; i < nums.size(); i++)  // 从左往右找最小值
      {
        r = (nums[i] < maxNum) ? i : r;
        maxNum = max(maxNum, nums[i]);
      }
      return (r > l) ? r - l + 1 : 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}