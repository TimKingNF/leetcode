//给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。 
//
// 你需要返回给定数组中的重要翻转对的数量。 
//
// 示例 1: 
//
// 
//输入: [1,3,2,3,1]
//输出: 2
// 
//
// 示例 2: 
//
// 
//输入: [2,4,3,5,1]
//输出: 3
// 
//
// 注意: 
//
// 
// 给定数组的长度不会超过50000。 
// 输入数组中的所有数字都在32位整数的表示范围内。 
// 
// Related Topics 排序 树状数组 线段树 二分查找 分治算法

#include "header.h"

namespace LeetCode493 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
      return solution1(nums);
    }

    // 分治，归并排序
    int solution1(vector<int>& nums) {
      int ans = 0;
      solution1core(nums, 0, nums.size()-1, ans);
      return ans;
    }

    void solution1core(vector<int>& nums, int l, int r, int &ans) {
      if (l >= r) return;
      int mid = l + (r - l) / 2;
      solution1core(nums, l, mid, ans);
      solution1core(nums, mid+1, r, ans);
      // 循环比较左右
      for (int i = l, j = mid + 1; i <= mid && j <= r;) {
        long lNum = nums[i], rNum = nums[j];
        rNum *= 2;
        if (lNum <= rNum) ++i;
        else {
          ++j;
          ans += mid - i + 1;
        }
      }
      merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r) {
      vector<int> tmp(r-l+1);
      int i = l, j = mid + 1, k = 0;
      while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {  // 正常排序比较
          tmp[k++] = nums[i++];
        } else {
          tmp[k++] = nums[j++];
        }
      }
      while (i <= mid) {
        tmp[k++] = nums[i++];
      }
      while (j <= r) {
        tmp[k++] = nums[j++];
      }
      copy(tmp.begin(), tmp.end(), nums.begin() + l);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}