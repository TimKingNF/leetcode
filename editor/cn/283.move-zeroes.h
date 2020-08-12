//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。 
//
// 示例: 
//
// 输入: [0,1,0,3,12]
//输出: [1,3,12,0,0] 
//
// 说明: 
//
// 
// 必须在原数组上操作，不能拷贝额外的数组。 
// 尽量减少操作次数。 
// 
// Related Topics 数组 双指针

#include "header.h"

namespace LeetCode283 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    return moveZeroesToRight(nums);
  }

  void moveZeroesToRight(vector<int>& nums) {
    // for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); ++cur) {
    //   if (nums[cur] != 0) swap(nums[lastNonZeroFoundAt++], nums[cur]);
    // }
    int n = nums.size(), i = -1, j = 0;
    while (j < n) {
      if (nums[j] != 0) nums[++i] = nums[j];
      ++j;
    }
    for (int k = i+1; k < n; ++k) nums[k] = 0;
  }

  // 变种题，将 0 移动到前面
  void moveZeroesToLeft(vector<int>& nums) {
    for (int lastZeroFoundAt = 0, cur = 0; cur < nums.size(); ++cur) {
      if (nums[cur] == 0) swap(nums[lastZeroFoundAt++], nums[cur]);
    }
  }

  // 变种题，将 0 分别移动到左右, 同时并保证顺序
  void moveZeroesToLeftRight(vector<int>& nums) {
    return;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}