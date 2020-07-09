//给定一个范围在 1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。 
//
// 找到所有在 [1, n] 范围之间没有出现在数组中的数字。 
//
// 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。 
//
// 示例: 
//
// 
//输入:
//[4,3,2,7,8,2,3,1]
//
//输出:
//[5,6]
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode448 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      return solution1(nums);
    }

    // 通过在原数组上记录访问过的元素
    vector<int> solution1(vector<int>& nums) {
      if (nums.empty()) return nums;
      int len = nums.size();
      vector<int> res;
      for(int i = 0; i < len; ++i)
      {
        int index = (nums[i] - 1) % len;  // 因为是在原数组上修改， 所以还需要对数据进行取模
        nums[index] += len;
      }
      for(int i = 0 ; i < len; ++i)
      {
        if(nums[i] <= len)  // 该元素没有被上一步遍历到，故还是小于 n
          res.push_back(i+1);
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}