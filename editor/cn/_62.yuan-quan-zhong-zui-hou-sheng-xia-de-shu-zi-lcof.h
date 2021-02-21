//0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。 
//
// 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。 
//
// 
//
// 示例 1： 
//
// 输入: n = 5, m = 3
//输出: 3
// 
//
// 示例 2： 
//
// 输入: n = 10, m = 17
//输出: 2
// 
//
// 
//
// 限制： 
//
// 
// 1 <= n <= 10^5 
// 1 <= m <= 10^6 
// 
//

#include "header.h"

namespace LeetCode_62 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 典型约瑟夫环问题
    int lastRemaining(int n, int m) {
      return solution1(n, m);
    }

    int solution1(int n, int m) {
      if (n < 1 || m < 1) return -1;
      int last = 0;  // last 是最后一轮下标的位置, 为0 ，通过它倒推出在上一轮的位置
      for (int i = 2; i <= n; ++i)
        last = (last + m) % i;  // 下标位置前补上m个元素，再模取 上一轮的个数
      return last;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}