//
// Created by timking.nf@foxmail.com on 2021/2/28.
//

#ifndef LEETCODE_CIG_1_5002_HPP
#define LEETCODE_CIG_1_5002_HPP

#include "header.h"

namespace CIG_1_5002 {

class Solution {
 public:
  int numSum(string s) {
    int ans = 0;
    int num = 0;  // 当前记录的数
    bool f = true;  // 当前记录数的符号
    int cur = 0;

    for (int i = 0; i < s.size(); ++i) {
      cur = s[i] - '0';
      if (cur < 0 || cur > 9) {  // 非数字
        ans += num;
        num = 0;
        if (s[i] == '-') {
          if (i - 1 >= 0 && s[i-1] == '-') {
            f = !f;  // 避免出现连续3个 - 号
          } else {
            f = false;
          }
        }
      } else {
        num = num * 10 + (f ? cur : -cur);
      }
    }
    ans += num;
    return ans;
  }
};

}

#endif  // LEETCODE_CIG_1_5002_HPP
