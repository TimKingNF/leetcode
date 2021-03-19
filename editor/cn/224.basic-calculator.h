//实现一个基本的计算器来计算一个简单的字符串表达式的值。 
//
// 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格 。 
//
// 示例 1: 
//
// 输入: "1 + 1"
//输出: 2
// 
//
// 示例 2: 
//
// 输入: " 2-1 + 2 "
//输出: 3 
//
// 示例 3: 
//
// 输入: "(1+(4+5+2)-3)+(6+8)"
//输出: 23 
//
// 说明： 
//
// 
// 你可以假设所给定的表达式都是有效的。 
// 请不要使用内置的库函数 eval。 
// 
// Related Topics 栈 数学

#include "header.h"

namespace LeetCode224 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int calculate(string s) {
      return solution1(s);
    }

    int solution1(string s) {
      int n = s.size();
      stack<int> nums;
      stack<char> operators;
      bool negative = false;  // 记录下一个数是负数, 这里是将 - 号 转为 + 号，原数变为负数

      for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') continue;

        if (isdigit(s[i])) {  // 如果遇到数字
          int num = s[i] - '0';
          while (i < n && isdigit(s[i+1])) {  // 考虑遇到多位数的情况
            num *= 10;
            num += s[i+1] - '0';
            ++i;
          }
          nums.push(negative ? -num : num);
          negative = false;
        } else if (s[i] == '-') {
          operators.push('+');
          negative = true;
        } else if (s[i] == ')') {  // ), 开始做运算
          while (operators.top() != '(') {
            int second = nums.top();
            nums.pop();
            int first = nums.top();
            nums.pop();
            operators.pop();
            nums.push(first + second);  // 括号内的 - 都被处理为了 + 号。所以直接+ 即可
          }
          operators.pop();  // 弹出 '('

          // 判断 括号表达式 最后的结果值要不要处理为负数
          if (!operators.empty() && operators.top() == '-') {
            int num = nums.top();
            nums.pop();
            nums.push(-num);
            operators.pop();
          }
        } else {
          // 表示括号的表达式最终结果值为负数
          if (s[i] == '(' && (!operators.empty() && negative)) {
            operators.push('-');
            negative = false;
          }
          operators.push(s[i]);  // ( +
        }
      }

      // 如果操作符还有，此时已经不含 括号 和 - 号
      while (!operators.empty() && nums.size() >= 2) {
        int second = nums.top();
        nums.pop();
        int first = nums.top();
        nums.pop();
        operators.pop();
        nums.push(first + second);
      }
      return nums.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}