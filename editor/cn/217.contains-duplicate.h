//给定一个整数数组，判断是否存在重复元素。 
//
// 如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。 
//
// 
//
// 示例 1: 
//
// 输入: [1,2,3,1]
//输出: true 
//
// 示例 2: 
//
// 输入: [1,2,3,4]
//输出: false 
//
// 示例 3: 
//
// 输入: [1,1,1,3,3,4,3,2,4,2]
//输出: true 
// Related Topics 数组 哈希表

#include "header.h"

namespace LeetCode217 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      return solution1(nums);
    }

    // O(N) 空间: O(N)
    bool solution1(vector<int>& nums) {
      return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }

    // O(N * logN)
    bool solution2(vector<int>& nums) {
      if (nums.empty()) return false;
      quick_sort(nums, 0, nums.size() - 1);  // 先排序
      for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] == nums[i+1]) return true;
      }
      return false;
    }

    // TODO: O(N * logN)  极端情况下， 如果数组是升序，该算法会退化为 O(n^2)
    void quick_sort(vector<int>& nums, int begin, int end) {
      if (begin >= end) return;

      int left = begin, right = end + 1, t = nums[left];
      while (true) {
        do {
          left++;
        } while (left <= end && nums[left] < t);  // 遍历直到第一个大于等于的元素
        do {
          right--;
        } while (right >= begin && nums[right] > t);

        if (left > right) break;
        swap(nums[left], nums[right]);
      }
      swap(nums[begin], nums[right]);
      quick_sort(nums, begin, right - 1);
      quick_sort(nums, right + 1, end);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}