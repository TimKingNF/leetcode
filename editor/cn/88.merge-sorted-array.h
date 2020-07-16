//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。 
//
// 
//
// 说明: 
//
// 
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。 
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。 
// 
//
// 
//
// 示例: 
//
// 输入:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//
//输出: [1,2,2,3,5,6] 
// Related Topics 数组 双指针

#include "header.h"

namespace LeetCode88 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      return solution1(nums1, m, nums2, n);
    }

    void solution1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      // 从后往前复制，减少需要移动的次数
      int i = m - 1, j = n - 1, k = m + n - 1;
      while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
          nums1[k--] = nums1[i--];
        else
          nums1[k--] = nums2[j--];
      }
      // 如果 i < 0，则无需拷贝; j >= 0，则需要将剩余的 0-j的元素复制到 nums1 中
      if (j >= 0) copy(nums2.begin(), nums2.begin()+j+1, nums1.begin());
      // while ( j >= 0 )
      //   nums1[k--] = nums2[j--];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}