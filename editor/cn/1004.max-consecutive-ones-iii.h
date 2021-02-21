//给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。 
//
// 返回仅包含 1 的最长（连续）子数组的长度。 
//
// 
//
// 示例 1： 
//
// 输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
//输出：6
//解释： 
//[1,1,1,0,0,1,1,1,1,1,1]
//粗体数字从 0 翻转到 1，最长的子数组长度为 6。 
//
// 示例 2： 
//
// 输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
//输出：10
//解释：
//[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
//粗体数字从 0 翻转到 1，最长的子数组长度为 10。 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 20000 
// 0 <= K <= A.length 
// A[i] 为 0 或 1 
// 
// Related Topics 双指针 Sliding Window 
// 👍 189 👎 0

#include "header.h"

namespace LeetCode1004 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
      return solution1(A, K);
    }

    int solution1(vector<int>& A, int K) {
      int ans = 0;
      int n = A.size();
      int cost = K;

      int left = 0, right = 0;
      while (right < n) {
        if (A[right] == 0 && !cost) {
          // 回收 cost，且 cost 不能大于 K
          if (A[left] == 0) cost = cost + 1 >= K ? K : cost + 1;
          ++left;
          if (left > right) right = left;  // 调整, right 必须大于等于 left
          continue;  // right - left 距离减少。可以不用考虑
        } else if (A[right] == 0 && cost) {
          --cost;  // 由 0 变 1，cost 减少
        }
        ans = max(ans, right - left + 1);
        ++right;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}