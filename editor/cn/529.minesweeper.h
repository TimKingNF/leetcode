//让我们一起来玩扫雷游戏！ 
//
// 给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）
//地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。 
//
// 现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板： 
//
// 
// 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。 
// 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。 
// 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。 
// 如果在此次点击中，若无更多方块可被揭露，则返回面板。 
// 
//
// 
//
// 示例 1： 
//
// 输入: 
//
//[['E', 'E', 'E', 'E', 'E'],
// ['E', 'E', 'M', 'E', 'E'],
// ['E', 'E', 'E', 'E', 'E'],
// ['E', 'E', 'E', 'E', 'E']]
//
//Click : [3,0]
//
//输出: 
//
//[['B', '1', 'E', '1', 'B'],
// ['B', '1', 'M', '1', 'B'],
// ['B', '1', '1', '1', 'B'],
// ['B', 'B', 'B', 'B', 'B']]
//
//解释:
//
// 
//
// 示例 2： 
//
// 输入: 
//
//[['B', '1', 'E', '1', 'B'],
// ['B', '1', 'M', '1', 'B'],
// ['B', '1', '1', '1', 'B'],
// ['B', 'B', 'B', 'B', 'B']]
//
//Click : [1,2]
//
//输出: 
//
//[['B', '1', 'E', '1', 'B'],
// ['B', '1', 'X', '1', 'B'],
// ['B', '1', '1', '1', 'B'],
// ['B', 'B', 'B', 'B', 'B']]
//
//解释:
//
// 
//
// 
//
// 注意： 
//
// 
// 输入矩阵的宽和高的范围为 [1,50]。 
// 点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。 
// 输入面板不会是游戏结束的状态（即有地雷已被挖出）。 
// 简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。 
// 
// Related Topics 深度优先搜索 广度优先搜索

#include "header.h"

namespace LeetCode529 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
      return solution1(board, click);
    }

    // dfs
    // O( N ), O( N )
    vector<vector<char>> solution1(vector<vector<char>>& board, vector<int>& click) {
      if (board[click[0]][click[1]] == 'M') {
        board[click[0]][click[1]] = 'X';  // 直接点到雷爆炸
      } else {
        solution1core(board, click[1], click[0]);
      }
      return board;
    }

    void solution1core(vector<vector<char>>& board, int curX, int curY) {
      int rows = board.size(), cols = board[0].size();
      if (curX < 0 || curX == cols || curY < 0 || curY == rows) return;
      int bX = curX - 1, bY = curY - 1;

      // 当走到雷时，判断周围一圈是否都已经被挖开, 如果是，则修改雷，结束
      if (board[curY][curX] == 'M') {
        bool flag = true;
        for (int i = 0; i < 9; ++i) {
          if (i == 4) continue;  // 跳过原点
          int nX = bX + i % 3, nY = bY + i / 3;
          if (nX < 0 || nX == cols || nY < 0 || nY == rows) continue;
          if (board[nY][nX] == 'B') {
            flag = false;
            break;
          }
        }
        if (flag) board[curY][curX] = 'X';  // 该雷被挖出
        return;
      }

      if (board[curY][curX] != 'E') return;  // 说明已经走过, B,1-8

      // 当前格子为 E
      // 检查周围8个点是否有雷
      char cnt = '0';
      for (int i = 0; i < 9; ++i) {
        if (i == 4) continue;  // 跳过原点
        int nX = bX + i % 3, nY = bY + i / 3;
        if (nX < 0 || nX == cols || nY < 0 || nY == rows) continue;
        if (board[nY][nX] == 'M') cnt += 1;
      }

      if (cnt == '0') {
        board[curY][curX] = 'B';
        // 如果是空白则继续往相邻8个方向下探
        solution1core(board, curX-1, curY-1);
        solution1core(board, curX, curY-1);
        solution1core(board, curX+1, curY-1);
        solution1core(board, curX-1, curY);
        solution1core(board, curX+1, curY);
        solution1core(board, curX-1, curY+1);
        solution1core(board, curX, curY+1);
        solution1core(board, curX+1, curY+1);
      } else {
        board[curY][curX] = cnt;
        // 如果是数字就没有必要再下探了
      }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
