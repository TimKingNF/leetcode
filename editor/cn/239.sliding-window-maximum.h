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
  };
//leetcode submit region end(Prohibit modification and deletion)

}