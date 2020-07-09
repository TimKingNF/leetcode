//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。 
//
// 示例 1: 
//
// 输入: 121
//输出: true
// 
//
// 示例 2: 
//
// 输入: -121
//输出: false
//解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 
//
// 示例 3: 
//
// 输入: 10
//输出: false
//解释: 从右向左读, 为 01 。因此它不是一个回文数。
// 
//
// 进阶: 
//
// 你能不将整数转为字符串来解决这个问题吗？ 
// Related Topics 数学

#include "header.h"

namespace LeetCode9 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(int x) {
      return solution2(x);
    }

    bool solution1(int x) {
      // 取上界和下界进行依次比较
      if (x < 0 || (x % 10 == 0 && x != 0)) return false;

      int l, r, div = 1;
      while (x / div > 9) div *= 10;  // 计算出小于x的最大10倍数
      while (x > 0) {
        l = x / div;
        r = x % 10;
        if (l != r) return false;
        x = (x - l * div) / 10;  // 取去掉首位和尾端的 中间数
        div /= 100;
      }
      return true;
    }

    // O(long10 N)
    bool solution2(int x) {
      // 取数的一半进行翻转，和另一半进行比较
      if (x < 0 || (x % 10 == 0 && x != 0)) return false;

      int reverseNumber = 0, i;
      while (x > reverseNumber) {
        reverseNumber = reverseNumber * 10 + x % 10;
        x = x / 10;
      }

      // 如果是奇数，则 reverseNumber 还要再 / 10
      return x == reverseNumber || x == reverseNumber / 10;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}