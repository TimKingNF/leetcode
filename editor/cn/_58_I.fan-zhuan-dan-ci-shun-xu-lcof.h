//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
//则输出"student. a am I"。 
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
// 注意：本题与主站 151 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/ 
//
//
// 注意：此题对比原题有改动 
// Related Topics 字符串

#include "header.h"

namespace LeetCode_58_I {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseWords(string s) {
      return solution2(s);
    }

    // O(N), O(N)
    // 或者可以采取倒叙遍历的方式，这样可以节省下 stk 空间
    string solution1(string s) {
      stack<string> stk;
      int pre = -1;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ' && pre != -1) {  // 开始截断
          stk.push(s.substr(pre, i-pre));  // 无需+1，因为不包括当前的空格
          pre = -1;
        } else if (s[i] != ' ' && pre == -1) {
          pre = i;  // 记录首个字符的位置
        }
      }
      if (pre != -1)  // 添加最后一个字符串
        stk.push(s.substr(pre, s.size()-pre));
      string ans;
      while (!stk.empty()) {
        ans += stk.top() + ' ';
        stk.pop();
      }
      return ans.substr(0, ans.size()-1);  // 去掉最后的空格
    }

    // 在stack的基础上更简化一下
    // 使用 substr 会多构造一个字符串
    string solution2(string s) {
      stack<string> stk;
      string res, str;
      istringstream ss(s);
      while (ss >> str) stk.push(str);  // 利用 istringstream 进行分割
      while (!stk.empty()) res += stk.top() + ' ', stk.pop();
      res.erase(res.end() - 1, res.end());
      return res;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}