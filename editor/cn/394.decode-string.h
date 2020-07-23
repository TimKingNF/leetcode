//给定一个经过编码的字符串，返回它解码后的字符串。 
//
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。 
//
// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。 
//
// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。 
//
// 
//
// 示例 1： 
//
// 输入：s = "3[a]2[bc]"
//输出："aaabcbc"
// 
//
// 示例 2： 
//
// 输入：s = "3[a2[c]]"
//输出："accaccacc"
// 
//
// 示例 3： 
//
// 输入：s = "2[abc]3[cd]ef"
//输出："abcabccdcdcdef"
// 
//
// 示例 4： 
//
// 输入：s = "abc3[cd]xyz"
//输出："abccdcdcdxyz"
// 
// Related Topics 栈 深度优先搜索

#include "header.h"

namespace LeetCode394 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string decodeString(string s) {
      return solution1(s);
    }

    // 使用栈
    string solution1(string s) {
      int n = s.size();
      if (n == 0) return s;
      stack<string> stk;
      string tmp, cur;
      for (int i = 0; i < n; ++i) {
        if (s[i] == ']') {
          tmp = "";
          while (!stk.empty() && stk.top() != "[") {  // 遍历到 '[' 截止
            tmp = stk.top() + tmp;
            stk.pop();
          }
          cur = tmp;
          stk.pop();  // pop 掉 [ 拿到数字
          for (int j = 1; j < stoi(stk.top()); ++j) cur += tmp;  // repeat次数
          stk.pop();  // pop 掉数字
          stk.push(cur);
        } else if (s[i] - '0' < 10) {
          tmp = s[i];
          // 遍历数字
          while (i + 1 < n && s[i+1] - '0' < 10) {
            tmp += s[++i];
          }
          stk.push(tmp);
        } else stk.push(string(1, s[i]));
      }
      // 此时已经消除所有的 [] , 遍历 stk 即可
      string ans = "";
      while (!stk.empty()) {
        ans = stk.top() + ans;
        stk.pop();
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}