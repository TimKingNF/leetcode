//给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。 
//
// 示例 1： 
//
// 输入: num = 1775(110111011112)
//输出: 8
// 
//
// 示例 2： 
//
// 输入: num = 7(01112)
//输出: 4
// 
// Related Topics 位运算

#include "header.h"

namespace LeetCode_05_03 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reverseBits(int num) {
      return solution1(num);
    }

    // 求 0 两边最大 1 的个数
    int solution1(int num) {
      int pre = 0, next = 0;
      int ans = 0;
      while (num != 0) {
        if (num & 1) {
          ++next;
        } else {
          ans = max(ans, pre + next + 1);
          pre = next;
          next = 0;
        }
        num >>= 1;
      }
      return max(ans, pre + next + 1);
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}