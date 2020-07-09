//编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符。 
// 示例： 
// 输入： a = 1, b = 2
//输出： 2
// 
// Related Topics 位运算 数学

#include "header.h"

namespace LeetCode_16_07 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximum(int a, int b) {
      long k = (((long)a - (long)b) >> 63) & 1;  // a-b 求符号位
      return b * k + a * (1 - k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}