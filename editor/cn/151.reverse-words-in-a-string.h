//给定一个字符串，逐个翻转字符串中的每个单词。 
//
// 
//
// 示例 1： 
//
// 输入: "the sky is blue"
//输出: "blue is sky the"
// 
//
// 示例 2： 
//
// 输入: "  hello world!  "
//输出: "world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 
//
// 示例 3： 
//
// 输入: "a good   example"
//输出: "example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
// 
//
// 
//
// 说明： 
//
// 
// 无空格字符构成一个单词。 
// 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。 
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。 
// 
//
// 
//
// 进阶： 
//
// 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。 
// Related Topics 字符串

#include "header.h"

namespace LeetCode151 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseWords(string s) {
      return solution1(s);
    }

    // 从后往前遍历
    string solution1(string s) {
      string ans;
      int next = -1;
      for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == ' ' && next != -1) {
          ans += s.substr(i+1, next-i) + ' ';
          next = -1;
        } else if (s[i] != ' ' && next == -1) {
          next = i;
        }
      }
      if (next != -1)
        ans += s.substr(0, next+1);  // next是下标，所以要+1
      else if (ans.size() > 0)  // 不满足 next != -1 且最后也没有结果
        ans.erase(ans.end()-1, ans.end());  // 如果没有拼接，则需要去掉最后的空格
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}