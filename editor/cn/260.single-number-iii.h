//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。 
//
// 示例 : 
//
// 输入: [1,2,1,3,2,5]
//输出: [3,5] 
//
// 注意： 
//
// 
// 结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。 
// 你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？ 
// 
// Related Topics 位运算

#include "header.h"

namespace LeetCode260 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      return solution1(nums);
    }

    // TODO
    // 通过位运算将nums分为两组，通过最后两数a^b得不同的二进制位，再根据此位进行分组
    vector<int> solution1(vector<int>& nums) {
      int ab = 0;
      for (int v : nums) ab ^= v;
      // 获取最低的1的位置
      int flag = ab & -ab;
      int a = 0;
      for (int v : nums) {
        if (v & flag) a ^= v;
      }
      return {a, ab ^ a};  // ab ^ a 得到 b
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}