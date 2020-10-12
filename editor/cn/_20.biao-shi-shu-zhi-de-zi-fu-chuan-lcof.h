//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"都表示数值，但
//"12e"、"1a3.14"、"1.2.3"、"+-5"、"-1E-16"及"12e+5.4"都不是。 
//
// 
//
// 注意：本题与主站 65 题相同：https://leetcode-cn.com/problems/valid-number/ 
// Related Topics 数学

#include "header.h"

namespace LeetCode_20 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool isNumber(string s) {
    s = trim(s);
    int p = 0;
    bool numeric = scanInteger(s, p);
    if (s[p] == '.') {
      ++p;
      numeric = scanUnsignedInteger(s, p) || numeric;  // 小数点后可以带纯数字
    }
    if (s[p] == 'e' || s[p] == 'E') {
      ++p;
      numeric = numeric && scanInteger(s, p);
    }
    return numeric && p == s.size();
  }

  // 读取包含符号在内的数字
  bool scanInteger(string s, int& p) {
    if (p < s.size() && (s[p] == '+' || s[p] == '-')) ++p;
    return scanUnsignedInteger(s, p);
  }

  // 读取无符号数字
  bool scanUnsignedInteger(string s, int& p) {
    int pre = p;
    while (p < s.size() && isdigit(s[p])) ++p;
    return p > pre;
  }

  string trim(string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j && s[i] == ' ') ++i;
    while (i <= j && s[j] == ' ') --j;
    return s.substr(i, j-i+1);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}