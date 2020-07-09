//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 注意空字符串可被认为是有效字符串。 
//
// 示例 1: 
//
// 输入: "()"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "()[]{}"
//输出: true
// 
//
// 示例 3: 
//
// 输入: "(]"
//输出: false
// 
//
// 示例 4: 
//
// 输入: "([)]"
//输出: false
// 
//
// 示例 5: 
//
// 输入: "{[]}"
//输出: true 
// Related Topics 栈 字符串

#include "header.h"

namespace LeetCode20 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
      if (s.length() & 1) return false;  // 奇数必然为false
      stack<char> stk;
      unordered_map<char, char> tmp;
      tmp.insert(pair<char, char>('}', '{'));
      tmp.insert(pair<char, char>(')', '('));
      tmp.insert(pair<char, char>(']', '['));

      for (char c : s) {
        if (!stk.empty() && tmp.find(c) != tmp.end()) {
          if (stk.top() != tmp[c]) return false;  // 如果find的元素的值不为 stk.top, 说明不是对应括号
          stk.pop();
        } else {
          stk.push(c);
        }
      }
      return stk.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}