//给定一个二维网格和一个单词，找出该单词是否存在于网格中。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例: 
//
// board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//
//给定 word = "ABCCED", 返回 true
//给定 word = "SEE", 返回 true
//给定 word = "ABCB", 返回 false 
//
// 
//
// 提示： 
//
// 
// board 和 word 中只包含大写和小写英文字母。 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// 1 <= word.length <= 10^3 
// 
// Related Topics 数组 回溯算法

#include "header.h"

namespace LeetCode79 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      return solution1(board, word);
    }

    bool solution1(vector<vector<char>>& board, string word) {
      int rows = board.size(), cols = board[0].size();
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          if (solution1core(board, word, r, c, 0)) return true;
        }
      }
      return false;
    }

    bool solution1core(vector<vector<char>>& board, string word, int r, int c, int index) {
      int rows = board.size(), cols = board[0].size();
      if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) return false;
      if (index == word.size() - 1) return true;
      // 记录当前位置已被遍历，使用 board 可以节约内存
      char tmp = board[r][c];
      board[r][c] = '/';
      bool found = solution1core(board, word, r+1, c, index+1) ||
        solution1core(board, word, r-1, c, index+1) ||
        solution1core(board, word, r, c+1, index+1) ||
        solution1core(board, word, r, c-1, index+1);
      board[r][c] = tmp;
      return found;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}