//给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。 
//
// 换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。 
//
// 以数组形式返回答案。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [8,1,2,2,3]
//输出：[4,0,1,1,3]
//解释： 
//对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
//对于 nums[1]=1 不存在比它小的数字。
//对于 nums[2]=2 存在一个比它小的数字：（1）。 
//对于 nums[3]=2 存在一个比它小的数字：（1）。 
//对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
// 
//
// 示例 2： 
//
// 输入：nums = [6,5,4,8]
//输出：[2,1,0,3]
// 
//
// 示例 3： 
//
// 输入：nums = [7,7,7,7]
//输出：[0,0,0,0]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 500 
// 0 <= nums[i] <= 100 
// 
// Related Topics 数组 哈希表 
// 👍 96 👎 0

#include "header.h"

namespace LeetCode1365 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      return solution2(nums);
    }

    // 快排 + hash
    // O( N(logN+1) ), O( N )
    vector<int> solution1(vector<int>& nums) {
      int n = nums.size();
      vector<int> ans(nums.begin(), nums.end());
      sort(ans.begin(), ans.end());
      map<int, int> dict;

      for (int i = 0; i < n; ++i) {
        dict[ans[i]] = i;
        // 如果有相同的数，遍历到最后一个
        while (i + 1 < n && ans[i] == ans[i+1]) ++i;
      }

      int i = 0;
      for (int num : nums) {
        ans[i++] = dict[num];
      }
      return ans;
    }

    // 计数排序
    vector<int> solution2(vector<int>& nums) {
      vector<int> cnt(101, 0);  // 0 <= nums[i] <= 100
      int n = nums.size();
      for (int i = 0; i < n; ++i) {
        ++cnt[nums[i]];
      }

      for (int i = 1; i <= 100; ++i) {  // 累计数量
        cnt[i] += cnt[i-1];
      }
      vector<int> ans(n);
      for (int i = 0; i < n; ++i) {
        ans[i] = nums[i] == 0 ? 0 : cnt[nums[i]-1];  // nums[i]-1 取前一个数，不包括 nums[i] 自己
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}