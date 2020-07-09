//给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可
//能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。 
//
// 
//
// 示例 1: 
//
// 输入: 12258
//输出: 5
//解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi" 
//
// 
//
// 提示： 
//
// 
// 0 <= num < 231 
// 
//

#include "header.h"

namespace LeetCode_46 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO
    int translateNum(int num) {
      return solution2(num);
    }

    // 使用递归的方式
    int solution1(int num) {
      if (num < 10) return 1;  // 当最后的数字小于10时，只能有一种翻译方式
      // 当最后两位的数字小于10时，或者大于25时，均只有一种翻译方式
      return (num % 100 < 10 || num % 100 > 25) ?
        solution1(num / 10) : solution1(num / 10) + solution1(num / 100);
    }

    // 使用 dp 的方式
    int solution2(int num) {
      if (num < 10) return 1;
      string str_num = to_string(num);
      int len = str_num.size();
      int counts[len];  // 初始化用于存放递推的数组，当前位表示当前共有多少种翻译方式
      int count;
      string digit;

      for (int i = len - 1; i >= 0; --i) {
        count = 0;
        if (i < len - 1) count = counts[i+1];  // 初始值为下一位的基础, 表示当前字符按一位进行翻译
        else count = 1;
        if (i < len - 1) {
          // 取当前位和下一位, 判断是否有两种翻译方式
          digit = str_num.substr(i, 2);
          if (digit >= "10" && digit <= "25") {
            if (i < len - 2) count += counts[i+2];  // 当前位和下一位可以翻译为两次，所以加上两位之后的总翻译次数
            else count += 1;  // 在基础值的基础上加1
          }
        }
        counts[i] = count;
      }
      return counts[0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}