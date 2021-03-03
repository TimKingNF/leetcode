//
// Created by timking.nf@foxmail.com on 2021/3/1.
//

#ifndef LEETCODE_CIG_1_5010_HPP
#define LEETCODE_CIG_1_5010_HPP

#include "header.h"

namespace CIG_1_5010 {

class Solution {
 public:
  int getIndex(vector<string*>& strs, string* str) {
    if (!str || strs.empty()) return -1;

    int ans = -1, mid;
    int left = 0, right = strs.size()-1;
    int i = 0;
    while (left <= right) {
      mid = (left + right) / 2;
      if (strs[mid] && *strs[mid] == *str) {
        ans = mid;
        right = mid - 1;  // 因为要找最左位置，所以还有继续查找
      } else if (strs[mid]) {
        // 字典序判断左右
        if (*strs[mid] < *str) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else {  // 当前为 空节点
        // 先从右向左，找整个左半区间中第一个不为 nullptr 的值进行比较
        i = mid;
        while (!strs[i] && --i >= left);
        if (i < left || *strs[i] < *str) {  // 说明左半区间没有，或者左半区间最大字符串也小于 str
          left = mid + 1;
        } else {
          ans = *strs[i] == *str ? i : ans;
          right = i - 1;
        }
      }
    }
    return ans;
  }
};

}

#endif  // LEETCODE_CIG_1_5010_HPP
