//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。 
//
// 说明：本题中，我们将空字符串定义为有效的回文串。 
//
// 示例 1: 
//
// 输入: "A man, a plan, a canal: Panama"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "race a car"
//输出: false
// 
// Related Topics 双指针 字符串

#include "header.h"

namespace LeetCode125 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(string s) {
      return solution3(s);
    }

    // 双指针，遇到非字母数字跳过
    bool solution1(string s) {
      if (s.empty()) return true;
      int left = 0, right = s.size() - 1;

      while (left <= right) {
        while (left <= right && !valid(s[left])) {
          ++left;
        }
        while (left <= right && !valid(s[right])) {
          --right;
        }
        if (left <= right && tolower(s[left]) != tolower(s[right]))
          return false;
        ++left;
        --right;
      }
      return true;
    }

    // 符合大小写字母和数字, 可以用内置函数 isalnum 代替
    bool valid(char c) {
      return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    bool solution2(string s) {
      ostringstream os;
      for (auto v : s) {
        if (isalnum(v)) os.put(tolower(v));
      }
      string oss = os.str();
      int left = 0, right = oss.size() - 1;
      while (left <= right) {
        if (oss[left++] != oss[right--]) return false;
      }
      return true;
    }

    // 方法一 更简洁的写法
    bool solution3(string s) {
      int l = 0, r = s.size() - 1;
      while (l <= r) {
        if (!isalnum(s[l])) {
          ++l;
          continue;
        }
        if (!isalnum(s[r])) {
          --r;
          continue;
        }
        if (tolower(s[l++]) != tolower(s[r--])) return false;
      }
      return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}