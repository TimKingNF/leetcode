//给定一个整数，写一个函数来判断它是否是 3 的幂次方。 
//
// 示例 1: 
//
// 输入: 27
//输出: true
// 
//
// 示例 2: 
//
// 输入: 0
//输出: false 
//
// 示例 3: 
//
// 输入: 9
//输出: true 
//
// 示例 4: 
//
// 输入: 45
//输出: false 
//
// 进阶： 
//你能不使用循环或者递归来完成本题吗？ 
// Related Topics 数学

#include "header.h"

namespace LeetCode326 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPowerOfThree(int n) {
      return solution1(n);
    }

    // int 范围下 3的幂最大为 3^19 = 1162261467, 故只要能被该数整除，即为3的幂次方
    bool solution1(int n) {
      return n > 0 && 1162261467 % n == 0;
    }

    // 或者将 n 转为以 3 为基地的 进制字符串，并符合 1000... 的格式
};
//leetcode submit region end(Prohibit modification and deletion)

}