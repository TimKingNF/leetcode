//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
//
// 
//
// 示例 1: 
//
// 输入: [7,5,6,4]
//输出: 5 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
//

#include "header.h"

namespace LeetCode_51 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
      return solution1(nums);
    }

    // 分治, 利用归并排序
    int solution1(vector<int>& nums) {
      int ans = 0;
      solution1core(nums, 0, nums.size()-1, ans);
      return ans;
    }

    void solution1core(vector<int>& nums, int l, int r, int& ans) {
      if (l >= r) return;
      int mid = l + (r - l) / 2;
      solution1core(nums, l, mid, ans);
      solution1core(nums, mid+1, r, ans);
      merge(nums, l, mid, r, ans);
    }

    void merge(vector<int>& nums, int l, int mid, int r, int& ans) {
      vector<int> tmp(r-l+1);
      int i = l, j = mid + 1, k = 0;
      while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
          tmp[k] = nums[i];
          ++i;
          ans += j - 1 - mid;  // 从 mid+1 - j-1 之间的元素
        } else {
          tmp[k] = nums[j];
          ++j;
        }
        ++k;
      }
      while (i <= mid) {
        tmp[k] = nums[i];
        ++i;
        ++k;
        ans += j - 1 - mid;
      }
      while (j <= r) {
        tmp[k] = nums[j];
        ++k;
        ++j;
      }
      // 复制到原数组中
      copy(tmp.begin(), tmp.end(), nums.begin()+l);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}