//给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
// 
//
// 
// 每次转换只能改变一个字母。 
// 转换过程中的中间单词必须是字典中的单词。 
// 
//
// 说明: 
//
// 
// 如果不存在这样的转换序列，返回 0。 
// 所有单词具有相同的长度。 
// 所有单词只由小写字母组成。 
// 字典中不存在重复的单词。 
// 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。 
// 
//
// 示例 1: 
//
// 输入:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]
//
//输出: 5
//
//解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//     返回它的长度 5。
// 
//
// 示例 2: 
//
// 输入:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//
//输出: 0
//
//解释: endWord "cog" 不在字典中，所以无法进行转换。
// Related Topics 广度优先搜索 
// 👍 540 👎 0

#include "header.h"

namespace LeetCode127 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      return solution5(beginWord, endWord, wordList);
    }

    // 会超时
    int solution1(string beginWord, string endWord, vector<string>& wordList) {
      unordered_map<string, int> dict;
      for (auto& word : wordList) {
        dict.insert({word, 0});
      }
      if (!dict.count(endWord)) return 0;  // endWord 不在字典中

      int ans = INT32_MAX;
      dfs(beginWord, endWord, dict, 0, ans);
      return ans == INT32_MAX ? 0 : ans + 1;  // INT32_MAX 说明没有解法，ans 是times，长度需要+1
    }

    bool compareOneChar(const string& first, const string& second) {
      int diff = 0;
      for (int i = 0; i < first.size(); ++i) {
        if (diff > 1) return false;  // 后续没有必要再比较
        if (first[i] != second[i]) ++diff;
      }
      return diff == 1;
    }

    void dfs(const string& beginWord, string cur,
             unordered_map<string, int>& dict, int times, int& ans) {
      if (compareOneChar(cur, beginWord)) {  // 停止条件
        ans = min(times + 1, ans);  // 只需要再变一次
        return;
      }

      dict[cur] = 1;
      // 从 cur 开始倒推，变一个字符，且需要在 dict 中或是 begin word
      for (auto& e : dict) {
        if (e.second != 0) continue;
        if (!compareOneChar(cur, e.first)) continue;  // 不是差距一个字符
        dfs(beginWord, e.first, dict, times+1, ans);  // 下探
      }
      dict[cur] = 0;
    }

    // bfs
    int solution2(string beginWord, string endWord, vector<string>& wordList) {
      unordered_map<string, int> dict;
      for (const auto& word: wordList) dict.insert({word, 0});
      if (!dict.count(endWord)) return 0;

      queue<string> q;
      q.push(beginWord);
      int minlen = 1;
      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
          string word = q.front();
          q.pop();

          string cur = word;
          for (int j = 0; j < word.size(); ++j) {
            char orig_c = word[j];
            for (char c = 'a'; c <= 'z'; ++c) {
              cur[j] = c;
              if (cur == endWord) return minlen + 1;  // 是停止符则返回
              if (dict.count(cur) && dict[cur] == 0) {  // 需要没有使用过的
                q.push(cur);
                dict[cur] = 1;
              }
            }
            cur[j] = orig_c;
          }
        }
        ++minlen;  // 找过一轮
      }
      return 0;
    }

    // 双向bfs
    int solution3(string beginWord, string endWord, vector<string>& wordList) {
      unordered_map<string, int> wordMap;
      for (const auto& word : wordList) wordMap.insert({word, 0});
      if (wordMap.empty() || !wordMap.count(endWord)) return 0;

      unordered_set<string> beginVisited, endVisited;
      beginVisited.insert(beginWord);
      endVisited.insert(endWord);

      // 执行双向 bfs
      int step = 1;
      while (!beginVisited.empty() && !endVisited.empty()) {
        // 优先选择小的哈希表进行扩散，考虑到的情况更少
        if (beginVisited.size() > endVisited.size()) {
          swap(beginVisited, endVisited);
        }

        unordered_set<string> nextLevelVisited;
        for (const auto & word : beginVisited) {
          if (changeWordEveryOneLetter(word, endVisited, wordMap, nextLevelVisited)) {
            return step + 1;
          }
        }

        // 原来的 beginVisited 废弃，从 nextLevelVisited 开始新的双向 BFS
        beginVisited = nextLevelVisited;
        step++;
      }
      return 0;
    }

    bool changeWordEveryOneLetter(string word, unordered_set<string>& endVisited,
                                  unordered_map<string, int>& wordMap,
                                  unordered_set<string>& nextLevelVisited) {
      string cur = word;
      for (int i = 0; i < word.size(); ++i) {
        char orig_c = word[i];
        for (char c = 'a'; c <= 'z'; ++c) {
          if (orig_c == c) continue;
          cur[i] = c;
          if (wordMap.count(cur)) {  // 在字典中
            if (endVisited.count(cur)) return true;  // 说明在 endVisited 集合中存在
            if (wordMap[cur] == 0) {  // 单词还没有被遍历过
              nextLevelVisited.insert(cur);  // 加到下一级遍历中
              wordMap[cur] = 1;  // 记录已经遍历
            }
          }
        }
        cur[i] = orig_c;  // 恢复
      }
      return false;
    }

