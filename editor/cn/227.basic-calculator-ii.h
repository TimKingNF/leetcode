//实现一个基本的计算器来计算一个简单的字符串表达式的值。 
//
// 字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格 。 整数除法仅保留整数部分。 
//
// 示例 1: 
//
// 输入: "3+2*2"
//输出: 7
// 
//
// 示例 2: 
//
// 输入: " 3/2 "
//输出: 1 
//
// 示例 3: 
//
// 输入: " 3+5 / 2 "
//输出: 5
// 
//
// 说明： 
//
// 
// 你可以假设所给定的表达式都是有效的。 
// 请不要使用内置的库函数 eval。 
// 
// Related Topics 字符串

#include "header.h"

namespace LeetCode227 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int calculate(string s) {
      return solution1(s);
    }

    int solution1(string s) {
      long res = 0, curRes = 0, num = 0, n = s.size();
      char op = '+';  // 第一个operator 默认为 +，因为第一个数需要加进来
      for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
          num = num * 10 + c - '0';
        }

        if (c == '+' || c == '-' || c == '*' || c == '/' || i == n-1) {
          switch (op) {
            case '+': curRes += num; break;
            case '-': curRes -= num; break;
            case '*': curRes *= num; break;
            case '/': curRes /= num; break;
          }
          if (c == '+' || c == '-' || i == n-1) {
            res += curRes;
            curRes = 0;
          }
          op = c;
          num = 0;
        }
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}