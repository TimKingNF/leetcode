//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 
//
// 上图为 8 皇后问题的一种解法。 
//
// 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。 
//
// 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 示例: 
//
// 输入: 4
//输出: [
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
//解释: 4 皇后问题存在两个不同的解法。
// 
//
// 
//
// 提示： 
//
// 
// 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步
//，可进可退。（引用自 百度百科 - 皇后 ） 
// 
// Related Topics 回溯算法

#include "header.h"

namespace LeetCode51 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      return solution1(n);
    }

    vector<vector<string>> solution1(int n) {
      if (n <= 0) return {};
      vector<vector<string>> ans;
      vector<string> board(n, string(n, '.'));  // 初始化棋盘
      for (int col = 0; col < n; ++col) {
        isOk(0, col, board, ans);  // col 个初始位置都试一遍
        board[0][col] = '.';  // 回撤结果
      }
      return ans;
    }

    // 检查是否可以放置皇后
    void isOk(int row, int col, vector<string>& board, vector<vector<string>>& ans) {
      int n = board.size();
      int leftup = col - 1, rightup = col + 1;
      for (int i = row - 1; i >= 0; --i) {  // 向上检查每一行
        if (board[i][col] == 'Q')  return;  // 说明在之前的行，col列已经放过皇后
        if (leftup >= 0 && board[i][leftup] == 'Q') return;  // 检查左上对角线是否有皇后
        if (rightup < n && board[i][rightup] == 'Q') return;  // 检查右上对角线
        --leftup;
        ++rightup;

        // 更简单的判断对角线是否相同, 如果行互减的绝对值等于列互减的绝对值，说明在一条斜线上
        // 这要求在每一行记录 Q 所在的位置，可以快速判断
      }
      // 该位置可以放皇后
      board[row][col] = 'Q';

      // N皇后放置完毕
      if (row + 1 == board.size()) {
        ans.push_back(board);
        return;
      }

      // 继续检查下一行, cols 个位置是否可以放, 要遍历所有可能的结果
      for (int c = 0; c < n; ++c) {
        isOk(row+1, c, board, ans);
        board[row+1][c] = '.';  // 不管可不可能，都恢复状态
      }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}