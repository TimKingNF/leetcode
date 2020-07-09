//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？ 
//
// 注意：本题相对书上原题稍作改动 
//
// 示例 1： 
//
// 输入：[3,0,1]
//输出：2 
//
// 
//
// 示例 2： 
//
// 输入：[9,6,4,2,3,5,7,0,1]
//输出：8
// 
// Related Topics 位运算 数组 数学

#include "header.h"

namespace LeetCode_17_04 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      return solution2(nums);
    }

    int solution1(vector<int>& nums) {
      int n = nums.size();
      int sum = 0;
      for (int v : nums) sum += v;
      return n * (n + 1) / 2 - sum;
    }

    // 从0到n 进行异或
    int solution2(vector<int>& nums) {
      int ans = 0, n = nums.size();
      for (int i = 0; i < n; ++i) {
        ans ^= i ^ nums[i];
      }
      return ans ^ n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}