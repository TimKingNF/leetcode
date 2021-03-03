//请你来实现一个 atoi 函数，使其能将字符串转换成整数。 
//
// 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下： 
//
// 
// 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。 
// 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。 
// 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。 
// 
//
// 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。 
//
// 在任何情况下，若函数不能进行有效的转换时，请返回 0 。 
//
// 提示： 
//
// 
// 本题中的空白字符只包括空格字符 ' ' 。 
// 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231, 231 − 1]。如果数值超过这个范围，请返回 INT32_MAX (231
// − 1) 或 INT32_MIN (−231) 。
// 
//
// 
//
// 示例 1: 
//
// 输入: "42"
//输出: 42
// 
//
// 示例 2: 
//
// 输入: "   -42"
//输出: -42
//解释: 第一个非空白字符为 '-', 它是一个负号。
//     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
// 
//
// 示例 3: 
//
// 输入: "4193 with words"
//输出: 4193
//解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
// 
//
// 示例 4: 
//
// 输入: "words and 987"
//输出: 0
//解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
//     因此无法执行有效的转换。 
//
// 示例 5: 
//
// 输入: "-91283472332"
//输出: -2147483648
//解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
//     因此返回 INT32_MIN (−231) 。
// 
// Related Topics 数学 字符串

#include "header.h"

namespace LeetCode8 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int myAtoi(string str) {
      return solution1(str);
    }

    int solution1(string str) {
      int left = 0, flag = 1, len = str.size(), ans = 0;
      // 移除字符串前的空格
      while (left < len && str[left] == ' ') ++left;
      if (left == len) return ans;  // 说明全是空格

      // 允许正负号开头
      if (str[left] == '-') flag = -1;
      if (str[left] == '+' || str[left] == '-') ++left;

      int digit;
      int minDigit = INT32_MAX / 10;  // 扩大到最大位之前
      int minRight = INT32_MAX % 10;  // 在 ans == minDigit 之后所允许的最大位, =7
      for (; left < len && isdigit(str[left]); ++left) {
        digit = str[left] - '0';  // 此位上的数字
        if (ans > minDigit ||
            (ans == minDigit && digit > minRight)) {  // 此时无论如何都为越界
          return flag > 0 ? INT32_MAX : INT32_MIN;
        }
        ans = ans * 10 + digit;
      }
      return flag * ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}