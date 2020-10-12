//给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。 
//
// 如果小数部分为循环小数，则将循环的部分括在括号内。 
//
// 示例 1: 
//
// 输入: numerator = 1, denominator = 2
//输出: "0.5"
// 
//
// 示例 2: 
//
// 输入: numerator = 2, denominator = 1
//输出: "2" 
//
// 示例 3: 
//
// 输入: numerator = 2, denominator = 3
//输出: "0.(6)"
// 
// Related Topics 哈希表 数学

#include "header.h"

namespace LeetCode166 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
      return solution1(numerator, denominator);
    }

    string solution1(int numerator, int denominator) {
      if (denominator == 0) return "";
      if (denominator == 1) return to_string(numerator);
      bool sign = true;
      if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
        sign = false;

      long num = abs(numerator);  // 转为负数之后防止溢出
      long denom = abs(denominator);

      string ans;
      ans += (sign ? "" : "-") + to_string(num / denom);  // 整数部分

      // 处理小数部分
      num %= denom;
      if (num == 0) return ans;  // 小数为0 直接返回即可
      ans.push_back('.');

      unordered_map<int, int> dict;
      int idx = ans.size() - 1;  // 获取小数点的下标
      while (num && !dict.count(num)) {  // 余数不为0，且余数还没有出现重复数字
        dict[num] = ++idx;  // 记录每个数字的除数起点位置
        num *= 10;
        ans += to_string(num / denom);
        num %= denom;
      }
      if (dict.count(num)) { // 说明出现了循环余数
        ans.insert(dict[num], "(");
        ans.push_back(')');
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}