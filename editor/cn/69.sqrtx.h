//实现 int sqrt(int x) 函数。 
//
// 计算并返回 x 的平方根，其中 x 是非负整数。 
//
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。 
//
// 示例 1: 
//
// 输入: 4
//输出: 2
// 
//
// 示例 2: 
//
// 输入: 8
//输出: 2
//说明: 8 的平方根是 2.82842..., 
//     由于返回类型是整数，小数部分将被舍去。
// 
// Related Topics 数学 二分查找

#include "header.h"

namespace LeetCode69 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
      return solution2(x);
    }

    int solution1(int x) {
      if (x == 0 || x == 1) return x;
      int l = 0, r = x, middle, ans;
      while (l <= r) {
        middle = (l + r) / 2;
        ans = x / middle;  // 避免越界
        // if (ans == middle) return ans;
        if (ans < middle) r = middle - 1;
        else {
          l = middle + 1;
          ans = middle;  // 如果下一次 middle ^ 2 大于 x，则需要向下取整，故在该轮赋值 ans = middle
        }
      }
      return ans;
    }

    // 数学
    int solution2(int x) {
      if (x == 0) return x;
      int ans = exp(0.5 * log(x));  // 这里可能有两个解 n + 1, n
      return x / (ans+1) >= (ans+1) ? ans + 1 : ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}