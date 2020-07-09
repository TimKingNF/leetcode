//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果
//一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。 
//
// [["a","b","c","e"], 
//["s","f","c","s"], 
//["a","d","e","e"]] 
//
// 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。 
//
// 
//
// 示例 1： 
//
// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "A
//BCCED"
//输出：true
// 
//
// 示例 2： 
//
// 输入：board = [["a","b"],["c","d"]], word = "abcd"
//输出：false
// 
//
// 提示： 
//
// 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// 
//
// 注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/ 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode_12 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      return solution1(board, word);
    }

    // 暴力递归解法
    bool solution1(vector<vector<char>>& board, string word) {
      int rows = board.size(), cols = board[0].size();
      // 用一个矩阵记录是否走过
      vector<bool> tracks(rows * cols);
      // 因为可以从任意一格开始，遍历矩阵，找到起点
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          if (board[r][c] == word[0]) {
            tracks[r * cols + c] = true;
            if (solution1core(board, word, tracks, 1, r, c)) {  // 说明能找到
              return true;
            }
            tracks[r * cols + c] = false;
          }
        }
      }
      return false;
    }

    bool solution1core(vector<vector<char>>& board, string word,
                       vector<bool>& tracks, int word_index,
                       int r, int c) {
      if (word_index == word.size()) return true;  // 说明已经全部找到
      int rows = board.size(), cols = board[0].size();
      bool found = false;
      // 从 i, j 开始，判断上下左右是否符合 word 第二个字符，以及是否已经走过
      if (r - 1 >= 0 && !tracks[(r-1) * cols + c] && board[r-1][c] == word[word_index]) {  // 判断上
        tracks[(r-1) * cols + c] = true;
        found = solution1core(board, word, tracks, word_index+1, r-1, c);
        if (!found) tracks[(r-1) * cols + c] = false;  // 如果从上无法找到，则重置该位置
      }
      if (!found && r + 1 < rows && !tracks[(r+1) * cols + c] && board[r+1][c] == word[word_index]) {  // 判断下
        tracks[(r+1) * cols + c] = true;
        found = solution1core(board, word, tracks, word_index+1, r+1, c);
        if (!found) tracks[(r+1) * cols + c] = false;
      }
      if (!found && c - 1 >= 0 && !tracks[r * cols + c - 1] && board[r][c-1] == word[word_index]) {  // 判断左
        tracks[r * cols + c - 1] = true;
        found = solution1core(board, word, tracks, word_index+1, r, c-1);
        if (!found) tracks[r * cols + c - 1] = false;
      }
      if (!found && c + 1 < cols && !tracks[r * cols + c + 1] && board[r][c+1] == word[word_index]) {  // 判断右
        tracks[r * cols + c + 1] = true;
        found = solution1core(board, word, tracks, word_index+1, r, c+1);
        if (!found) tracks[r * cols + c + 1] = false;
      }
      return found;
    }

    // 动态规划

  };
//leetcode submit region end(Prohibit modification and deletion)

}