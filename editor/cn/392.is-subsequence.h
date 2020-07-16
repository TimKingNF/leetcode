//给定字符串 s 和 t ，判断 s 是否为 t 的子序列。 
//
// 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。 
//
// 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"ae
//c"不是）。 
//
// 示例 1: 
//s = "abc", t = "ahbgdc" 
//
// 返回 true. 
//
// 示例 2: 
//s = "axc", t = "ahbgdc" 
//
// 返回 false. 
//
// 后续挑战 : 
//
// 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码
//？ 
//
// 致谢: 
//
// 特别感谢 @pbrother 添加此问题并且创建所有测试用例。 
// Related Topics 贪心算法 二分查找 动态规划

#include "header.h"

namespace LeetCode392 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isSubsequence(string s, string t) {
      return solution2(s, t);
    }

    // 双指针
    bool solution1(string s, string t) {
      int i = 0, j = 0;
      while (i < s.size() && j < t.size()) {
        if (s[i] == t[j++]) ++i;
      }
      return i == s.size();
    }

    // TODO
    // 对于k10亿，可以先处理长字符串，记录每下一个字符的位置
    bool solution2(string s, string t) {
      t.insert(t.begin(), ' ');
      int t_len = t.size();
      vector<vector<int> > dp(t_len , vector<int>(26, 0));
      int nextPos;
      for (char c = 'a'; c <= 'z'; c++) {
        nextPos = -1; //表示接下来再不会出现该字符
        for (int i = t_len - 1; i>= 0; i--) {  //为了获得下一个字符的位置，要从后往前
          dp[i][c - 'a'] = nextPos;
          if (t[i] == c) nextPos = i;
        }
      }

      int index = 0;
      for (char c : s) {
        index = dp[index][c - 'a'];
        if (index == -1) return false;
      }
      return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}