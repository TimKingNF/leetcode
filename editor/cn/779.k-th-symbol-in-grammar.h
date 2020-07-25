//在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。 
//
// 给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始） 
//
// 
//例子: 
//
// 输入: N = 1, K = 1
//输出: 0
//
//输入: N = 2, K = 1
//输出: 0
//
//输入: N = 2, K = 2
//输出: 1
//
//输入: N = 4, K = 5
//输出: 1
//
//解释:
//第一行: 0
//第二行: 01
//第三行: 0110
//第四行: 01101001
// 
//
// 
//注意： 
//
// 
// N 的范围 [1, 30]. 
// K 的范围 [1, 2^(N-1)]. 
// 
// Related Topics 递归

#include "header.h"

namespace LeetCode779 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int kthGrammar(int N, int K) {
      return solution2(N, K);
    }

    // 递归, 会超时
    int solution1(int N, int K) {
      string v = "0";
      while (--N > 0) v = solution1core(v);
      return v[K-1] - '0';
    }

    string solution1core(string s) {
      ostringstream os;
      for (auto v : s) {
        if (v == '0') {
          os.put('0');
          os.put('1');
        } else {
          os.put('1');
          os.put('0');
        }
      }
      return os.str();
    }

    // 递归：根据解析前一行的位来输出下一行的为
    // 第 K 位的父位应该是第 (K+1) / 2 位。如果父位是 0，那么这一位就是 1 - (K%2)。
    // 如果父位是 1，那么这一位就是 K%2。
    int solution2(int N, int K) {
      if (N == 1) return 0;
      // int v = solution2(N-1, (K + 1) / 2);
      // return v ? K % 2 : 1 - K % 2;
      // 以上可以简写为
      return (~K & 1) ^ solution2(N-1, (K + 1) / 2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}