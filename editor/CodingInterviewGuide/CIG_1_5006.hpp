//
// Created by timking.nf@foxmail.com on 2021/2/28.
//

#ifndef LEETCODE_CIG_1_5006_HPP
#define LEETCODE_CIG_1_5006_HPP

#include "header.h"

namespace CIG_1_5006 {

class Solution {
 public:
  string replace(string str, string from, string to) {
    ostringstream oss;
    int match = 0, right = 0;
    bool isContinue = false;

    while (right < str.size()) {
      if (str[right] != from[match]) {
        // 如果有未能匹配的，将未能匹配的串写入
        while (match > 0) {
          oss << str[right-match];
          --match;
        }
        oss << str[right];
        isContinue = false;
      } else {
        ++match;
        if (match == from.size()) {  // 说明就此匹配到了
          if (!isContinue) {  // 避免连续出现 from
            oss << to;
            isContinue = true;
          }
          match = 0;
        }
      }
      ++right;
    }

    return oss.str();
  }
};

}

#endif  // LEETCODE_CIG_1_5006_HPP
