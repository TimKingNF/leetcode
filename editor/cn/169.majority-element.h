//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。 
//
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。 
//
// 
//
// 示例 1: 
//
// 输入: [3,2,3]
//输出: 3 
//
// 示例 2: 
//
// 输入: [2,2,1,1,1,2,2]
//输出: 2
// 
// Related Topics 位运算 数组 分治算法

#include "header.h"

namespace LeetCode169 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO: 位运算解法
    int majorityElement(vector<int>& nums) {
      return solution3(nums);
    }

    // O(N) 空间：0(N)
    int solution1(vector<int>& nums) {
      int len = nums.size();
      unordered_map<int, int> v;
      int max_count = 0, res = 0;
      for (int i = 0; i < len; ++i) {
        if (++v[nums[i]] > max_count) {  // 可以再简化一下：已知结果占元素的一般以上
          max_count = v[nums[i]];
          res = nums[i];
        }
      }
      return res;
    }

    // O(N log2 N)
    int solution2(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      return nums[nums.size() / 2];  // 中位数一定是众数
    }

    // O(N)
    int solution3(vector<int>& nums) {
      int count = 0, candidate;
      for (int i : nums) {
        if (count == 0) candidate = i;
        if (i == candidate) ++count;
        else --count;
      }
      return candidate;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}