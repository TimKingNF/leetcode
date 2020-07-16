//给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。 
//
// 说明：不要使用任何内置的库函数，如 sqrt。 
//
// 示例 1： 
//
// 输入：16
//输出：True 
//
// 示例 2： 
//
// 输入：14
//输出：False
// 
// Related Topics 数学 二分查找

#include "header.h"

namespace LeetCode367 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPerfectSquare(int num) {
      return solution2(num);
    }

    bool solution1(int num) {
      if (num < 2) return true;

      int left = 0, right = num, middle;
      float tmp;
      while (left <= right) {
        middle = left + (right - left) / 2;
        tmp = (float) num / middle;
        if (tmp == middle) return true;
        if (tmp > middle) left = middle + 1;
        else right = middle - 1;
      }
      return false;
    }

    // 数学
    // 开方数可以看为
    // 4 = 1 + 3
    // 16 = 1 + 3 + 5 + 7
    // 25 = 1 + 3 + 5 + 7 + 9
    // 36 = 1 + 3 + 5 + 7 + 9 + 11
    bool solution2(int num) {
      int tmp = 1;
      while (num > 0) {
        num -= tmp;
        tmp += 2;
      }
      return num == 0;
    }

    // TODO 牛顿迭代法
};
//leetcode submit region end(Prohibit modification and deletion)

}