//给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。 
//
// 示例: 
//
// 输入: 13
//输出: 6 
//解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。 
// Related Topics 数学

#include "header.h"

namespace LeetCode233 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDigitOne(int n) {
      if (n <= 0) return 0;

      int high = n / 10, cur = n % 10, low = 0;
      long dight = 1;
      int ans = 0;
      while (high != 0 || cur != 0) {
        if (cur == 0)
          ans += high * dight;
        else if (cur == 1)
          ans += high * dight + low + 1;
        else
          ans += (high + 1) * dight;

        low += cur * dight;
        cur = high % 10;
        high /= 10;
        dight *= 10;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}