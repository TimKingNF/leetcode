// 仅使用递归函数和栈操作逆序一个栈
//
// Created by timking.nf@foxmail.com on 2021/1/30.
//

#include "header.h"

namespace CIG_1_1003 {

class Solution {
 public:
  void reverse(stack<int>& stk) {
    if (stk.empty()) return;
    int x = getStackBottomItem(stk);  // 获取最底下的元素出栈
    reverse(stk);  // 继续翻转
    stk.push(x);
  }

  int getStackBottomItem(stack<int>& stk) {
    int x = stk.top();
    stk.pop();
    if (stk.empty()) {
      return x;  // 说明 x 就是最底下的元素
    } else {
      int y = getStackBottomItem(stk);  // 继续获取
      stk.push(x);  // 将 x 放回去, 保持原栈
      return y;
    }
  }
};

};
