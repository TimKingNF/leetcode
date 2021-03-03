//
// Created by timking.nf@foxmail.com on 2021/3/1.
//

#ifndef LEETCODE_CIG_1_5017_HPP
#define LEETCODE_CIG_1_5017_HPP

#include "header.h"

namespace CIG_1_5017 {

class Solution {
 public:
  string getPalindrome(string& str, string& strlps) {
    if (str.empty()) return "";
    // 可以计算出来，2倍的 str长度 - 最长回文子串长度，得到的就是 最后形成回文串的长度
    string ans(2*str.size()-strlps.size(), ' ');

    int i = 0, j = str.size()-1;
    int lpsL = 0, lpsR = strlps.size()-1;
    int ansL = 0, ansR = ans.size()-1;
    int left = 0, right = 0;

    while (lpsL <= lpsR) {
      left = i;
      right = j;
      // 已知 strlps 是回文，分别从 str 左右找到回文的第一个字符
      while (str[i] != strlps[lpsL]) {
        ++i;
      }
      while (str[j] != strlps[lpsR]) {
        --j;
      }
      // 找到之后，将 i 之间的字符 和 j 之后的字符，组合成回文，具体方法是
      // (leftPart + rightPart 逆序) ... (rightPart + leftPart 逆序)
      set(ans, &ansL, &ansR, str, left, right, i, j);

      // 此时 i，j 是 lps 的左右字符，移动下标
      ans[ansL++] = str[i++];
      ans[ansR--] = str[j--];
      lpsL++;
      lpsR--;
    }
    return ans;
  }

  void set(string& ans, int *ansL, int *ansR, string& str, int left, int right,
           int leftEnd, int rightEnd) {
    for (int i = left; i < leftEnd; ++i) {
      ans[(*ansL)++] = ans[(*ansR)--] = str[i];
    }
    for (int i = right; i > rightEnd; --i) {
      ans[(*ansL)++] = ans[(*ansR)--] = str[i];
    }
  }
};

}

#endif  // LEETCODE_CIG_1_5017_HPP
