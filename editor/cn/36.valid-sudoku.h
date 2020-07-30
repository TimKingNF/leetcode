//判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 
// 
//
// 
//
// 上图是一个部分填充的有效的数独。 
//
// 数独部分空格内已填入了数字，空白格用 '.' 表示。 
//
// 示例 1: 
//
// 输入:
//[
//  ["5","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//]
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//[
//  ["8","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//]
//输出: false
//解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
//     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。 
//
// 说明: 
//
// 
// 一个有效的数独（部分已被填充）不一定是可解的。 
// 只需要根据以上规则，验证已经填入的数字是否有效即可。 
// 给定数独序列只包含数字 1-9 和字符 '.' 。 
// 给定数独永远是 9x9 形式的。 
// 
// Related Topics 哈希表

#include "header.h"

namespace LeetCode36 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      return solution2(board);
    }

    bool solution1(vector<vector<char>>& board) {
      auto valid = [&](vector<int>& line) {
        // 计算 . 的数量
        int count = 0;
        for (int v : line) if (v == '.') count++;
        set<int> line_set(line.begin(), line.end());
        return line_set.size() == (count == 0 ? line.size() : line.size() - count + 1);
      };

      vector<int> cur;
      // 验证横排
      for (int i = 0; i < 9; ++i) {
        cur.clear();
        cur.reserve(9);
        for (int j = 0; j < 9; ++j) cur.push_back(board[i][j]);
        if (!valid(cur)) return false;
      }
      // 验证竖排
      for (int j  = 0; j < 9; ++j) {
        cur.clear();
        cur.reserve(9);
        for (int i = 0; i < 9; ++i) {
          cur.push_back(board[i][j]);
        }
        if (!valid(cur)) return false;
      }
      // 验证九宫
      for (int i = 0; i < 9; ++i) {
        cur.clear();
        cur.reserve(9);
        for (int r = 0; r < 9; ++r) {
          for (int c = 0; c < 9; ++c) {
            if (r / 3 * 3 + c / 3 == i) {
              cur.push_back(board[r][c]);
            }
          }
        }
        if (!valid(cur)) return false;
      }
      return true;
    }

    // 创建3个二维数组，分别用于记录九宫，行和列
    bool solution2(vector<vector<char>>& board) {
      int matrix[9][9] = {};
      int col[9][9] = {};
      int row[9][9] = {};
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          if (board[i][j] == '.') continue;  // 跳过 .
          int index = (i / 3) * 3 + j / 3;  // 计算出九宫第一维索引
          int num = board[i][j] - '0' - 1;  // 再-1 计算得索引
          if (++col[i][num] > 1 || ++row[j][num] > 1 || ++matrix[index][num] > 1) return false;
        }
      }
      return true;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}