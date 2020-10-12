//给定一个正整数，返回它在 Excel 表中相对应的列名称。 
//
// 例如， 
//
//     1 -> A
//    2 -> B
//    3 -> C
//    ...
//    26 -> Z
//    27 -> AA
//    28 -> AB 
//    ...
// 
//
// 示例 1: 
//
// 输入: 1
//输出: "A"
// 
//
// 示例 2: 
//
// 输入: 28
//输出: "AB"
// 
//
// 示例 3: 
//
// 输入: 701
//输出: "ZY"
// 
// Related Topics 数学

#include "header.h"

namespace LeetCode168 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convertToTitle(int n) {
      string ans;
      while (n != 0) {
        n--;  // 因为正向计算+1，所以反过来计算需要-1
        ans.push_back('A' + n % 26);  // 取个位上的数
        n /= 26;  // 移位
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}