//给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。 
//
// 示例 1: 
//
// 
//输入: [3, 2, 1]
//
//输出: 1
//
//解释: 第三大的数是 1.
// 
//
// 示例 2: 
//
// 
//输入: [1, 2]
//
//输出: 2
//
//解释: 第三大的数不存在, 所以返回最大的数 2 .
// 
//
// 示例 3: 
//
// 
//输入: [2, 2, 3, 1]
//
//输出: 1
//
//解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
//存在两个值为2的数，它们都排第二。
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode414 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
      return solution3(nums);
    }

    // O(log2 N)  取决于算法的效率
    int solution1(vector<int>& nums) {
      sort(nums.rbegin(), nums.rend());  // 从大到小
      int tmp = nums[0], diff = 0;
      for  (int cur = 1; diff < 2 && cur < nums.size(); ++cur) {
        if (tmp != nums[cur]) {
          ++diff;
          tmp = nums[cur];
        }
      }
      return diff == 2 ? tmp : nums[0];
    }

    // O(N) 利用 set 有序且去重的性质, 但会产生额外的N空间开销
    int solution2(vector<int>& nums) {
      set<int> tmp(nums.begin(), nums.end());
      auto it = tmp.end();
      --it;
      if (tmp.size() < 3) return *it;
      // 否则取倒数第三的元素
      --it;
      --it;
      return *it;
    }

    // O(N) 手动维护数组
    int solution3(vector<int>& nums) {
      long tmp[3];
      tmp[0] = tmp[1] = tmp[2] = INT64_MIN;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == tmp[0] || nums[i] == tmp[1] || nums[i] == tmp[2]) continue;
        if (nums[i] > tmp[0]) {  // 大于最大值
          tmp[2] = tmp[1];
          tmp[1] = tmp[0];
          tmp[0] = nums[i];
        } else if (nums[i] > tmp[1]) {  // 大于第二大的值
          tmp[2] = tmp[1];
          tmp[1] = nums[i];
        } else if (nums[i] > tmp[2]) {  // 大于第三大的值
          tmp[2] = nums[i];
        }
      }
      return tmp[2] != INT64_MIN ? tmp[2] : tmp[0];
    }

};
//leetcode submit region end(Prohibit modification and deletion)

}