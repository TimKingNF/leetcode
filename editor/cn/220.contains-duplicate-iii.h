//在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的
//绝对值也小于等于 ķ 。 
//
// 如果存在则返回 true，不存在返回 false。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,2,3,1], k = 3, t = 0
//输出: true 
//
// 示例 2: 
//
// 输入: nums = [1,0,1,1], k = 1, t = 2
//输出: true 
//
// 示例 3: 
//
// 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
//输出: false 
// Related Topics 排序 Ordered Map

#include "header.h"

namespace LeetCode220 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      return solution3(nums, k, t);
    }

    // O(Kn) 极端情况 O(n^2)
    bool solution1(vector<int>& nums, int k, int t) {
      int n = nums.size();
      for (int i = 0; i < n; ++i) {
        for (int idx = i + 1; idx < min(i + k + 1, n); ++idx) {
          if (abs((long) nums[i] - nums[idx]) <= t) return true;
        }
      }
      return false;
    }

    // 桶排序
    // O(N) O(min(n,k))
    bool solution2(vector<int>& nums, int k, int t) {
      if (t < 0) return false;
      long mod = t + 1L;
      unordered_map<long, long> bucket;
      for (int i = 0; i < nums.size(); ++i) {
        long nth = nums[i] / mod;
        if (nums[i] < 0) --nth;  // 当nums[i] 为负数时，nth 区分于0，需要记为 -1
        if (bucket.count(nth)) return true;  // 这样保证在同一个桶内的数据相差 t
        // 在相邻的桶，元素之间存在也可能存在差值满足 <= t
        // 因为在桶与桶之间，桶的最大值和下一个桶的最小值 相差为1，所以还需要检查相邻的桶
        if (bucket.count(nth - 1) && abs(bucket[nth-1] - nums[i]) <= t) return true;
        if (bucket.count(nth + 1) && abs(bucket[nth+1] - nums[i]) <= t) return true;
        bucket[nth] = nums[i];
        if (i >= k) bucket.erase(nums[i - k] / mod);  // 移除第一个桶
      }
      return false;
    }

    // 二叉搜索树
    // O(nlog(min(n, k)) O(min(n,k))
    bool solution3(vector<int>& nums, int k, int t) {
      set<long> mySet;
      for (int i = 0; i < nums.size(); ++i) {
        // nums[i] 较大时，nums[i] - nums[j] <= t, 则 nums[j] >= nums[i] - t
        // nums[j] 较大时，nums[j] - nums[i] <= t, 则 nums[j] <= nums[i] + t
        // 即 nums[i] - t <= nums[j] <= nums[i] + t
        // lower_bound 取出 set 中大于等于 x 的元素的第一个元素
        // 如果全部都 小于x，则取到最后一个元素，即最大元素，所以下面要做一个判断
        auto iter = mySet.lower_bound((long) nums[i] - t);
        if (iter != mySet.end() && *iter <= (long) nums[i] + t) return true;
        mySet.insert(nums[i]);
        if (mySet.size() == k + 1) mySet.erase(nums[i-k]);  // 保证滑动窗口
      }
      return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}