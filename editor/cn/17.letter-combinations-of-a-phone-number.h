//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 示例: 
//
// 输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 
//
// 说明: 
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。 
// Related Topics 字符串 回溯算法

#include "header.h"

namespace LeetCode17 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
      return solution2(digits);
    }

    vector<string> solution1(string digits) {
      if (digits.empty()) return {};
      vector<string> ans;
      vector<string> vec{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      vector<string> charLists;
      for (char digit : digits) charLists.push_back(vec[digit - '0' - 2]);
      int n = charLists.size();
      vector<int> idxs(n, -1);
      solution1core(charLists, idxs, ans);
      return ans;
    }

    void solution1core(vector<string>& charLists, vector<int>& idxs, vector<string>& ans) {
      if (idxs.back() != -1) {
        string line;
        for (int i = 0; i < idxs.size(); ++i) line += charLists[i][idxs[i]];
        ans.push_back(line);
        return;
      }

      // 拿到第一个为 -1 的下标
      int first_idx = 0;
      for (int i = 0; i < idxs.size(); ++i) {
        if (idxs[i] == -1) {
          first_idx = i;
          break;
        }
      }
      // 继续从 first_idx 的对应的字符串开始取
      for (int i = 0; i < charLists[first_idx].size(); ++i) {  // 注意是取如 abc 各个字符
        idxs[first_idx] = i;
        solution1core(charLists, idxs, ans);
        idxs[first_idx] = -1;  // 撤销还原
      }
    }

    // 将代码更精简一番
    vector<string> solution2(string digits) {
      if (digits.empty()) return {};
      vector<string> dict{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      vector<string> ans;
      solution2core(digits, 0, "", dict, ans);
      return ans;
    }

    void solution2core(string digits, int idx, string path, vector<string>& dict, vector<string>& ans) {
      if (idx == digits.size()) {
        ans.push_back(path);
        return;
      }
      for (auto c : dict[digits[idx]-'0'-2])
        solution2core(digits, idx+1, path + c, dict, ans);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}