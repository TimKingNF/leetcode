//给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values
//[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。 
//
// 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj =
// ? 的结果作为答案。 
//
// 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。 
//
// 
//
// 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。 
//
// 
//
// 示例 1： 
//
// 
//输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"]
//,["b","a"],["a","e"],["a","a"],["x","x"]]
//输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
//解释：
//条件：a / b = 2.0, b / c = 3.0
//问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
// 
//
// 示例 2： 
//
// 
//输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], quer
//ies = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
//输出：[3.75000,0.40000,5.00000,0.20000]
// 
//
// 示例 3： 
//
// 
//输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a
//","c"],["x","y"]]
//输出：[0.50000,2.00000,-1.00000,-1.00000]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= equations.length <= 20 
// equations[i].length == 2 
// 1 <= Ai.length, Bi.length <= 5 
// values.length == equations.length 
// 0.0 < values[i] <= 20.0 
// 1 <= queries.length <= 20 
// queries[i].length == 2 
// 1 <= Cj.length, Dj.length <= 5 
// Ai, Bi, Cj, Dj 由小写英文字母与数字组成 
// 
// Related Topics 并查集 图 
// 👍 349 👎 0

#include "header.h"

namespace LeetCode399 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
  struct Node {
    string& val;
    explicit Node(string& val): val(val) {}
    unordered_map<string, pair<Node*, double>> dict;
  };
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      return solution1(equations, values, queries);
    }

    vector<double> solution1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      unordered_map<string, Node*> vals;
      string val1, val2;
      for (int i = 0; i < equations.size(); ++i) {
        val1 = equations[i][0];
        val2 = equations[i][1];

        if (!vals.count(val1)) {
          vals[val1] = new Node(val1);
          vals[val1]->dict[val1] = {vals[val1], 1};  // 自己除自己
        }
        if (!vals.count(val2)) {
          vals[val2] = new Node(val2);
          vals[val2]->dict[val2] = {vals[val2], 1};  // 自己除自己
        }

        // v[0] / v[1] = values[i]
        vals[val1]->dict[val2] = {vals[val2], values[i]};
        // v[1] / v[0] = 1 / values[i]
        vals[val2]->dict[val1] = {vals[val1], 1 / values[i]};
      }

      function<void(string&,
                    string&,
                    double&,
                    set<Node*>&,
                    bool&)> dfs = [&](string& first,
                                      string& second,
                                      double& ret,
                                      set<Node*>& visited,
                                      bool& stop) {
        if (!vals.count(first) || !vals.count(second)) return;
        if (stop) return;
        visited.insert(vals[first]);
        if (vals[first]->dict.count(second)) {
          ret *= vals[first]->dict[second].second;
          stop = true;
          return;
        }
        double tmp;
        string a;
        for (auto& v : vals[first]->dict) {
          if (visited.count(v.second.first)) continue;
          tmp = ret;
          ret *= v.second.second;
          a = v.first;
          dfs(a, second, ret, visited, stop);
          if (stop) return;  // 得到结果
          ret = tmp;
        }
      };

      // 求结果
      vector<double> ans(queries.size());
      double ret;
      set<Node*> visited;
      bool stop;
      for (int i = 0; i < queries.size(); ++i) {
        ret = 1;
        stop = false;
        visited.clear();
        dfs(queries[i][0], queries[i][1], ret, visited, stop);
        ans[i] = stop ? ret : -1;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}