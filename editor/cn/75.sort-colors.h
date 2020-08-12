//给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。 
//
// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。 
//
// 注意: 
//不能使用代码库中的排序函数来解决这道题。 
//
// 示例: 
//
// 输入: [2,0,2,1,1,0]
//输出: [0,0,1,1,2,2] 
//
// 进阶： 
//
// 
// 一个直观的解决方案是使用计数排序的两趟扫描算法。 
// 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。 
// 你能想出一个仅使用常数空间的一趟扫描算法吗？ 
// 
// Related Topics 排序 数组 双指针

#include "header.h"

namespace LeetCode75 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void sortColors(vector<int>& nums) {
      return solution2(nums);
    }

    // 计数排序, O( 2n )
    void solution1(vector<int>& nums) {
      int cnt[3] = {0};
      for (int n : nums) ++cnt[n];
      int i = 0;
      while (cnt[0]-- > 0) nums[i++] = 0;
      while (cnt[1]-- > 0) nums[i++] = 1;
      while (cnt[2]-- > 0) nums[i++] = 2;
    }

    // O( n )
    void solution2(vector<int>& nums) {
      int n = nums.size();
      int lt = -1, gt = n, i = 0;
      while (i < gt) {
        if (nums[i] == 2) swap(nums[--gt], nums[i]);  // i 无需移动，还要再次判断
        else if (nums[i] == 0) swap(nums[++lt], nums[i++]);  // i 需要移动
        else ++i;
      }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}