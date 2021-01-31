//给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。 
//
// （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。） 
//
// 示例 1: 
//
// 输入: N = 10
//输出: 9
// 
//
// 示例 2: 
//
// 输入: N = 1234
//输出: 1234
// 
//
// 示例 3: 
//
// 输入: N = 332
//输出: 299
// 
//
// 说明: N 是在 [0, 10^9] 范围内的一个整数。 
// Related Topics 贪心算法 
// 👍 141 👎 0

#include "header.h"

namespace LeetCode738 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
      return solution2(N);
    }

    // O( N ), O( 1 )
    int solution1(int N) {
      if (N == 0) return 0;

      int dict[10] = {0};  // N max = 10^9
      int i = 9;
      int minV = 9;  // 在 dict 里的除左边以外的最小值
      int nineIdx = 9;
      while (N > 0) {
        int digit = N % 10;
        N /= 10;
        if (digit <= minV) {
          dict[i] = min(minV, digit);
          minV = dict[i];  // next value must be lower than digit
        } else {  // 当前位上的值，比最小值大，则为了保证连续，不能接受
          dict[i] = digit - 1;
          // 之前的位都可以调整为 9
          for (int j = i + 1; j <= nineIdx; ++j) dict[j] = 9;
          nineIdx = i;
          minV = dict[i];  // reset minV
        }
        --i;
      }
      int ans = 0;
      for (int j = 0; j < 10; ++j) {
        ans *= 10;
        ans += dict[j];
      }
      return ans;
    }

    // O( logN )
    int solution2(int N) {
      string strN = to_string(N);
      int i = 1;
      // 先计算连续递增的长度
      while (i < strN.length() && strN[i - 1] <= strN[i]) {
        i += 1;
      }
      if (i < strN.length()) {  // 处理剩下非连续递增的字符串
        while (i > 0 && strN[i - 1] > strN[i]) {
          strN[i - 1] -= 1;  // 前一位借1
          i -= 1;
        }
        // 剩下的位都重置为 9，则可以保证连续递增
        for (i += 1; i < strN.length(); ++i) {
          strN[i] = '9';
        }
      }
      return stoi(strN);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}