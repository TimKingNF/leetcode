//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [3,4,3,3]
//输出：4
// 
//
// 示例 2： 
//
// 输入：nums = [9,1,7,9,7,9,7]
//输出：1 
//
// 
//
// 限制： 
//
// 
// 1 <= nums.length <= 10000 
// 1 <= nums[i] < 2^31 
// 
//
// 
//

#include "header.h"

namespace LeetCode_56_II {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      return solution2(nums);
    }

    // 使用hash表, O(N) 常数为32 O(N)
    int solution1(vector<int>& nums) {
      unordered_map<int, int> m(nums.size());
      for (int num : nums)
        m[num] += 1;
      for (auto v : m) {
        if (v.second == 1)
          return v.first;
      }
      return -1;
    }

    // 所有数字的二进制对应每一位的1都加起来，对于只出现一次的数字来说
    // 能够被3整除的为必为0，不能被3整除的为1
    // O(N) O(1)
    int solution2(vector<int>& nums) {
      int tmp[32] = {0};
      uint x;
      for (int num : nums) {
        x = 1;
        for (int j = 31; j >= 0; --j) {
          if (num & x)
            tmp[j] += 1;
          x = x << 1;
        }
      }
      uint ans = 0;
      for (int i : tmp) {
        ans = ans << 1;
        ans += i % 3;
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}