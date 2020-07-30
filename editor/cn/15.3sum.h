//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复
//的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例： 
//
// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
// 
// Related Topics 数组 双指针

#include "header.h"

namespace LeetCode15 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      return solution2(nums);
    }

    // 将三数问题转化为两数之和问题, 使用双指针
    vector<vector<int>> solution1(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> ans;
      int len = nums.size();
      for (int i = 0; i < len; ++i) {
        int left = i + 1, right = len - 1;
        while (left < right) {
          int sum = nums[left] + nums[right];
          if (sum == -nums[i]) {
            ans.push_back({nums[i], nums[left], nums[right]});
            // 跳过与当前元素重复的元素, 指向相同元素的最后一个
            while (left < right && nums[left] == nums[left+1]) ++left;
            while (left < right && nums[right] == nums[right-1]) --right;
            // 指向下一个元素
            ++left;
            --right;
          } else if (sum < -nums[i]) {
            ++left;
          } else {
            --right;
          }
        }
        // 跳过和 当前 i 相同的元素
        while (i + 1 < len && nums[i] == nums[i+1]) ++i;
      }
      return ans;
    }

    // 使用字典辅助，这里需要记录原数组的每个数字的出现次数，并且要将重复的元素合并
    vector<vector<int>> solution2(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> new_nums;
      unordered_map<int, int> dict;
      for (int v : nums) {
        if (dict.count(v)) ++dict[v];
        else {
          new_nums.push_back(v);
          dict[v] = 1;
        }
      }
      // 对new_nums 排序
      sort(new_nums.begin(), new_nums.end());
      int len = new_nums.size();
      for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
          // 如果元素只有一个
          if (i == j && dict[new_nums[j]] == 1) continue;
          int target = -new_nums[i] - new_nums[j];
          // 这一步防止取到重复的值，target < new_nums[j], 则说明之前已经取过该组合
          if (target < new_nums[j]) continue;
          if (dict.count(target)) {
            // 这里避免取到两个同样的元素
            if (new_nums[i] == target && dict[target] < 2) continue;
            if (new_nums[j] == target && dict[target] < 2) continue;
            // 0,0,0 的情况
            if (new_nums[i] == target && new_nums[j] == target && dict[target] < 3) continue;
            ans.push_back({new_nums[i], new_nums[j], target});
          }
        }
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}