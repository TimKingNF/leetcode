//给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。 
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
// 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。 
//
// 注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/ 
// Related Topics 栈 Sliding Window

#include "header.h"

namespace LeetCode_59_I {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      return solution1(nums, k);
    }

    vector<int> solution1(vector<int>& nums, int k) {
      if (nums.empty()) return {};
      // if (k > nums.size()) return {*max_element(nums.begin(), nums.end())};  // 题目中已经限定 1 <= k <= n, 所以无需考虑
      vector<int> ans;
      deque<int> q;
      for (int i = 0; i < nums.size(); ++i) {
        if (!q.empty() && i - q.back() == k)  // 说明当前最大值的索引已经超过了滑动窗口的范围
          q.pop_back();
        // 从前往后开始比较，大于等于队列的元素，则该元素出队列
        // 最后将当前索引从前插入，表示第几大的元素
        // 如果比所有元素都大，则说明当前是最大元素
        while (!q.empty() && nums[i] >= nums[q.front()])
          q.pop_front();
        q.push_front(i);
        if (i >= k - 1)  // 满足第一个 k 窗口之后
          ans.push_back(nums[q.back()]);  // 返回最大的元素
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}