//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 
//
// 上图为 8 皇后问题的一种解法。 
//
// 给定一个整数 n，返回 n 皇后不同的解决方案的数量。 
//
// 示例: 
//
// 输入: 4
//输出: 2
//解释: 4 皇后问题存在如下两个不同的解法。
//[
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
// 
//
// 
//
// 提示： 
//
// 
// 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或 N
//-1 步，可进可退。（引用自 百度百科 - 皇后 ） 
// 
// Related Topics 回溯算法 
// 👍 181 👎 0

#include "header.h"

namespace LeetCode52 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int totalNQueens(int n) {
      return solution1(n);
    }

    int solution1(int n) {
      int ans = 0;
      vector<string> boards(n, string(n, '.'));
      for (int i = 0; i < n; ++i) {
        dfs(n, 0, i, boards, ans);  // 尝试要放的位置
      }
      return ans;
    }

    void dfs(int n, int row, int col, vector<string> &boards, int &ans) {
      // 判断 (row, col) 可不可以放
      int l = col - 1, r = col + 1;
      for (int i = row - 1; i >= 0; --i) {
        if (boards[i][col] == 'Q') return;  // 同一列已经放了皇后
        // 斜线上已经放有皇后
        if (l >= 0 && boards[i][l] == 'Q') return;
        if (r < n && boards[i][r] == 'Q') return;
        l--;
        r++;
      }
      // 可以放
      boards[row][col] = 'Q';

      // 如果这段代码放在函数最开始，那么在下探的时候就会重复计算
      // 所以要在此处判断
      if (row + 1 == n) {
        // 说明全部放置完毕
        ans += 1;
        return;
      }

      // 下探
      for (int i = 0; i < n; ++i) {
        dfs(n, row+1, i, boards, ans);
      }
      boards[row][col] = '.';  // backstack
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}