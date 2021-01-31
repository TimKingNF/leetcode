//给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 个数字拼接
//成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。 
//
// 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。 
//
// 说明: 请尽可能地优化你算法的时间和空间复杂度。 
//
// 示例 1: 
//
// 输入:
//nums1 = [3, 4, 6, 5]
//nums2 = [9, 1, 2, 5, 8, 3]
//k = 5
//输出:
//[9, 8, 6, 5, 3] 
//
// 示例 2: 
//
// 输入:
//nums1 = [6, 7]
//nums2 = [6, 0, 4]
//k = 5
//输出:
//[6, 7, 6, 0, 4] 
//
// 示例 3: 
//
// 输入:
//nums1 = [3, 9]
//nums2 = [8, 9]
//k = 3
//输出:
//[9, 8, 9] 
// Related Topics 贪心算法 动态规划 
// 👍 211 👎 0

#include "header.h"

namespace LeetCode321 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
      return solution1(nums1, nums2, k);
    }

    vector<int> solution1(vector<int>& nums1, vector<int>& nums2, int k) {
      int n = nums1.size(), m = nums2.size();
      vector<int> maxSubsequence(k, 0);
      int start = max(0, k - m), end = min(k, n);
      for (int i = start; i <= end; ++i) {
        // nums1 最少要取几个，到 nums1 最多可以取几个
        vector<int> subsequence1(MaxSubsequence(nums1, i));
        vector<int> subsequence2(MaxSubsequence(nums2, k-i));
        vector<int> curMaxSubsequence(merge(subsequence1, subsequence2));
        if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) {
          maxSubsequence.swap(curMaxSubsequence);
        }
      }
      return maxSubsequence;
    }

    // 在 nums 数组中取 k 个数返回最大值，同时要保持相对位置
    // 利用单调栈获得子序列
    vector<int> MaxSubsequence(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> stk(k, 0);
      int top = -1;
      int remain = n - k;
      for (int i = 0; i < n; ++i) {
        int num = nums[i];
        while (top >= 0 && stk[top] < num && remain > 0) {
          top--;
          remain--;
        }
        if (top < k - 1) {
          stk[++top] = num;  // 直接拼接上当前数
        } else {
          remain--;
        }
      }
      return stk;
    }

    vector<int> merge(vector<int>& subseq1, vector<int>& subseq2) {
      int x = subseq1.size(), y = subseq2.size();
      if (x == 0) return subseq2;
      if (y == 0) return subseq1;
      int mergeLength = x + y;
      vector<int> ans(mergeLength);
      int i = 0, j = 0;
      for (int k = 0; k < mergeLength; ++k) {
        if (compare(subseq1, i, subseq2, j) > 0) {
          ans[k] = subseq1[i++];
        } else {
          ans[k] = subseq2[j++];
        }
      }
      return ans;
    }

    int compare(vector<int>& seq1, int i, vector<int>& seq2, int j) {
      int x = seq1.size(), y = seq2.size();
      while (i < x && j < y) {
        int diff = seq1[i] - seq2[j];
        if (diff != 0) return diff;  // 哪个大取哪个
        i++;
        j++;
      }
      return (x - i) - (y - j);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}