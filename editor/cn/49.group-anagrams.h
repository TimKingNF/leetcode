//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。 
//
// 示例: 
//
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//] 
//
// 说明： 
//
// 
// 所有输入均为小写字母。 
// 不考虑答案输出的顺序。 
// 
// Related Topics 哈希表 字符串

#include "header.h"

namespace LeetCode49 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      return solution2(strs);
    }

    // 这里的key 不排序，按计数也是可以的
    vector<vector<string>> solution1(vector<string>& strs) {
      unordered_map<string, vector<string>> dict;
      unordered_map<string, vector<string>>::iterator find;
      string cur;
      for (const string& v : strs) {
        cur = v;
        sort(cur.begin(), cur.end());
        find = dict.find(cur);
        if (find != dict.end()) {
          find->second.push_back(v);
        } else dict[cur] = vector<string>{v};
      }
      vector<vector<string>> ans;
      ans.reserve(dict.size());
      for (auto& i : dict) ans.push_back(i.second);
      return ans;
    }

    // 利用下标，这样代码更加简洁
    vector<vector<string>> solution2(vector<string>& strs) {
      vector<vector<string>> ans;
      unordered_map<string, int> dict;  // int 记录 ans 的下标
      string key;
      int idx = 0;
      for (const string& v : strs) {
        key = v;
        sort(key.begin(), key.end());
        if (dict.count(key)) {
          ans[dict[key]].push_back(v);
        } else {
          ans.push_back({v});
          dict[key] = idx++;
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}