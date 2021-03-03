//
// Created by timking.nf@foxmail.com on 2021/3/1.
//

#ifndef LEETCODE_CIG_1_5012_HPP
#define LEETCODE_CIG_1_5012_HPP

#include "header.h"

namespace CIG_1_5012 {

class Solution {
 public:
  void modify(string& str) {
    if (str.empty()) return;
    int j = str.size() - 1;
    for (int i = str.size()-1; i >= 0; --i) {
      if (str[i] != '*') {
        str[j--] = str[i];
      }
    }
    // j 前面都是 *
    for (; j >= 0;) str[j--] = '*';
  }
};

}

#endif  // LEETCODE_CIG_1_5012_HPP
