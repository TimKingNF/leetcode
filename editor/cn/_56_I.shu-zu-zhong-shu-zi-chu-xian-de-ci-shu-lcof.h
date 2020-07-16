//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [4,1,4,6]
//输出：[1,6] 或 [6,1]
// 
//
// 示例 2： 
//
// 输入：nums = [1,2,10,4,1,4,3,3]
//输出：[2,10] 或 [10,2] 
//
// 
//
// 限制： 
//
// 
// 2 <= nums.length <= 10000 
// 
//
// 
//

#include "header.h"

namespace LeetCode_56_I {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
      return solution1(nums);
    }

    // 问题在于如何将数组分解为两个 各含有单个元素，并相同元素在一起的数组
    // 可以通过 整体异或之后的结果，求得其最低位为 1 的位置 x
    // 然后通过对所有元素 x 位置为 1 和 x 位置为 0 的规则进行分组，即可求出不同的元素
    // 时间复杂度为 O(2N) = O(N)
    vector<int> solution1(vector<int>& nums) {
      int v = 0;
      for (auto num : nums)
        v ^= num;
      // 求得最低位为1的位置
      int x = v & -v;
      vector<int> ans(2, 0);
      for (auto num: nums) {
        if (num & x) ans[0] ^= num;
        else ans[1] ^= num;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}