//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。 
//
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。 
//
// 必须原地修改，只允许使用额外常数空间。 
//
// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。 
//1,2,3 → 1,3,2 
//3,2,1 → 1,2,3 
//1,1,5 → 1,5,1 
// Related Topics 数组 
// 👍 766 👎 0

#include "header.h"

namespace LeetCode31 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      return solution1(nums);
    }

    // TODO
    // 1. 从后向前查找第一个相邻升序的元素对 (i,j)，满足 nums[i] < nums[j]。此时 [j,end) 必然是降序
    // 2. 在 [j,end) 从后向前查找第一个满足 nums[i] < nums[k] 的 k。
    // 3. 交换 nums[i] 和 nums[k], 此时 [j, end) 任是降序
    // 4. 倒置 [j,end] 让其升序
    // 1.2 如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，则直接跳到步骤 4
    void solution1(vector<int>& nums) {
      int n = nums.size();
      if (n <= 1) return;

      int i = n-2, j = n-1, k = n-1;

      // find: nums[i] < nums[j]
      while (i >= 0 && nums[i] >= nums[j]) {
        i--;
        j--;
      }

      if (i >= 0) {  // 说明不是完全递减
        // find: nums[i] < nums[k]
        while (nums[i] >= nums[k]) k--;
        swap(nums[i], nums[k]);
      }

      reverse(nums.begin()+j, nums.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}