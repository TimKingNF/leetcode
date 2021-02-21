//给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。 
//
// （例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。） 
//
// 返回 A 中好子数组的数目。 
//
// 
//
// 示例 1： 
//
// 输入：A = [1,2,1,2,3], K = 2
//输出：7
//解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
// 
//
// 示例 2： 
//
// 输入：A = [1,2,1,3,4], K = 3
//输出：3
//解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 20000 
// 1 <= A[i] <= A.length 
// 1 <= K <= A.length 
// 
// Related Topics 哈希表 双指针 Sliding Window 
// 👍 196 👎 0

#include "header.h"

namespace LeetCode992 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
      return solution1(A, K);
    }

    int solution1(vector<int>& A, int K) {
      auto atMostDistinct = [&](int n) {
        unordered_map<int, int> mp;
        int left = 0, right = 0, ret = 0;
        while (right < A.size()) {
          ++mp[A[right++]];
          while (mp.size() > n) {
            --mp[A[left]];
            if (mp[A[left]] == 0) mp.erase(A[left]);
            ++left;
          }
          // 新增的子数组数
          // Eg. 当满足条件的子数组从 [A,B,C] 增加到 [A,B,C,D] 时，新子数组的长度为 4，
          //     同时增加的子数组为 [D], [C,D], [B,C,D], [A,B,C,D] 也为4。
          ret += right - left;
        }
        return ret;
      };
      // 最多包含 K 个 - 最多包含 K - 1 个  = 恰好有 K 个
      return atMostDistinct(K) - atMostDistinct(K - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}