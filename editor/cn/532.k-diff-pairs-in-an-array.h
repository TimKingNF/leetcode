//给定一个整数数组和一个整数 k, 你需要在数组里找到不同的 k-diff 数对。这里将 k-diff 数对定义为一个整数对 (i, j), 其中 i 和 j
// 都是数组中的数字，且两数之差的绝对值是 k. 
//
// 示例 1: 
//
// 
//输入: [3, 1, 4, 1, 5], k = 2
//输出: 2
//解释: 数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
//尽管数组中有两个1，但我们只应返回不同的数对的数量。
// 
//
// 示例 2: 
//
// 
//输入:[1, 2, 3, 4, 5], k = 1
//输出: 4
//解释: 数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
// 
//
// 示例 3: 
//
// 
//输入: [1, 3, 1, 5, 4], k = 0
//输出: 1
//解释: 数组中只有一个 0-diff 数对，(1, 1)。
// 
//
// 注意: 
//
// 
// 数对 (i, j) 和数对 (j, i) 被算作同一数对。 
// 数组的长度不超过10,000。 
// 所有输入的整数的范围在 [-1e7, 1e7]。 
// 
// Related Topics 数组 双指针

#include "header.h"

namespace LeetCode532 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      return solution3(nums, k);
    }

    // O(N^2)
    int solution1(vector<int>& nums, int k) {
      int len = nums.size(), res = 0;
      unordered_map<int, bool> tmp;
      for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
          if (abs(nums[i] - nums[j]) == k && !tmp[nums[i]+nums[j]]) {
            ++res;
            tmp[nums[i]+nums[j]] = true;
          }
        }
      }
      return res;
    }

    // O(N * logN + N) 先排序后使用双指针遍历
    int solution2(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());

      int slow = 0, quick = 1, len = nums.size(), res = 0;
      while (quick < len) {
        int diff = nums[quick] - nums[slow];
        if (diff == k) {
          ++res;
          // 跳过重复元素
          while (slow < len - 1 && nums[slow] == nums[slow+1]) ++slow;
          while (quick < len - 1 && nums[quick] == nums[quick+1]) ++quick;
          ++slow;
          ++quick;
        } else if (diff > k) {
          ++slow;
        } else {
          ++quick;
        }

        if (quick == slow) {  // 如果slow追上了quick, 则quick自增
          ++quick;
        }
      }
      return res;
    }

    // O(N), O(N)
    int solution3(vector<int>& nums, int k) {
      if (k < 0)
        return 0;
      unordered_set<int> saw;  // 保存已经访问过的数

      // 保存 k-diff 数对中较小的那个（也可以保存较大的）只用来统计数对个数
      unordered_set<int> diff;

      for (int i = 0; i < nums.size(); i++) {
        // 检查数对中较小的数 1 是否在数组中：3 - 2 = 1
        if (saw.find(nums[i] - k) != saw.end())
          diff.insert(nums[i] - k); // 插入数对中较小的数 1

        // 检查数对中较大的数 3 是否在数组中：1 + 2 = 3
        if (saw.find(nums[i] + k) != saw.end())
          diff.insert(nums[i]); // 插入数对中较小的数 1

        saw.insert(nums[i]);
      }

      // 因为 set 中不存在重复元素，所以不同的元素个数代表不同的 k-diff 数对个数
      return diff.size();
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}