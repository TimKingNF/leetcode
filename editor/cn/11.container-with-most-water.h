//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, 
//ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 
//
// 说明：你不能倾斜容器，且 n 的值至少为 2。 
//
// 
//
// 
//
// 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。 
//
// 
//
// 示例： 
//
// 输入：[1,8,6,2,5,4,8,3,7]
//输出：49 
// Related Topics 数组 双指针

#include "header.h"

namespace LeetCode11 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxArea(vector<int>& height) {
      return solution1(height);
    }

    // 关键在于，双指针夹逼的时候，指针之间的距离是一直在减小的
    // 容量为 min(i, j) * (j - i)
    // 而移动数字较大的板，min(i, j) 只可能减小，不可能增大，所以要移动数字较小的板
    int solution1(vector<int>& height) {
      int left = 0, right = height.size() - 1;
      int ans = 0;
      while (left < right) {
        if (height[left] < height[right]) {
          ans = max(ans, height[left] * (right - left));
          ++left;
        } else {
          ans = max(ans, height[right] * (right - left));
          --right;
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}