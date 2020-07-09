//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。 
//
// 
//
// 示例: 
//
// 输入: a = 1, b = 1
//输出: 2 
//
// 
//
// 提示： 
//
// 
// a, b 均可能是负数或 0 
// 结果不会溢出 32 位整数 
// 
//

#include "header.h"

namespace LeetCode_65 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int add(int a, int b) {
      int sum, carry;  // 和与进位
      do {
        sum = a ^ b;  // 每一位都异或，求出进位之后的数
        carry = ((unsigned int) a & b) << 1;  // 与之后左移1位，求得进位
        a = sum;
        b = carry;
      } while (b != 0);
      return a;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}