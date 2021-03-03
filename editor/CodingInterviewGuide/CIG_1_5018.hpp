//
// Created by timking.nf@foxmail.com on 2021/3/1.
//

#ifndef LEETCODE_CIG_1_5018_HPP
#define LEETCODE_CIG_1_5018_HPP

#include "header.h"

namespace CIG_1_5018 {

class Solution {
 public:
  bool isValid(string& str) {
    if (str.empty()) return false;

    int cnt = 0;
    for (auto c : str) {
      if (c == '(') {
        cnt++;
      } else if (c == ')') {  // 出现一个 ）对应 cnt --
        if (--cnt < 0) return false;
      } else {  // 不能出现除 () 以外的字符
        return false;
      }
    }
    return cnt == 0;
  }
};

}

#endif  // LEETCODE_CIG_1_5018_HPP
