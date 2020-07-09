//两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。 
//
// 给出两个整数 x 和 y，计算它们之间的汉明距离。 
//
// 注意： 
//0 ≤ x, y < 231. 
//
// 示例: 
//
// 
//输入: x = 1, y = 4
//
//输出: 2
//
//解释:
//1   (0 0 0 1)
//4   (0 1 0 0)
//       ↑   ↑
//
//上面的箭头指出了对应二进制位不同的位置。
// 
// Related Topics 位运算

#include "header.h"

namespace LeetCode461 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int hammingDistance(int x, int y) {
      int v = x ^ y;  // 消去相同的位，只保留不同的位
      int ans = 0;
      while (v != 0) {
        v = v & (v - 1);
        ++ans;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}