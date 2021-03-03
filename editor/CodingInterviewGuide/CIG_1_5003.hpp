//
// Created by timking.nf@foxmail.com on 2021/2/28.
//

#ifndef LEETCODE_CIG_1_5003_HPP
#define LEETCODE_CIG_1_5003_HPP

#include "header.h"

namespace CIG_1_5003 {

class Solution {
 public:
  string removeKZeros(string s, int k) {
    ostringstream oss;
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        ++count;
      } else {
        if (count != k) {  // 说明之前出现的 k 个0 都要原样写回去
          while (count-- != 0) oss << '0';
        }
        count = 0;
        oss << s[i];  // 不同的字符直接写入
      }
    }
    // 到最后以 0 结尾的情况, 且 count 不为 k，重写回去
    if (count != 0 && count != k) {
      while (count-- != 0) oss << '0';
    }
    return oss.str();
  }
};

}

#endif  // LEETCODE_CIG_1_5003_HPP
