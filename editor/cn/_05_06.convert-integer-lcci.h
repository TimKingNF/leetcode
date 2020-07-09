//整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。 
//
// 示例1: 
//
// 
// 输入：A = 29 （或者0b11101）, B = 15（或者0b01111）
// 输出：2
// 
//
// 示例2: 
//
// 
// 输入：A = 1，B = 2
// 输出：2
// 
//
// 提示: 
//
// 
// A，B范围在[-2147483648, 2147483647]之间 
// 
// Related Topics 位运算

#include "header.h"

namespace LeetCode_05_06 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 461 题的变种, 存在负数的可能，所以需要将 int 转位 unsigned int
    int convertInteger(int A, int B) {
      unsigned int v = (unsigned int) A ^ B;  // 消去相同的位，只保留不同的位
      int ans = 0;
      while (v != 0) {
        v = v & (v - 1);
        ++ans;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}