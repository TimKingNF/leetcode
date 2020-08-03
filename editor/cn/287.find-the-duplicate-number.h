//给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出
//这个重复的数。 
//
// 示例 1: 
//
// 输入: [1,3,4,2,2]
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [3,1,3,4,2]
//输出: 3
// 
//
// 说明： 
//
// 
// 不能更改原数组（假设数组是只读的）。 
// 只能使用额外的 O(1) 的空间。 
// 时间复杂度小于 O(n2) 。 
// 数组中只有一个重复的数字，但它可能不止重复出现一次。 
// 
// Related Topics 数组 双指针 二分查找

#include "header.h"

namespace LeetCode287 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      return solution2(nums);
    }

    // 每次二分之后都去判断小于 mid 的数字有多少个
    // O( nlogN )
    int solution1(vector<int>& nums) {
      int n = nums.size(), left = 1, right = n - 1;  // 实际的 n 为 nums.size() - 1
      while (left < right) {
        int mid = left + (right - left) / 2;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
          cnt += nums[i] <= mid;
        }
        if (cnt > mid) {  // 说明重复的元素一定出在左边
          right = mid;
        } else {  // 包括了 cnt = mid 的情况，所以left = mid + 1
          left = mid + 1;
        }
      }
      return left;
    }

    // 快慢指针
    // O (N)
    int solution2(vector<int>& nums) {
      int slow = 0, fast = 0;
      do {
        slow = nums[slow];
        fast = nums[nums[fast]];
      } while (slow != fast);  // slow 与 fast 相等时说明 slow 和 fast 在环中相遇
      slow = 0;
      while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;  // 环入口
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}