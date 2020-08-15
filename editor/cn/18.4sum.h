//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
// d 的值与 target 相等？找出所有满足条件且不重复的四元组。 
//
// 注意： 
//
// 答案中不可以包含重复的四元组。 
//
// 示例： 
//
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
//满足要求的四元组集合为：
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]
// 
// Related Topics 数组 哈希表 双指针

#include "header.h"

namespace LeetCode18 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      return solution2(nums, target);
    }

    vector<vector<int>> solution1(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> ans;
      int len = nums.size();
      if (len < 4) return ans;
      int diff, sum;
      for (int i = 0; i <= len - 4; ++i) {  // i 最多遍历到 len - 4, 因为是4数之和
        for (int j = i + 1; j <= len - 3; ++j) {  // 同理 j 最多遍历到 len - 3
          diff = target - nums[i] - nums[j];
          int left = j + 1, right = len - 1;
          while (left < right) {
            sum = nums[left] + nums[right];
            if (sum == diff) {
              ans.push_back({nums[i], nums[j], nums[left], nums[right]});
              while (left < right && nums[left] == nums[left+1]) ++left;
              while (left < right && nums[right] == nums[right-1]) --right;
              ++left;
              --right;
            }
            else if (sum < diff) ++left;
            else --right;
          }
          // 跳过重复的 j 元素
          while (j + 1 <= len-3 && nums[j] == nums[j+1]) ++j;
        }
        // 跳过重复的 i 元素
        while (i + 1 <= len-4 && nums[i] == nums[i+1]) ++i;
      }
      return ans;
    }

    vector<vector<int>> solution2(vector<int>& nums, int target) {
      vector<vector<int>> ans;
      int len = nums.size();
      set<vector<int>> res;
      sort(nums.begin(), nums.end());
      unordered_map<int, vector<pair<int, int>>> dict;
      for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {  // 滑动窗口
          int sum = nums[i] + nums[j];
          if (dict.count(target - sum)) {
            for (auto v : dict[target - sum]) {
              if (v.second < i)  // 这里防止重复取
                res.insert({nums[v.first], nums[v.second], nums[i], nums[j]});
            }
          }
          if (!dict.count(sum)) dict[sum] = vector<pair<int, int>>{{i, j}};
          else dict[sum].emplace_back(i, j);
        }
      }
      // 由于是通过下标判断重复，故, 对于 0,0,0,0,0 可能产生多个结果, 需要去重
      for (auto v : res) ans.push_back(v);
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}