//我们正在玩一个猜数字游戏。 游戏规则如下： 
//我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。 
//每次你猜错了，我会告诉你这个数字是大了还是小了。 
//你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）： 
//
// -1 : 我的数字比较小
// 1 : 我的数字比较大
// 0 : 恭喜！你猜对了！
// 
//
// 
//
// 示例 : 
//
// 输入: n = 10, pick = 6
//输出: 6 
// Related Topics 二分查找

#include "header.h"

namespace LeetCode374 {

int guess(int num) {
  return num > 6 ? -1 : num < 6 ? 1 : 0;
}

//leetcode submit region begin(Prohibit modification and deletion)
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      int left = 1, right = n, middle, guess_ans;
      while (left <= right) {
        middle = left + (right - left) / 2;
        guess_ans = guess(middle);
        if (guess_ans == 0) return middle;
        if (guess_ans < 0) right = middle - 1;
        else left = middle + 1;
      }
      return -1;  // 无解
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}