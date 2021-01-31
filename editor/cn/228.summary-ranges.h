//给定一个无重复元素的有序整数数组 nums 。 
//
// 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 num
//s 的数字 x 。 
//
// 列表中的每个区间范围 [a,b] 应该按如下格式输出： 
//
// 
// "a->b" ，如果 a != b 
// "a" ，如果 a == b 
// 
//
// 
//
// 示例 1： 
//
// 输入：nums = [0,1,2,4,5,7]
//输出：["0->2","4->5","7"]
//解释：区间范围是：
//[0,2] --> "0->2"
//[4,5] --> "4->5"
//[7,7] --> "7"
// 
//
// 示例 2： 
//
// 输入：nums = [0,2,3,4,6,8,9]
//输出：["0","2->4","6","8->9"]
//解释：区间范围是：
//[0,0] --> "0"
//[2,4] --> "2->4"
//[6,6] --> "6"
//[8,9] --> "8->9"
// 
//
// 示例 3： 
//
// 输入：nums = []
//输出：[]
// 
//
// 示例 4： 
//
// 输入：nums = [-1]
//输出：["-1"]
// 
//
// 示例 5： 
//
// 输入：nums = [0]
//输出：["0"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 20 
// -231 <= nums[i] <= 231 - 1 
// nums 中的所有值都 互不相同 
// 
// Related Topics 数组 
// 👍 82 👎 0

#include "header.h"

namespace LeetCode228 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      return solution2(nums);
    }

    vector<string> solution1(vector<int>& nums) {
      int n = nums.size();
      if (n == 0) return {};
      if (n == 1) return {to_string(nums[0])};
      int start = nums[0], i = 1;
      vector<string> ans;
      ostringstream oss;

      while (i < n) {
        if (nums[i] != nums[i-1] + 1) {
          if (nums[i-1] != start) {
            oss << start << "->" << nums[i-1];
          } else {
            oss << start;
          }
          ans.push_back(oss.str());
          oss.str("");
          start = nums[i];
        }
        ++i;
      }
      if (nums[i-1] == nums[n-2] + 1) {
        oss << start << "->" << nums[n-1];
      } else {
        oss << start;
      }
      ans.push_back(oss.str());
      return ans;
    }

    // 更简洁的写法
    vector<string> solution2(vector<int>& nums) {
      int n = nums.size();
      vector<string> ans;
      for (int i = 0, j = 0; j < n; ++j) {
        if (j + 1 < n && nums[j+1] == nums[j] + 1) continue;
        if (i == j) ans.push_back(to_string(nums[i]));
        else ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
        i = j + 1;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}