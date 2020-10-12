//设计一种算法，打印 N 皇后在 N × N 棋盘上的各种摆法，其中每个皇后都不同行、不同列，也不在对角线上。这里的“对角线”指的是所有的对角线，不只是平分整
//个棋盘的那两条对角线。 
//
// 注意：本题相对原题做了扩展 
//
// 示例: 
//
//  输入：4
// 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// 解释: 4 皇后问题存在如下两个不同的解法。
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
// Related Topics 回溯算法

#include "header.h"

namespace LeetCode_08_12 {

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