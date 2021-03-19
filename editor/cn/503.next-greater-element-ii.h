//给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第
//一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。 
//
// 示例 1: 
//
// 
//输入: [1,2,1]
//输出: [2,-1,2]
//解释: 第一个 1 的下一个更大的数是 2；
//数字 2 找不到下一个更大的数； 
//第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
// 
//
// 注意: 输入数组的长度不会超过 10000。 
// Related Topics 栈 
// 👍 337 👎 0

#include "header.h"

namespace LeetCode503 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      return solution2(nums);
    }

    // O( N ), O( N )
    vector<int> solution1(vector<int>& nums) {
      if (nums.empty()) return {};

      int n = nums.size();
      vector<int> ans(n, -1);
      stack<pair<int, int>> stk;
      stk.push({nums[0], 0});  // 记录下当前的位置

      int right = 1;
      while (right < n) {
        if (nums[right] < stk.top().first) {
          stk.push({nums[right], right});
        } else {
          while (!stk.empty() && nums[right] > stk.top().first) {
            ans[stk.top().second] = nums[right];
            stk.pop();
          }
          if (!stk.empty() && right == stk.top().second) {  // 说明当前就是最大值了
            ans[right] = -1;
            break;
          }
          stk.push({nums[right], right});
        }
        if (stk.size() == 2 * n) break; // 说明并没有可以计算大小的空间
        if (++right == n) right = 0;
      }
      return ans;
    }

    // 更简化写法
    vector<int> solution2(vector<int>& nums) {
      int n = nums.size();
      vector<int> ans(n, -1);
      stack<int> stk;
      for (int i = 0; i < 2 * n -1; ++i) {
        while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
          ans[stk.top()] = nums[i % n];
          stk.pop();
        }
        stk.push(i % n);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}