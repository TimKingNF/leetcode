//给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。 
//
// 
//
// 
// 
//
// 示例 1: 
//
// 输入: 5
//输出: 2
//解释: 5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
// 
//
// 示例 2: 
//
// 输入: 1
//输出: 0
//解释: 1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。
// 
//
// 
//
// 注意: 
//
// 
// 给定的整数保证在 32 位带符号整数的范围内。 
// 你可以假定二进制数不包含前导零位。 
// 本题与 1009 https://leetcode-cn.com/problems/complement-of-base-10-integer/ 相同 
// 
// Related Topics 位运算

#include "header.h"

namespace LeetCode476 {

//leetcode submit region   begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO
    int findComplement(int num) {
      return solution2(num);
    }

    int solution1(int num) {
      unsigned int n = num;
      vector<int> tmp;
      int ans = 0;
      while (n != 0) {
        tmp.push_back((n & 1) ^ 1);
        n >>= 1;
      }
      for (int i = tmp.size()-1; i >= 0; --i) {
        ans = tmp[i] ? (ans | 1) : (ans & ~1);  // 置第一位的值为取反之后的数
        if (i > 0) ans <<= 1;  // 最后一位不需要移位
      }
      return ans;
    }

    // 和相同位数1的数异或即为取反
    int solution2(int num) {
      int tmp = 1;
      while (tmp < num) {
        tmp <<= 1;
        tmp += 1;
      }
      return (tmp ^ num);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}