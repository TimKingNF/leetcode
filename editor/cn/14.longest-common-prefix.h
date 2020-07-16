//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 示例 1: 
//
// 输入: ["flower","flow","flight"]
//输出: "fl"
// 
//
// 示例 2: 
//
// 输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
// 
//
// 说明: 
//
// 所有输入只包含小写字母 a-z 。 
// Related Topics 字符串

#include "header.h"

namespace LeetCode14 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      return solution3(strs);
    }

    // 暴力解法
    string solution1(vector<string>& strs) {
      if (strs.empty()) return "";
      ostringstream os;
      int i = 0;
      char cur;
      while (i < strs[0].size()) {
        cur = strs[0][i];
        for (auto str : strs)
          if (i == str.size() || cur != str[i]) return os.str();
        os.put(cur);
        ++i;
      }
      return os.str();
    }

    // 排序思路, 对 strs 排序之后比较头尾字符串得 公共前缀即可
    string solution2(vector<string>& strs) {
      if(strs.empty()) return "";
      sort(strs.begin(), strs.end());
      string st = strs.front(), en = strs.back();
      int i, num = min(st.size(), en.size());
      for(i = 0; i < num && st[i] == en[i]; i ++);
      return string(st, 0, i);
    }

    // 在最短字符串长度的基础上 二分，再判断从n到中间位是否相同
    string solution3(vector<string>& strs) {
      if(strs.empty()) return "";
      int min_len = min_element(strs.begin(), strs.end(), [](const string &left, const string &right) {
        return left.size() < right.size();
      })->size();
      int left = 0, right = min_len-1, middle;
      while (left <= right) {
        middle = left + (right - left) / 2;
        if (solution3core(strs, left, middle)) left = middle + 1;
        else right = middle - 1;
      }
      return strs[0].substr(0, left);
    }

    bool solution3core(vector<string>& strs, int start, int end) {
      // 判断从 start 到 end 是否相同
      string s = strs[0];
      string cur;
      for (int i = 1; i < strs.size(); ++i) {
        cur = strs[i];
        for (int j = start; j <= end; ++j) {
          if (cur[j] != s[j]) return false;
        }
      }
      return true;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}