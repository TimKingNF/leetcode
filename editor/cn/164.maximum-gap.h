//给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。 
//
// 如果数组元素个数小于 2，则返回 0。 
//
// 示例 1: 
//
// 输入: [3,6,9,1]
//输出: 3
//解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。 
//
// 示例 2: 
//
// 输入: [10]
//输出: 0
//解释: 数组元素个数小于 2，因此返回 0。 
//
// 说明: 
//
// 
// 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。 
// 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。 
// 
// Related Topics 排序 
// 👍 240 👎 0

#include "header.h"

namespace LeetCode164 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
      return solution2(nums);
    }

    // 使用基数排序
    // O( N ), O( N )
    int solution1(vector<int>& nums) {
      int n = nums.size();
      if (n < 2) return 0;

      int exp = 1;  // 指数
      vector<int> buf(n);
      int maxVal = *max_element(nums.begin(), nums.end());

      while (maxVal >= exp) {
        vector<int> cnt(10);  // 0 - 9
        for (int i = 0; i < n; ++i) {
          int digit = (nums[i] / exp) % 10;  // 取个位数的值
          cnt[digit]++;
        }
        // 计算每个位数的结束位置
        for (int i = 1; i < 10; ++i) cnt[i] += cnt[i-1];

        for (int i = n - 1; i >= 0; --i) {
          int digit = (nums[i] / exp) % 10;
          buf[--cnt[digit]] = nums[i];  // 按个位数倒序插入
        }
        copy(buf.begin(), buf.end(), nums.begin());
        exp *= 10;
      }

      int ans = 0;
      for (int i = 1; i < n; ++i) ans = max(ans, nums[i] - nums[i-1]);
      return ans;
    }

    // 桶排序
    int solution2(vector<int>& nums) {
      int n = nums.size();
      if (n < 2) return 0;
      int minVal = *min_element(nums.begin(), nums.end());
      int maxVal = *max_element(nums.begin(), nums.end());
      int d = max(1, (maxVal - minVal) / (n-1));  // 间距的单位最大值
      int bucketSize = (maxVal - minVal) / d + 1;

      // 桶内记录最大值和最小值, 桶内最大值和最小值间距不超过d，我们需要计算桶与桶相隔最大距离
      vector<pair<int, int>> bucket(bucketSize, {-1, -1});
      for (int i = 0; i < n; ++i) {
        int idx = (nums[i] - minVal) / d;
        if (bucket[idx].first == -1) {
          bucket[idx].first = bucket[idx].second = nums[i];
        } else {
          bucket[idx].first = min(bucket[idx].first, nums[i]);
          bucket[idx].second = max(bucket[idx].second, nums[i]);
        }
      }

      int ans = 0;
      int prev = -1;
      for (int i = 0; i < bucketSize; ++i) {
        if (bucket[i].first == -1) continue;  // 桶内没有数据
        if (prev != -1) ans = max(ans, bucket[i].first - bucket[prev].second);  // 和上一个桶的最大间距
        prev = i;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}