//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。 
//
// 说明： 
//
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？ 
//
// 示例 1: 
//
// 输入: [2,2,3,2]
//输出: 3
// 
//
// 示例 2: 
//
// 输入: [0,1,0,1,0,1,99]
//输出: 99 
// Related Topics 位运算

#include "header.h"

namespace LeetCode137 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      return solution1(nums);
    }

    // hash 计数，略过

    // 所以数字的二进制上每一个位的1加起来，能被 3 整除，记为0，不能为1，最后的数即为ans
    int solution1(vector<int>& nums) {
      int tmp[32] = {0};
      uint x = 1;
      for (int i = 31; i >= 0; --i) {
        for (int v : nums) {
          if (v & x) ++tmp[i];
        }
        x <<= 1;
      }
      uint ans = 0;
      for (int v : tmp) {
        ans <<= 1;
        ans += v % 3;
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}