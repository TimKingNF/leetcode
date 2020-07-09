//输入一个字符串，打印出该字符串中字符的所有排列。 
//
// 
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。 
//
// 
//
// 示例: 
//
// 输入：s = "abc"
//输出：["abc","acb","bac","bca","cab","cba"]
// 
//
// 
//
// 限制： 
//
// 1 <= s 的长度 <= 8 
// Related Topics 回溯算法

#include "header.h"

namespace LeetCode_38 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO
    vector<string> permutation(string s) {
      return solution3(s);
    }

    // O(N!)
    vector<string> solution1(string s) {
      vector<string> ans;
      solution1core(s, &ans);
      return ans;
    }

    void solution1core(string s, vector<string>* ans) {
      if (s.length() <= 1) {
        (*ans).push_back(s);
        return;
      }

      vector<string> tmp_ans;
      string str_sub;
      char c;
      unordered_set<string> ans_set;  // 用一个set来帮助去重
      // 遍历 s 的每个字符, 作为排列的首字符
      for (int i = 0; i < s.size(); ++i) {
        c = s[i];
        // 去掉c 之后的剩下字符串
        str_sub = s.substr(0, i) + s.substr(i+1, s.size()-i-1);
        solution1core(str_sub, &tmp_ans);
        for (string v : tmp_ans) {
          str_sub = c+v;
          if (ans_set.find(str_sub) != ans_set.end())
            continue;
          (*ans).push_back(str_sub);
          ans_set.insert(str_sub);
        }
        tmp_ans.clear();
      }
    }

    // 回溯法 O(N!), 通过set进行剪枝
    vector<string> solution2(string s) {
      set<string> res;
      backtrack(s, 0, res);
      return vector<string>(res.begin(), res.end());
    }

    void backtrack(string s, int start, set<string>& res) {
      if (start == s.size()) {
        res.insert(s);
        return;
      }

      for (int i = start; i < s.size(); ++i) {
        swap(s[i], s[start]);
        backtrack(s, start+1, res);  // 进入下一次决策树
        swap(s[i], s[start]);
      }
    }

    vector<string> solution3(string s) {
      sort(s.begin(), s.end());
      vector<string> ans;
      do {
        cout << s << endl;
        ans.push_back(s);
      } while(next_permutation(s.begin(), s.end()));
      return ans;
    }

    bool next_permutation(string::iterator first, string::iterator last) {
      if (first == last) return false;  // first 为 end
      auto i = last;
      if (first == --i) return false;  // 刚好最后一个元素
      while (true) {
        decltype(i) i1, i2;  // 声明 i1, i2 的类型是 i 的类型
        i1 = i;
        if (*--i < *i1) {
          i2 = last;
          while (!(*i < *--i2)) ;
          iter_swap(i, i2);
          reverse(i1, last);
          return true;
        }
        if (i == first) {
          reverse(first, last);
          return false;
        }
      }
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}