//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
//
// 
//
// 示例 1： 
//
// 输入：s = "We are happy."
//输出："We%20are%20happy." 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 10000 
//

#include "header.h"

namespace LeetCode_05 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string replaceSpace(string s) {
      return solution1(s);
    }

    // O(N)
    string solution1(string s) {
      // 预先计算有多少个空格, 计算出新的字符串的长度，然后从后往前替换
      int space_count = 0;
      for (auto c : s) {
        if (c == ' ') ++space_count;
      }
      const char* replacement = "%20";
      string res(s.size() + space_count * 2, ' ');  // 新字符串的长度
      int p = res.size()-1;
      for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != ' ') res[p--] = s[i];
        else {
          res[p--] = '0';
          res[p--] = '2';
          res[p--] = '%';
        }
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}