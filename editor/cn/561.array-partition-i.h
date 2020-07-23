//给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 
//的 min(ai, bi) 总和最大。 
//
// 示例 1: 
//
// 
//输入: [1,4,3,2]
//
//输出: 4
//解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
// 
//
// 提示: 
//
// 
// n 是正整数,范围在 [1, 10000]. 
// 数组中的元素范围在 [-10000, 10000]. 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode561 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
      return solution2(nums);
    }

    // O(N * logN + N)
    int solution1(vector<int>& nums) {
      // 要使总min最大，则先排序，然后根据下标%2=0 去和
      sort(nums.begin(), nums.end());

      int res = 0;
      for (int i = 0; i < nums.size(); i += 2) {
        res += nums[i];
      }
      return res;
    }

    int solution2(vector<int>& nums) {
      int hash[20001] = { 0 };
      for (int num : nums)
        hash[num + 10000] += 1;
      int ans = 0;
      bool flag = true;
      for (int i = 0; i <= 20000; ++i) {  // 由小到大开始
        while (hash[i] > 0) {
          if (flag) ans += i - 10000;  // 算上第1，3，5...个数，如果有
          flag = !flag;  // 跳过下一个数
          --hash[i];
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}