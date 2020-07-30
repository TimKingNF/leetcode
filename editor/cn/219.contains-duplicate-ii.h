//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值
// 至多为 k。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,2,3,1], k = 3
//输出: true 
//
// 示例 2: 
//
// 输入: nums = [1,0,1,1], k = 1
//输出: true 
//
// 示例 3: 
//
// 输入: nums = [1,2,3,1,2,3], k = 2
//输出: false 
// Related Topics 数组 哈希表

#include "header.h"

namespace LeetCode219 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> v;
      for (int i = 0 ; i < nums.size(); ++i) {
        if (v.count(nums[i]) && i - v[nums[i]] <= k) return true;
        v[nums[i]] = i; // 记录最新的下标
      }
      return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}