private:
  unordered_map<string, int> wordId;
  vector<vector<int>> edge;
  int nodeNum = 0;

    void addWord(const string& word) {
      if (!wordId.count(word)) {
        wordId[word] = nodeNum++;
        edge.emplace_back();
      }
    }

    void addEdge(string& word) {
      addWord(word);
      int id1 = wordId[word];
      for (char& it : word) {
        char tmp = it;
        it = '*';
        addWord(word);  // 插入一个字符变为 * 的字符串
        int id2 = wordId[word];
        // 建立双向边，说明它们可以互相转换
        edge[id1].push_back(id2);
        edge[id2].push_back(id1);
        it = tmp;  // 恢复
      }
    }

public:
    // 使用图结构的双向 bfs
    int solution4(string beginWord, string endWord, vector<string>& wordList) {
      for (string& word : wordList) addEdge(word);
      addEdge(beginWord);
      if (!wordId.count(endWord)) return 0;

      vector<int> disBegin(nodeNum, INT32_MAX), disEnd(nodeNum, INT32_MAX);
      int beginId = wordId[beginWord], endId = wordId[endWord];
      disBegin[beginId] = 0;
      disEnd[endId] = 0;
      queue<int> bq, eq;
      bq.push(beginId);
      eq.push(endId);

      while (!bq.empty() && !eq.empty()) {
        int bq_size = bq.size();
        for (int i = 0; i < bq_size; ++i) {
          int nodeBegin = bq.front();
          bq.pop();
          // node 节点到 disEnd 中有距离，说明 node 可以到达 endWord
          if (disEnd[nodeBegin] != INT32_MAX) {
            // 除以2，是因为带 * 的点的存在，会多记一条边
            return (disBegin[nodeBegin] + disEnd[nodeBegin]) / 2 + 1;
          }
          for (int& it : edge[nodeBegin]) {  // 遍历 node 节点可到达的点
            if (disBegin[it] == INT32_MAX) {  // it 点还没有记录离 beginWord 的距离
              disBegin[it] = disBegin[nodeBegin] + 1;
              bq.push(it);
            }
          }
        }

        int eq_size = eq.size();
        for (int i = 0; i < eq_size; ++i) {
          int nodeEnd = eq.front();
          eq.pop();
          if (disBegin[nodeEnd] != INT32_MAX) {
            return (disBegin[nodeEnd] + disEnd[nodeEnd]) / 2 + 1;
          }
          for (int& it : edge[nodeEnd]) {
            if (disEnd[it] == INT32_MAX) {
              disEnd[it] = disEnd[nodeEnd] + 1;
              eq.push(it);
            }
          }
        }
      }
      return 0;
    }

    // 双向 dfs 简洁写法
    int solution5(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> wordSet{wordList.begin(), wordList.end()};
      if (!wordSet.count(endWord)) return 0;

      unordered_set<string> from({beginWord}), to({endWord});
      int ans = 2;  // beginWord 和 endWord 不同，所以最小长度是 2

      while (!from.empty()) {
        unordered_set<string> next;
        // 在 wordSet 中移除已经遍历过的元素
        for (auto& word : from) {
          wordSet.erase(word);
        }

        for (auto& word : from) {
          string cur = word;
          for (int i = 0; i < word.size(); ++i) {
            char orig_c = word[i];
            for (char c = 'a'; c <= 'z'; ++c) {
              cur[i] = c;
              if (!wordSet.count(cur)) continue;
              next.insert(cur);
              if (!to.count(cur)) continue;  // 在 to 中也没有可匹配的
              return ans;
            }
            cur[i] = orig_c;
          }
        }
        from = next;
        if (from.size() > to.size()) swap(from, to);
        ++ans;
      }
      return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}