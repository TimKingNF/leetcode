//假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
//
// 请找出其中最小的元素。 
//
// 你可以假设数组中不存在重复元素。 
//
// 示例 1: 
//
// 输入: [3,4,5,1,2]
//输出: 1 
//
// 示例 2: 
//
// 输入: [4,5,6,7,0,1,2]
//输出: 0 
// Related Topics 数组 二分查找

#include "header.h"

namespace LeetCode153 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMin(vector<int>& nums) {
      return solution2(nums);
    }

    // O(N)
    int solution1(vector<int>& nums) {
      int res = INT32_MAX;
      for (int num : nums) {
        if (num < res) res = num;
      }
      return res;
    }

    // O(log2 N)
    int solution2(vector<int>& nums) {
      // 数组的旋转可以分为两段递增数组，其中最小的元素就是两个数组的分界线
      // 在不重复的数组中，取中点的数据，通过比较中点可知, 该中点在前面的递增数组中，还是在后面的递增数组中
      int left = 0, right = nums.size() - 1;
      int middle = left;
      while (nums[right] < nums[left]) {  // 如果不满足此条件，说明该数组就是一个有序数组
        if (right - left == 1) return nums[right];  // 当缩短到只有2个元素时，后一个元素就是最小值

        middle = (left + right) / 2;
        if (nums[middle] >= nums[right])
          left = middle;
        else
          right = middle;
      }
      return nums[middle];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}