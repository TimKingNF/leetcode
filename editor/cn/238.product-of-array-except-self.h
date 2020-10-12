//给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之
//外其余各元素的乘积。 
//
// 
//
// 示例: 
//
// 输入: [1,2,3,4]
//输出: [24,12,8,6] 
//
// 
//
// 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。 
//
// 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。 
//
// 进阶： 
//你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。） 
// Related Topics 数组

#include "header.h"

namespace LeetCode238 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      return solution2(nums);
    }

    vector<int> solution1(vector<int>& nums) {
      if (nums.empty()) return {};
      int n = nums.size();
      // 第一遍先逆向乘过去
      vector<int> ans(n, 1);
      ans[n-1] = nums[n-1];
      for (int i = n-2; i >= 0; --i) {
        ans[i] = nums[i] * ans[i+1];
      }
      // 第二遍正向乘回来
      ans[0] = ans[1];
      int tmp = nums[0];
      for (int i = 1; i < n-1; ++i) {
        ans[i] = tmp * ans[i+1];
        tmp *= nums[i];
      }
      ans[n-1] = tmp;  // 补上最后一个元素
      return ans;
    }

    // 更精简的代码
    vector<int> solution2(vector<int>& nums) {
      if (nums.empty()) return {};
      int n = nums.size();
      vector<int> ans(n, 1);
      int tmp = 1;
      for (int i = 0; i < n - 1; ++i)
        ans[i+1] = tmp *= nums[i];
      tmp = 1;
      for (int i = n - 2; i >= 0; --i)
        ans[i] *= tmp *= nums[i+1];
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}