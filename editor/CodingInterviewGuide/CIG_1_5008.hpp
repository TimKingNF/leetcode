//
// Created by timking.nf@foxmail.com on 2021/2/28.
//

#ifndef LEETCODE_CIG_1_5008_HPP
#define LEETCODE_CIG_1_5008_HPP

#include "header.h"

namespace CIG_1_5008 {

class Solution {
 public:
  char getCharAt(string str, int index) {
    if (str.empty()) return 0;

    char cur = 0;
    int num = 0;
    bool stage = true;  // 遇到字符
    for (int i = 0; i != str.size(); ++i) {
      if (str[i] == '_') {
        stage = !stage;
      } else if (stage) {
        index -= num;
        if (index < 0) return cur;
        cur = str[i];
        num = 0;
      } else {
        num = num * 10 + str[i] - '0';
      }
    }
    return (char) (index - num < 0 ? cur : 0);
  }
};

}

#endif  // LEETCODE_CIG_1_5008_HPP
