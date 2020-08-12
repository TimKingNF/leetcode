//编写一个函数，以字符串作为输入，反转该字符串中的元音字母。 
//
// 示例 1: 
//
// 输入: "hello"
//输出: "holle"
// 
//
// 示例 2: 
//
// 输入: "leetcode"
//输出: "leotcede" 
//
// 说明: 
//元音字母不包含字母"y"。 
// Related Topics 双指针 字符串

#include "header.h"

namespace LeetCode345 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseVowels(string s) {
      return solution1(s);
    }

  // 两个元音字母之间交换
  string solution1(string s) {
      // 元音字母
      set<char> keys = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
      int i = 0, j = s.size() - 1;
      while (i < j) {
        if (!keys.count(s[i])) {
          ++i;
          continue;
        }
        if (!keys.count(s[j])) {
          --j;
          continue;
        }
        if (i < j) swap(s[i++], s[j--]);
      }
      return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}