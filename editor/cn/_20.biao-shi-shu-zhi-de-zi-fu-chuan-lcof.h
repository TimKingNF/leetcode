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
private:
    int pointer = 0;
public:
    bool isNumber(string s) {
      return solution1(s);
    }

    bool solution1(string s) {
      s = trim(s);
      if (s.length() == 0) return false;

      bool numeric = scanInteger(s);
      if (s[pointer] == '.') {
        ++pointer;
        numeric = scanUnsignedInteger(s) || numeric;
      }

      if (s[pointer] == 'e' || s[pointer] == 'E') {
        ++pointer;
        numeric = numeric && scanInteger(s);
      }
      return numeric && s[pointer] == '\0';
    }

    // 移除字符串首尾空格
    string trim(string s) {
      int i = 0, j = s.length() - 1;
      while (i < s.length() && s[i] == ' ')
        ++i;
      while (j >= 0 && s[j] == ' ')
        --j;
      return s.substr(i, j - i + 1);
    }

  // 扫描，确定字符串是否包含数值
    bool scanInteger(string s) {
      if (pointer < s.length() && (s[pointer] == '+' || s[pointer] == '-'))
        ++pointer;
      return scanUnsignedInteger(s);
    }

    // 扫描，确定字符串是否包含纯数值
    bool scanUnsignedInteger(string s) {
      int pre = pointer;
      while (pointer < s.length() && s[pointer] >= '0' && s[pointer] <= '9') {
        ++pointer;
      }
      return pointer > pre;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}