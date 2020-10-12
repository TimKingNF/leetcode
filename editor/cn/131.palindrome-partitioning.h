//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。 
//
// 返回 s 所有可能的分割方案。 
//
// 示例: 
//
// 输入: "aab"
//输出:
//[
//  ["aa","b"],
//  ["a","a","b"]
//] 
// Related Topics 回溯算法

#include "header.h"

namespace LeetCode131 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> partition(string s) {
      return solution1(s);
    }

    vector<vector<string>> solution1(string s) {
      if (s.empty()) return {};
      vector<vector<string>> ans;
      vector<string> cur;
      solution1core(s, 0, cur, ans);
      return ans;
    }

    void solution1core(string s, int idx, vector<string>& cur, vector<vector<string>>& ans) {
      if (idx >= s.size()) {
        ans.push_back(cur);
        return;
      }

      string tmp;
      for (int i = idx; i < s.size(); ++i) {
        bool isPalindrome = true;
        tmp = s.substr(idx, i-idx+1);
        int size = tmp.size();
        // 判断是否回文
        for (int j = 0; j < size / 2; ++j) {
          if (tmp[j] != tmp[size-j-1]) {
            isPalindrome = false;
            break;
          }
        }
        if (!isPalindrome) continue;
        cur.push_back(tmp);
        solution1core(s, i+1, cur, ans);
        cur.pop_back();
      }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}