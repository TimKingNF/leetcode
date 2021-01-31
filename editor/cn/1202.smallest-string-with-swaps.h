//给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。 
//
//
// 你可以 任意多次交换 在 pairs 中任意一对索引处的字符。 
//
// 返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。 
//
// 
//
// 示例 1: 
//
// 输入：s = "dcab", pairs = [[0,3],[1,2]]
//输出："bacd"
//解释： 
//交换 s[0] 和 s[3], s = "bcad"
//交换 s[1] 和 s[2], s = "bacd"
// 
//
// 示例 2： 
//
// 输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
//输出："abcd"
//解释：
//交换 s[0] 和 s[3], s = "bcad"
//交换 s[0] 和 s[2], s = "acbd"
//交换 s[1] 和 s[2], s = "abcd" 
//
// 示例 3： 
//
// 输入：s = "cba", pairs = [[0,1],[1,2]]
//输出："abc"
//解释：
//交换 s[0] 和 s[1], s = "bca"
//交换 s[1] 和 s[2], s = "bac"
//交换 s[0] 和 s[1], s = "abc"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10^5 
// 0 <= pairs.length <= 10^5 
// 0 <= pairs[i][0], pairs[i][1] < s.length 
// s 中只含有小写英文字母 
// 
// Related Topics 并查集 数组 
// 👍 129 👎 0

#include "header.h"

namespace LeetCode1202 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      return solution1(s, pairs);
    }

    // dfs
    string solution1(string s, vector<vector<int>>& pairs) {
      vector<vector<int>> g(s.size());
      unordered_set<int> visited;
      vector<int> idx;
      string tmp;

      // 构建邻接数组, 每个下标记录可以转换的下标
      for (const auto& e : pairs) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
      }

      // 构建dfs，用于查找从某个下标出发，可以交换的所有下标
      function<void(int)> dfs = [&](int cur) {
        if (visited.count(cur)) return;
        visited.insert(cur);
        idx.push_back(cur);  // 记录这个连通分量的所有下标
        tmp += s[cur];  // 记录所有字符
        for (int nxt : g[cur]) dfs(nxt);
      };

      // 遍历所有字符，找到所有的连通分量，每个连通分量单独排序，达到局部最优的结果，最后获得字典序最小的字符串
      for (int i = 0; i < s.size(); ++i) {
        if (visited.count(i)) continue;  // 是已经查找过的
        idx.clear();
        tmp.clear();
        dfs(i);  // 查找连通分量，放到 idx 和 tmp 中
        sort(begin(tmp), end(tmp));
        sort(begin(idx), end(idx));
        // 重新放回到字符串中
        for (int k = 0; k < idx.size(); ++k) s[idx[k]] = tmp[k];
      }
      return s;
    }

    // TODO：并查集
  };
//leetcode submit region end(Prohibit modification and deletion)

}