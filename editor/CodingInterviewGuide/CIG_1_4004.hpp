//
// Created by timking.nf@foxmail.com on 2021/2/28.
//

#ifndef LEETCODE_CIG_1_4004_HPP
#define LEETCODE_CIG_1_4004_HPP

#include "header.h"

namespace CIG_1_4004 {

class Solution {
 public:
  int minCoins(vector<int>& arr, int aim) {
    return solution2(arr, aim);
  }

  // DP
  int solution1(vector<int>& arr, int aim) {
    if (arr.empty() || aim <= 0)  return 0;

    int n = arr.size();
    int MAX = INT32_MAX;

    // dp[i][j] 在使用 arr[0...i] 张货币的情况下，组成 j 需要的最少张数
    vector<vector<int>> dp(n, vector<int>(aim+1, 0));

    // base
    for (int j = 1; j <= aim; ++j) dp[0][j] = MAX;
    if (arr[0] <= aim) dp[0][arr[0]] = 1;  // 构成第一张为 1

    int leftup = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= aim; ++j) {
        leftup = MAX;
        // 本次使用的金额是 arr[i], 那么要从 dp[i-1] 中来推
        if (j - arr[i] >= 0 && dp[i-1][j-arr[i]] != MAX) {
          leftup = dp[i-1][j-arr[i]] + 1;  // 加上 arr[i] 这一张
        }
        dp[i][j] = min(leftup, dp[i-1][j]);  // 和不增加 arr[i] 相比
      }
    }
    return dp[n-1][aim] != MAX ? dp[n-1][aim] : -1;
  }

  // DP 空间优化
  int solution2(vector<int>& arr, int aim) {
    if (arr.empty() || aim <= 0)  return 0;

    int n = arr.size();
    int MAX = INT32_MAX;
    int dp[aim+1];

    // base
    fill(dp, dp+aim+1, INT32_MAX);
    dp[0] = 0;
    if (arr[0] <= aim) dp[arr[0]] = 1;

    int leftup = 0;
    for (int i = 1; i < n; ++i) {
      // 不能从正着推的原因是，避免 arr[i] 被多次使用
      // 正着推可能导致 x, x+arr[i], x+arr[i]+arr[i] ... 原来 x+arr[i] 可能不存在值,
      // 导致错误的推算了 x+arr[i]+arr[i]
      for (int j = aim; j > 0; --j) {
        leftup = MAX;
        if (j - arr[i] >= 0 && dp[j-arr[i]] != MAX) {
          leftup = dp[j-arr[i]] + 1;
        }
        dp[j] = min(leftup, dp[j]);
      }
    }
    return dp[aim] != MAX ? dp[aim] : -1;
  }
};

}

#endif  // LEETCODE_CIG_1_4004_HPP
