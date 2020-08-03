//给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。 
//
// 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。 
//
// 你可以假设 nums1 和 nums2 不会同时为空。 
//
// 
//
// 示例 1: 
//
// nums1 = [1, 3]
//nums2 = [2]
//
//则中位数是 2.0
// 
//
// 示例 2: 
//
// nums1 = [1, 2]
//nums2 = [3, 4]
//
//则中位数是 (2 + 3)/2 = 2.5
// 
// Related Topics 数组 二分查找 分治算法

#include "header.h"

namespace LeetCode4 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      return solution4(nums1, nums2);
    }

    // O(m+n) O(m+n)
    double solution1(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size(), n = nums2.size(), len = m + n;
      vector<int> nums(len);
      int i = 0, j = 0;
      for (int k = 0; k < len; ++k) {
        if (i < m && j < n) {
          if (nums1[i] <= nums2[j]) nums[k] = nums1[i++];
          else nums[k] = nums2[j++];
        }
        else if (j == n) nums[k] = nums1[i++];
        else nums[k] = nums2[j++];
      }
      return (m + n) & 1 ? (double) nums[(len+1)/2-1]  // 奇数
                         : ((double) nums[len/2-1] + nums[len/2]) / 2;  // 偶数
    }

    // O( (m+n)/2 ), O(1)
    double solution2(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size(), n = nums2.size(), len = m + n;
      int median_left_index, median_right_index;
      if (len & 1)  {  // 奇数
        median_left_index = (len + 1) / 2 - 1;
        median_right_index = median_left_index;
      } else {
        median_left_index = len / 2 - 1;
        median_right_index = median_left_index + 1;
      }
      int i = 0, j = 0;
      double median_left = 0, median_right = 0;
      // 从 nums1 和 nums2 中数到 median_right_index
      for (int k = 0, left, right, tmp; k <= median_right_index; ++k) {
        left = i < m ? nums1[i] : INT_MAX;
        right = j < n ? nums2[j] : INT_MAX;
        if (left < right) {
          tmp = left;
          ++i;
        } else {
          tmp = right;
          ++j;
        }
        if (k == median_left_index) median_left = tmp;
        if (k == median_right_index) median_right = tmp;
      }
      return (median_left + median_right) / 2;
    }

    // 二分思路
    // O ( log(m+n) )
    double solution3(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size(), n = nums2.size();
      int left = (m + n + 1) / 2;  // 中位数左值
      int right = (m + n + 2) / 2;  // 中位数右值，如果是奇数，则 left = right
      return (solution3core(nums1, 0, m - 1, nums2, 0, n-1, left) +
              solution3core(nums1, 0, m - 1, nums2, 0, n-1, right)) * 0.5;
    }

    // 获取第K大的元素
    double solution3core(vector<int>& nums1, int start_1, int end_1,
                         vector<int>& nums2, int start_2, int end_2, int k) {
      int len_1 = end_1 - start_1 + 1, len_2 = end_2 - start_2 + 1;
      // 如果 len_1 > len_2, 则交换 nums1 和 nums2
      if (len_1 > len_2) return solution3core(nums2, start_2, end_2, nums1, start_1, end_1, k);
      if (len_1 == 0) return nums2[start_2 + k - 1];  // 如果 nums1 已空，则直接取 nums2 中的第 k 个数
      if (k == 1) return min(nums1[start_1], nums2[start_2]);  // 如果 k = 1，则取两边的较小值

      // 在两边数组中取第 k/2 的值（如果长度小于 k/2 则取末尾)
      int i = start_1 + min(len_1, k / 2) - 1;
      int j = start_2 + min(len_2, k / 2) - 1;
      // 比较两个值的较小值，较小的一方 从 start 到 k/2 都被排除掉
      if (nums1[i] > nums2[j])
        return solution3core(nums1, start_1, end_1, nums2, j+1, end_2, k - (j- start_2 + 1));
      else
        return solution3core(nums1, i+1, end_1, nums2, start_2, end_2, k - (i - start_1 + 1));
    }


    // 划分数组
    // O( log min(m+n) )
    double solution4(vector<int>& nums1, vector<int>& nums2) {
      // 保证 nums1 时较小长度
      if (nums1.size() > nums2.size()) swap(nums1, nums2);

      int m = nums1.size(), n = nums2.size();
      int left = 0, right = m;
      int median1 = 0, median2 = 0;  // median1: left_part的最大值，median2: right_part的最小值

      while (left <= right) {
        // 假设在 nums1 上选择一个位置 i 作为切割，分为 nums1[0 ... i-1]  和 nums1[i ... m-1]
        // 同样在 nums2 选择一个位置，该位置需要满足 left_part 长度 与 right_part 一致
        // 即 i + j = m - i + n - j 当 m + n 为偶数
        // i + j = m - i + n - j + 1 当 m + n 为奇数
        // 上面两个公式可以合并
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;  // 由公式 i+j = (m + n + 1) / 2 推导得
        // 此时 left_part 包含 nums1[0 ... i-1] 和 nums2[0 ... j-1]
        // right_part 包含 nums1[i ... m-1] 和 nums2[j ... n-1]

        // left_part
        int nums_iml = i == 0 ? INT_MIN : nums1[i - 1];  // nums1[i-1]
        int nums_jml = j == 0 ? INT_MIN : nums2[j - 1];  // nums2[j-1]
        // right_part
        int nums_i = i == m ? INT_MAX : nums1[i];  // nums[i]
        int nums_j = j == n ? INT_MAX : nums2[j];  // nums2[j]

        // 这里要满足 left_part 最大值 <= right_part 最小值
        // 由于 nums1[0 ... i-1] 递增 nums2[j ... n-1] 递减, 故需要取 nums_iml <= nums_j
        // 直到 i 在 0 ~ m 中取得最大
        if (nums_iml <= nums_j) {
          median1 = max(nums_iml, nums_jml);
          median2 = min(nums_i, nums_j);
          left = i + 1;
        } else {
          right = i - 1;
        }
      }
      // 如果是偶数，则中位数等于 (left_part 最大值 + right_part 最小值) * 0.5
      // 如果是奇数，left_part - right_part = 1, 取 left_part 最大值
      return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}