//
// Created by timking.nf@foxmail.com on 2021/2/19.
//

#ifndef LEETCODE_CIG_1_7003_HPP
#define LEETCODE_CIG_1_7003_HPP

#include "header.h"

namespace CIG_1_7003 {

class Solution {
 public:
  int add(int a, int b) {
    int sum = a;
    while (b != 0) {
      sum = a ^ b;
      b = (a & b) << 1;  // 进位
      a = sum;
    }
    return sum;
  }

  // a-b = a+(-b)
  int minus(int a, int b) {
    // 对 b 取反+1 得其补码
    return add(a, negNum(b));
  }

  // a*b = a * (2^0) * b0 + a * (2^1) * b1 + ... + a * (2^31) * b31
  // b(i) 指 b 的第 i 为数
  // 可以使用10进制进行验证
  int multi(int a, int b) {
    int ans = 0;
    while (b != 0) {
      if (b & 1) ans = add(ans, a);
      a <<= 1;
      b >>= 1;
    }
    return ans;
  }

  // 除法是乘法的逆运算
  // TODO
  int divide(int a, int b) {
    if (b == 0) throw invalid_argument("divisor is 0");
    if (a == INT32_MIN && b == INT32_MIN) return 1;
    else if (b == INT32_MIN) return 0;
    else if (a == INT32_MIN) {
      int ans = div(add(a, 1), b);
      return add(ans, div(minus(a, multi(ans, b)), b));
    } else {
      return div(a, b);
    }
  }

 private:
  int negNum(int n) {
    return add(~n, 1);
  }

  bool isNeg(int n) {
    return n < 0;
  }

  int div(int a, int b) {
    int x = isNeg(a) ? negNum(a) : a;  // 转为正数
    int y = isNeg(b) ? negNum(b) : b;
    int ans = 0;
    for (int i = 31; i > -1; i = minus(i, 1)) {
      if ((x >> i) >= y) {
        ans |= (1 << i);
        x = minus(x, y << i);
      }
    }
    return isNeg(a) ^ isNeg(b) ? negNum(ans) : ans;
  }
};

};

#endif  // LEETCODE_CIG_1_7003_HPP
