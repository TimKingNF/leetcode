//给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。 
//
// 注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct
//-characters 相同 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "bcabc"
//输出："abc"
// 
//
// 示例 2： 
//
// 
//输入：s = "cbacdcbc"
//输出："acdb" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 由小写英文字母组成 
// 
// Related Topics 栈 贪心算法 字符串 
// 👍 285 👎 0

#include "header.h"

namespace LeetCode316 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeDuplicateLetters(string s) {
      return solution1(s);
    }

    // O( N ), O( 1 )
    // 常数阶空间复杂度, 所以是 O( 1 )
    string solution1(string s) {
      string stk;
      int dict[26] = {0};
      set<char> seen;  // 记录已经在 stk 中的字符
      for (char c : s) dict[c - 'a']++;  // 记录每个字符出现的次数

      for (char c : s) {
        if (!seen.count(c)) {  // 如果已经出现过就无需考虑了
          // 如果前一个字符数量还有，并且其大于当前字符，说明有字典序更小的较优解，则移除前一个字符
          while (!stk.empty() && c < stk.back() && dict[stk.back() - 'a'] > 0) {
            seen.erase(stk.back());  // 从 seen 中移除
            stk.pop_back();
          }
          seen.insert(c);
          stk.push_back(c);
        }
        --dict[c - 'a'];
      }
      return stk;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}