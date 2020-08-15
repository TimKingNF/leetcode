//给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[
//l] = 0。 
//
// 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最
//终结果不会超过 231 - 1 。 
//
// 例如: 
//
// 
//输入:
//A = [ 1, 2]
//B = [-2,-1]
//C = [-1, 2]
//D = [ 0, 2]
//
//输出:
//2
//
//解释:
//两个元组如下:
//1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
//2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
// 
// Related Topics 哈希表 二分查找

#include "header.h"

namespace LeetCode454 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      return solution2(A, B, C, D);
    }

    // O(N^2)
    // 由于只需要记录数量，所以简写一下，可以修改 unordered_map 的 value type 为 int
    int solution1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      unordered_map<int, vector<pair<int, int>>> dict;  // key 是 AB之和，pair 分别为 AB的下标
      int len = A.size();
      int ans = 0;
      for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
          int sum = A[i] + B[j];
          if (dict.count(sum))
            dict[sum].push_back({i, j});
          else
            dict[sum] = vector<pair<int, int>>{{i, j}};
        }
      }
      for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
          int target = -C[i] - D[j];
          if (dict.count(target)) {
            ans += dict[target].size();
          }
        }
      }
      return ans;
    }

    int solution2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      unordered_map<int, int> dict;
      int len = A.size();
      int ans = 0;
      for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
          ++dict[A[i] + B[j]];
        }
      }
      for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
          int target = -C[i] - D[j];
          if (dict.count(target)) ans += dict[target];
        }
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}