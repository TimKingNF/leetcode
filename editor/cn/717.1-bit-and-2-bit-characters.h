//有两种特殊字符。第一种字符可以用一比特0来表示。第二种字符可以用两比特(10 或 11)来表示。 
//
// 现给一个由若干比特组成的字符串。问最后一个字符是否必定为一个一比特字符。给定的字符串总是由0结束。 
//
// 示例 1: 
//
// 
//输入: 
//bits = [1, 0, 0]
//输出: True
//解释: 
//唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
// 
//
// 示例 2: 
//
// 
//输入: 
//bits = [1, 1, 1, 0]
//输出: False
//解释: 
//唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。
// 
//
// 注意: 
//
// 
// 1 <= len(bits) <= 1000. 
// bits[i] 总是0 或 1. 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode717 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
      return solution2(bits);
    }

    // O(N)
    bool solution1(vector<int>& bits) {
      // 去掉最后一个字符，剩下的字符串也是可以解码的
      int i = 0;
      while (i < bits.size() - 1) {
        // if (bits[i] == 1) i+=2;
        // else ++i;
        i += bits[i] + 1;
      }
      return i == bits.size() - 1;  // 落在最后一位，说明可以解码
    }

    // O(N)
    bool solution2(vector<int>& bits) {
      // 从最后一个0，到倒数第二个0之间的 1的个数 需为偶数, 则可以确认最后一位必定为单字符
      int len = bits.size(), i = len - 2, v = 0;
      while (i >= 0 && bits[i]) {
        v ^= 1;
        --i;
      }
      return v == 0;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}