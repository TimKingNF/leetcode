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
      return solution1(strs);
    }

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
};
//leetcode submit region end(Prohibit modification and deletion)

}