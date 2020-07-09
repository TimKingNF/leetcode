//对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。 
//
// 返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。 
//
// 
//
// 示例 1： 
//
// 输入：str1 = "ABCABC", str2 = "ABC"
//输出："ABC"
// 
//
// 示例 2： 
//
// 输入：str1 = "ABABAB", str2 = "ABAB"
//输出："AB"
// 
//
// 示例 3： 
//
// 输入：str1 = "LEET", str2 = "CODE"
//输出：""
// 
//
// 
//
// 提示： 
//
// 
// 1 <= str1.length <= 1000 
// 1 <= str2.length <= 1000 
// str1[i] 和 str2[i] 为大写英文字母 
// 
// Related Topics 字符串

#include "header.h"

namespace LeetCode1071 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
      return solution1(str1, str2);
    }

    string solution1(string str1, string str2) {
      // 默认都有长度
      // 辗转移除字符串
      if (str2.length() > str1.length())
        swap(str1, str2);

      while (!str2.empty()) {
        // 要移除的字符串第一个字符就不同，说明无解
        if (str1[str1.size() - str2.size()] != str2[0]) return "";
        str1.resize(str1.size() - str2.size());
        if (str2.length() > str1.length())
          swap(str1, str2);
      }
      return str1;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}