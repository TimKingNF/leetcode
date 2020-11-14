//给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。 
//区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。 
//
// 说明: 
//最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。 
//
// 示例: 
//
// 输入: nums = [-2,5,-1], lower = -2, upper = 2,
//输出: 3 
//解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。
// 
// Related Topics 排序 树状数组 线段树 二分查找 分治算法 
// 👍 142 👎 0

#include "header.h"

namespace LeetCode327 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
      return solution1(nums, lower, upper);
    }

    // 归并并排序
    // O( NlogN ), O( N )
    int solution1(vector<int>& nums, int lower, int upper) {
      if (nums.empty()) return 0;
      long s = 0;
      vector<long> sum{0};  // 计算得前缀和数组，则有 sum[j] - sum[i] 是 nums[i-1] - nums[j-1] 的长度
      for (int v : nums) {
        s += v;
        sum.push_back(s);
      }
      return solution1core(sum, lower, upper, 0, sum.size()-1);
    }

    int solution1core(vector<long>& sum, int lower, int upper, int left, int right) {
      if (left == right) return 0;  // left 和 right 相同，没有意义

      int m = (left + right) / 2;
      int n1 = solution1core(sum, lower, upper, left, m);  // 同时 sum[left, m] 数据已经被排序好
      int n2 = solution1core(sum, lower, upper, m+1, right);
      int ret = n1 + n2;  // 这里先分别计算左边区间 和右边区间满足的数量

      // 合并计算，从左边区间的每个数出发到右边区间的每个数 满足条件的数量
      // 这里因为已经排序好，所以首先移动 l, 直到满足 sum[l] - sum[i] (最左端点) >= lower
      // 则 l 之后的元素都满足 >= lower
      int i = left;
      int l = m + 1, r = l;
      while (i <= m) {
        // 计算从 left 开始，在右端区间中满足 区间和 范围的 l 和 r
        while (l <= right && sum[l] - sum[i] < lower) l++;
        while (r <= right && sum[r] - sum[i] <= upper) r++;
        ret += (r - l);
        ++i;  // 继续计算新的起点
      }

      // 合并两个排序数组
      vector<int> sorted(right - left + 1);
      int p1 = left, p2 = m + 1;
      int k = 0;
      while (p1 <= m || p2 <= right) {
        if (p1 > m) {
          sorted[k++] = sum[p2++];  // 说明 左边数组已经取完
        } else if (p2 > right) {
          sorted[k++] = sum[p1++];  // 说明 右边数据已经取完
        } else {
          if (sum[p1] > sum[p2]) sorted[k++] = sum[p2++];
          else sorted[k++] = sum[p1++];
        }
      }

      // 重新拷贝回 sorted
      for (i = 0; i < sorted.size(); ++i) sum[left + i] = sorted[i];
      return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}