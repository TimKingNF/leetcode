//给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。 
//
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下： 
//
// 
// "123" 
// "132" 
// "213" 
// "231" 
// "312" 
// "321" 
// 
//
// 给定 n 和 k，返回第 k 个排列。 
//
// 说明： 
//
// 
// 给定 n 的范围是 [1, 9]。 
// 给定 k 的范围是[1, n!]。 
// 
//
// 示例 1: 
//
// 输入: n = 3, k = 3
//输出: "213"
// 
//
// 示例 2: 
//
// 输入: n = 4, k = 9
//输出: "2314"
// 
// Related Topics 数学 回溯算法

#include "header.h"

namespace LeetCode60 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  vector<int> factorial = {1,1,2,6,24,120,720,5040,40320};
public:
    string getPermutation(int n, int k) {
      return solution1(n, k);
    }

    string solution1(int n, int k) {
      vector<int> nums(n, 0);
      iota(nums.begin(), nums.end(), 1);  // 累加
      --k;  // 第k个排列，其下标应为 k-1
      string ans;
      for (int i = n - 1; i != -1; --i) {
        auto it = begin(nums) + k / factorial[i];
        ans += to_string(*it);
        nums.erase(it);
        k %= factorial[i];
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}