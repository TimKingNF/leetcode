//设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。 
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
// Related Topics 位运算

#include "header.h"

namespace LeetCode_17_01 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int add(int a, int b) {
      int sum;
      while (b != 0) {
        sum = a ^ b;  // 得加法之后的每一位的值
        b = ((unsigned int) a & b) << 1; // 得进位值
        a = sum;
      }
      return a;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}