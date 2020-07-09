//给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。 
//
// 
//示例:
//输入: S = "a1b2"
//输出: ["a1b2", "a1B2", "A1b2", "A1B2"]
//
//输入: S = "3z4"
//输出: ["3z4", "3Z4"]
//
//输入: S = "12345"
//输出: ["12345"]
// 
//
// 注意： 
//
// 
// S 的长度不超过12。 
// S 仅由数字和字母组成。 
// 
// Related Topics 位运算 回溯算法

#include "header.h"

namespace LeetCode784 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
      return solution1(S);
    }

    vector<string> solution1(string S) {
      vector<string> ans;
      ans.push_back(S);
      solution1core(S, S.size()-1, &ans);
      return ans;
    }

    void solution1core(string S, int num, vector<string> *ans) {
      if (num < 0) return;
      if (isdigit(S[num])) return solution1core(S, num - 1, ans);

      vector<string> tmp{(*ans).begin(), (*ans).end()};
      for (auto cur : tmp) {
        if (isalpha(cur[num])) {
          cur[num] ^= 32;  // 大小写转换
          (*ans).push_back(cur);
        }
      }
      solution1core(S, num - 1, ans);
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}