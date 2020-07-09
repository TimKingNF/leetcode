//给定一个整数，编写一个函数来判断它是否是 2 的幂次方。 
//
// 示例 1: 
//
// 输入: 1
//输出: true
//解释: 20 = 1 
//
// 示例 2: 
//
// 输入: 16
//输出: true
//解释: 24 = 16 
//
// 示例 3: 
//
// 输入: 218
//输出: false 
// Related Topics 位运算 数学

#include "header.h"

namespace LeetCode231 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPowerOfTwo(int n) {
      return solution1(n);
    }

    bool solution1(int n) {
      // 是整数，所以不考虑 负数次幂
      return n > 0 && !(n & (n - 1));  // 是2的幂的话，即最低位1应为最高位，消掉最高位之后为0
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}