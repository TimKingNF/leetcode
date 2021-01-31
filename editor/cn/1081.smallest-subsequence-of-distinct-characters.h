//返回字符串 text 中按字典序排列最小的子序列，该子序列包含 text 中所有不同字符一次。 
//
// 
//
// 示例 1： 
//
// 输入："cdadabcc"
//输出："adbc"
// 
//
// 示例 2： 
//
// 输入："abcd"
//输出："abcd"
// 
//
// 示例 3： 
//
// 输入："ecbacba"
//输出："eacb"
// 
//
// 示例 4： 
//
// 输入："leetcode"
//输出："letcod"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= text.length <= 1000 
// text 由小写英文字母组成 
// 
//
// 
//
// 注意：本题目与 316 https://leetcode-cn.com/problems/remove-duplicate-letters/ 相同 
// Related Topics 栈 贪心算法 字符串 
// 👍 60 👎 0

#include "header.h"

namespace LeetCode1081 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string smallestSubsequence(string s) {
      return solution1(s);
    }

    string solution1(string s) {
      string stk;
      int dict[26] = {0};
      set<char> seen;
      for (char c : s) dict[c-'a']++;

      for (char c : s) {
        if (!seen.count(c)) {
          // 前一个元素的字典续大于后一个元素, 且前一个元素后续还能再出现
          while (!stk.empty() && stk.back() > c && dict[stk.back()-'a'] > 0) {
            seen.erase(stk.back());
            stk.pop_back();
          }
          seen.insert(c);
          stk.push_back(c);
        }
        --dict[c-'a'];
      }
      return stk;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}