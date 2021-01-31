//给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。 
//
//
// 返回滑动窗口中的最大值。 
//
// 
//
// 进阶： 
//
// 你能在线性时间复杂度内解决此题吗？ 
//
// 
//
// 示例: 
//
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
//输出: [3,3,5,5,6,7] 
//解释: 
//
//  滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10^5 
// -10^4 <= nums[i] <= 10^4 
// 1 <= k <= nums.length 
// 
// Related Topics 堆 Sliding Window

#include "header.h"

namespace LeetCode239 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      return solution1(nums, k);
    }

    vector<int> solution1(vector<int>& nums, int k) {
      if (nums.empty()) return {};
      deque<int> q;
      vector<int> ans;
      for (int i = 0; i < nums.size(); ++i) {
        if (!q.empty() && i - q.back() == k)  // 最大值超出了滑动窗口范围
          q.pop_back();
        while (!q.empty() && nums[i] >= nums[q.front()])
          q.pop_front();
        q.push_front(i);
        if (i >= k - 1)
          ans.push_back(nums[q.back()]);
      }
      return ans;
    }

    // 单调栈，会超时
    vector<int> solution2(vector<int>& nums, int k) {
      stack<pair<int, int>> stk;
      vector<int> ans;
      int v, idx;

      for (int i = 0, j = 0; j < nums.size(); ++j) {
        if (j - i == k) {  // 说明已达 k+1 个滑动窗口
          // i 元素待移除
          tie(v, idx) = stk.top();
          if (nums[i] == v && idx == i) {  // 待移除元素等于栈顶元素，即最大值, 且下标也符合
            // 移除栈中下标小于等于 idx 的元素
            while (!stk.empty() && stk.top().second <= idx) {
              stk.pop();
            }
            // 补上从 i+1 开始，到 j 的元素, 构成新的单调栈
            int k = i + 1;
            while (k < j) {
              if (stk.empty() || nums[k] >= stk.top().first) {
                stk.push({nums[k], k});
              }
              ++k;
            }
          }
          ++i;  // i 自增
        }

        // push 新元素
        if (stk.empty() || nums[j] >= stk.top().first) {
          stk.push({nums[j], j});
        }

        // 满足 k 个窗口
        if (j - i + 1 == k) {
          ans.push_back(stk.top().first);
        }
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}