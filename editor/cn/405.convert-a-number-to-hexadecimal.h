//给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。 
//
// 注意: 
//
// 
// 十六进制中所有字母(a-f)都必须是小写。 
// 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
// 给定的数确保在32位有符号整数范围内。 
// 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。 
// 
//
// 示例 1： 
//
// 
//输入:
//26
//
//输出:
//"1a"
// 
//
// 示例 2： 
//
// 
//输入:
//-1
//
//输出:
//"ffffffff"
// 
// Related Topics 位运算

#include "header.h"

namespace LeetCode405 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string toHex(int num) {
      return solution2(num);
    }

    string solution1(int num) {
      if (num == 0) return "0";
      char dict[16];
      for (int i = 0; i < 10; ++i) {
        dict[i] = (char) (48 + i);  // 0 的ascii为48
      }
      for (int i = 10; i < 16; ++i) {
        dict[i] = (char) (87 + i);  // a 的ascii 为97
      }
      string ans = "";
      char cur;
      unsigned int n = num;
      // 最后一位是符号位
      while (n != 0) {
        cur = dict[n & 0xf];
        n >>= 4;
        ans = cur + ans;
      }
      return ans;
    }

    string solution2(int num) {
      if (num == 0) return "0";
      string dict = "0123456789abcdef";
      string ans;
      unsigned int n = num;
      while (n != 0) {
        ans.push_back(dict[n & 0xf]);
        n >>= 4;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}