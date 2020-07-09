//在一个由小写字母构成的字符串 S 中，包含由一些连续的相同字符所构成的分组。 
//
// 例如，在字符串 S = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。 
//
// 我们称所有包含大于或等于三个连续字符的分组为较大分组。找到每一个较大分组的起始和终止位置。 
//
// 最终结果按照字典顺序输出。 
//
// 示例 1: 
//
// 
//输入: "abbxxxxzzy"
//输出: [[3,6]]
//解释: "xxxx" 是一个起始于 3 且终止于 6 的较大分组。
// 
//
// 示例 2: 
//
// 
//输入: "abc"
//输出: []
//解释: "a","b" 和 "c" 均不是符合要求的较大分组。
// 
//
// 示例 3: 
//
// 
//输入: "abcdddeeeeaabbbcd"
//输出: [[3,5],[6,9],[12,14]] 
//
// 说明: 1 <= S.length <= 1000 
// Related Topics 数组

#include "header.h"

namespace LeetCode830 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
      return solution2(S);
    }

    vector<vector<int>> solution1(string S) {
      vector<vector<int>> ans;
      char cur = S[0];
      int index = 0;
      int len = S.length();
      for (int i = 1; i < len; ++i) {
        if (S[i] != cur) {
          if (i - index >= 3)  // 说明和上一个字符相差3个字符以上
            ans.push_back({index, i - 1});
          index = i;
          cur = S[i];
        }
      }

      // 处理最后一段是连续且超过3个字符的情况
      if (cur == S[len-1] && len - index >= 3)
        ans.push_back({index, len - 1});
      return ans;
    }

    // 使用双指针更容易理解
    vector<vector<int>> solution2(string S) {
       vector<vector<int>> ans;
       for (int i = 0, j = 0, len = S.length(); j < len; ++j) {  // j 记录为区间的右端点
         if (j == len - 1 || S[j+1] != S[i]) {
           if (j - i + 1 >= 3)
             ans.push_back({i, j});
           i = j + 1;
         }
       }
       return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}