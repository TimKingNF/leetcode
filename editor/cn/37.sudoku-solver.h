//编写一个程序，通过已填充的空格来解决数独问题。 
//
// 一个数独的解法需遵循如下规则： 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 
// 
//
// 空白格用 '.' 表示。 
//
// 
//
// 一个数独。 
//
// 
//
// 答案被标成红色。 
//
// Note: 
//
// 
// 给定的数独序列只包含数字 1-9 和字符 '.' 。 
// 你可以假设给定的数独只有唯一解。 
// 给定数独永远是 9x9 形式的。 
// 
// Related Topics 哈希表 回溯算法

#include "header.h"

namespace LeetCode37 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
      return solution1(board);
    }

    void solution1(vector<vector<char>>& board) {
      rows = vector<bitset<9>>(9, bitset<9>());
      cols = vector<bitset<9>>(9, bitset<9>());
      cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

      int cnt = 0;
      for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
          cnt += (board[r][c] == '.');
          if (board[r][c] == '.') continue;
          int n = board[r][c] - '1';
          rows[r] |= (1 << n);  // 在对应位置上记录为 1，表示该行存在该值
          cols[c] |= (1 << n);  // 同上
          cells[r / 3][c / 3] |= (1 << n);
        }
      }
      dfs(board, cnt);
    }

    bitset<9> getPossibleStatus(int x, int y) {
      return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    // 每次都选择 能填数字范围最小的 区域开始填, 这样回溯的次数更小
    vector<int> getNext(vector<vector<char>>& board) {
      vector<int> ret;
      int minCnt = 10;
      for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
          if (board[r][c] != '.') continue;
          auto cur = getPossibleStatus(r, c);
          if (cur.count() >= minCnt) continue;
          ret = {r, c};
          minCnt = cur.count();
          if (minCnt == 1) break;  // 无需再判断，就是最小了
        }
      }
      return ret;
    }

    void fillNum(int x, int y, int n, bool fillFlag) {
      rows[x][n] = (fillFlag) ? 1 : 0;
      cols[y][n] = (fillFlag) ? 1 : 0;
      cells[x/3][y/3][n] = (fillFlag) ? 1: 0;
    }

    bool dfs(vector<vector<char>>& board, int cnt) {
      if (cnt == 0) return true;

      auto next = getNext(board);
      auto bits = getPossibleStatus(next[0], next[1]); // 得到剩下能填的数字，会被标记为1
      for (int n = 0; n < bits.size(); n++) {
        if (!bits.test(n)) continue;  // 不能填的数字，跳过
        fillNum(next[0], next[1], n, true);
        board[next[0]][next[1]] = n + '1';
        if (dfs(board, cnt - 1)) return true;
        board[next[0]][next[1]] = '.';
        fillNum(next[0], next[1], n, false);
      }
      return false;
    }

private:
  vector<bitset<9>> rows;  // [9][9]
  vector<bitset<9>> cols;  // [9][9]
  vector<vector<bitset<9>>> cells;  // [3][3][9]
};
//leetcode submit region end(Prohibit modification and deletion)

}