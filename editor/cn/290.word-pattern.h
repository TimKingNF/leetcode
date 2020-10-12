//给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。 
//
// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。 
//
// 示例1: 
//
// 输入: pattern = "abba", str = "dog cat cat dog"
//输出: true 
//
// 示例 2: 
//
// 输入:pattern = "abba", str = "dog cat cat fish"
//输出: false 
//
// 示例 3: 
//
// 输入: pattern = "aaaa", str = "dog cat cat dog"
//输出: false 
//
// 示例 4: 
//
// 输入: pattern = "abba", str = "dog dog dog dog"
//输出: false 
//
// 说明: 
//你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。 
// Related Topics 哈希表

#include "header.h"

namespace LeetCode290 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
      return solution1(pattern, s);
    }

    bool solution1(string pattern, string s) {
      unordered_map<string, char> d1;
      unordered_map<char, string> d2;
      istringstream input(s);
      string tmp;
      int cnt = 0;
      while (getline(input, tmp, ' ')) {
        if (d1.count(tmp) && d1[tmp] != pattern[cnt]) return false;
        if (d2.count(pattern[cnt]) && d2[pattern[cnt]] != tmp) return false;
        d1[tmp] = pattern[cnt];
        d2[pattern[cnt]] = tmp;
        ++cnt;
      }
      return cnt == pattern.size();  // 最后cnt要指向末尾
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}