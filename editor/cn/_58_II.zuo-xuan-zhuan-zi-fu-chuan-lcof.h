//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数
//将返回左旋转两位得到的结果"cdefgab"。 
//
// 
//
// 示例 1： 
//
// 输入: s = "abcdefg", k = 2
//输出: "cdefgab"
// 
//
// 示例 2： 
//
// 输入: s = "lrloseumgh", k = 6
//输出: "umghlrlose"
// 
//
// 
//
// 限制： 
//
// 
// 1 <= k < s.length <= 10000 
// 
// Related Topics 字符串

#include "header.h"

namespace LeetCode_58_II {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseLeftWords(string s, int n) {
      return solution1(s, n);
    }

    string solution1(string s, int n) {
      int len = s.size();
      n = n % len;  // 防止 n > s.length
      if (len == 0 || n == 0) return s;
      // 单独翻转 0,n, n-end
      reverse(s, 0, n-1);
      reverse(s, n, len-1);
      reverse(s, 0, len-1);  // 最后再翻转整个字符串
      return s;
    }

    void reverse(string& s, int left, int right)  {
      while (left < right) swap(s[left++], s[right--]);
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}