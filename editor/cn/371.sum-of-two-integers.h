//不使用运算符 + 和 - ，计算两整数 a 、b 之和。 
//
// 示例 1: 
//
// 输入: a = 1, b = 2
//输出: 3
// 
//
// 示例 2: 
//
// 输入: a = -2, b = 3
//输出: 1 
// Related Topics 位运算

#include "header.h"

namespace LeetCode371 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int getSum(int a, int b) {
      return solution1(a, b);
    }

    // TODO
    int solution1(int a, int b) {
      int carry;
      while (b != 0) {
        carry = ((unsigned int) a & b) << 1;  // 进位
        a = a ^ b;  // 做加法之后的数
        b = carry;
      }
      return a;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}