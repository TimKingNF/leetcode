//
// Created by timking.nf@foxmail.com on 2021/2/28.
//

#ifndef LEETCODE_CIG_1_5007_HPP
#define LEETCODE_CIG_1_5007_HPP

#include "header.h"

namespace CIG_1_5007 {

class Solution {
 public:
  string getCountString(string str) {
    if (str.empty()) return "";
    ostringstream os;
    int cnt = 1;
    for (int i = 1; i < str.size(); ++i) {
      if (str[i] == str[i-1]) ++cnt;
      else {
        os << str[i-1] << '_' << cnt << '_';
        cnt = 1;
      }
    }
    // 写入最后一个字符
    os << str[str.size()-1] << '_' << cnt;
    return os.str();
  }
};

}

#endif  // LEETCODE_CIG_1_5007_HPP
