//给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不
//是 4 次，则需要在最终答案中包含该字符 3 次。 
//
// 你可以按任意顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 输入：["bella","label","roller"]
//输出：["e","l","l"]
// 
//
// 示例 2： 
//
// 输入：["cool","lock","cook"]
//输出：["c","o"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 100 
// 1 <= A[i].length <= 100 
// A[i][j] 是小写字母 
// 
// Related Topics 数组 哈希表 
// 👍 131 👎 0

#include "header.h"

namespace LeetCode1002 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
      return solution2(A);
    }

    vector<string> solution1(vector<string>& A) {
      vector<string> ans;
      int n = A.size();
      vector<vector<int>> dict(n, vector<int>(26, 0));

      for (int i = 0; i < n; ++i) {
        for (char c : A[i]) {
          int idx = c - 'a';
          dict[i][idx]++;
        }
      }

      for (int i = 0; i < 26; ++i) {
        bool all = true;
        int v = INT32_MAX;
        for (int j = 0; j < n; ++j) {
          if (dict[j][i] == 0) {
            all = false;
            break;
          } else {
            v = min(v, dict[j][i]);
          }
        }

        if (all) {
          for (int j = 0; j < v; ++j) ans.emplace_back(1, 'a' + i);
        }
      }
      return ans;
    }

    // 在 solution1 的基础上优化内存
    vector<string> solution2(vector<string>& A) {
      vector<string> ans;
      int minfreq[26], freq[26];
      fill(minfreq, minfreq+26, INT32_MAX);
      for (const string& str : A) {
        fill(freq, freq+26, 0);
        for (char c : str) {
          ++freq[c - 'a'];
        }
        // 计算 26 个字符最小值
        for (int i = 0; i < 26; ++i) {
          minfreq[i] = min(minfreq[i], freq[i]);
        }
      }

      for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < minfreq[i]; ++j) ans.emplace_back(1, 'a' + i);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}