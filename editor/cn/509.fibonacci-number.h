//斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是： 
//
// F(0) = 0, F(1)= 1
//F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
// 
//
// 给定 N，计算 F(N)。 
//
// 
//
// 示例 1： 
//
// 输入：2
//输出：1
//解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
// 
//
// 示例 2： 
//
// 输入：3
//输出：2
//解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
// 
//
// 示例 3： 
//
// 输入：4
//输出：3
//解释：F(4) = F(3) + F(2) = 2 + 1 = 3.
// 
//
// 
//
// 提示： 
//
// 
// 0 ≤ N ≤ 30 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode509 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int fib(int N) {
      return solution2(N);
    }

    // O( N )
    int solution1(int N) {
      if (N == 0) return 0;
      if (N <= 2) return 1;

      int first = 1, second = 1, tmp;
      for (int i = 3; i <= N; ++i) {
        tmp = first;
        first = first + second;
        second = tmp;
      }
      return first;
    }

    // O( logN )
    // 递归式严格遵循 F(N) = F(N-1) + F(N-2), 通过矩阵乘法可以降低复杂度
    // (F(n), F(n-1)) = (F(n-1), F(n-2)) * [a b]
    //                                     [c d]
    // 代入 F(1)=1, F(2)=1, F(3)=2, F(4)=3 得 [1 1]
    //                                       [1 0]
    // 当 n > 2, 原来的公式可以化简为
    // (F(3), F(2)) = (F(2), F(1)) *  [1 1] = (1,1) * [1 1]
    //                                [1 0]           [1 0]
    // (F(4), F(3)) = (F(3), F(2)) *  [1 1] = (1,1) * [1 1] ^ 2
    //                                [1 0]           [1 0]
    // ...
    // (F(n), F(n-1)) = (1,1) * [1 1] ^ n-2
    //                          [1 0]
    // 而求次方本身复杂度最低为 logN
    typedef vector<vector<int>> MatrixT;

    int solution2(int N) {
      if (N < 1) return 0;
      if (N == 1 || N == 2) return 1;
      MatrixT base = {{1,1}, {1,0}};
      MatrixT ans = matrixPower(base, N-2);
      return ans[0][0] + ans[1][0];  // 即最后 (1,1) * []^n-2
    }

    // 矩阵次方计算
    MatrixT matrixPower(MatrixT& m, int n) {
      MatrixT ans(m.size(), vector<int>(m[0].size()));
      for (int i = 0; i < ans.size(); ++i) ans[i][i] = 1;  // 设为单位矩阵

      MatrixT tmp = m;
      for (; n != 0; n >>= 1) {
        if (n & 1) {
          ans = multiMatrix(ans, tmp);
        }
        tmp = multiMatrix(tmp, tmp);
      }
      return ans;
    }

    // 矩阵乘法
    MatrixT multiMatrix(MatrixT& m1, MatrixT& m2) {
      MatrixT ans(m1.size(), vector<int>(m2[0].size()));
      for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
          for (int k = 0; k < m2.size(); ++k) {
            ans[i][j] += m1[i][k] * m2[k][j];
          }
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}