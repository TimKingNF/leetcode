//你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
// 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。 
//
// 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。 
//
// 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。 
//
// 字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。 
//
// 
//
// 示例 1: 
//
// 
//输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
//输出：6
//解释：
//可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
//注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
//因为当拨动到 "0102" 时这个锁就会被锁定。
// 
//
// 示例 2: 
//
// 
//输入: deadends = ["8888"], target = "0009"
//输出：1
//解释：
//把最后一位反向旋转一次即可 "0000" -> "0009"。
// 
//
// 示例 3: 
//
// 
//输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], targ
//et = "8888"
//输出：-1
//解释：
//无法旋转到目标数字且不被锁定。
// 
//
// 示例 4: 
//
// 
//输入: deadends = ["0000"], target = "8888"
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// 死亡列表 deadends 的长度范围为 [1, 500]。 
// 目标数字 target 不会在 deadends 之中。 
// 每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。 
// 
// Related Topics 广度优先搜索

#include "header.h"

namespace LeetCode752 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      return solution2(deadends, target);
    }

    // bfs
    int solution1(vector<string>& deadends, string target) {
      set<string> visited;
      for (string v : deadends) visited.insert(v);
      if (visited.find("0000") != visited.end()) return -1;

      string cur, next;
      int level = 0, size;
      deque<string> q;
      q.push_back("0000");
      while (!q.empty()) {
        size = q.size();
        for (int i = 0; i < size; ++i) {
          cur = q.front();
          q.pop_front();
          if (cur == target) return level;

          // 遍历8种可能
          for (int t = -1; t <= 1; t+=2) {
            for (int j = 0; j < 4; ++j) {
              next = rotate(cur, j, t);
              if (visited.find(next) == visited.end()) {
                q.push_back(next);
                visited.insert(next);  // 记录cur已经访问
              }
            }
          }
        }
        ++level;
      }
      return -1;
    }

    // 旋转第i位，step 为 +1 或者 -1
    string rotate(string s, int i, int step) {
      if (s[i] == '9' && step == 1) s[i] = '0';  // 9前拨为0
      else if (s[i] == '0' && step == -1) s[i] = '9';  // 0后拨为9
      else s[i] += step;
      return s;
    }

    // 双向BFS
    // 从起点和终点同时开始计算，直到两边遇到交集停止
    int solution2(vector<string>& deadends, string target) {
      set<string> visited;
      visited.insert(deadends.begin(), deadends.end());
      if (visited.count("0000")) return -1;

      // 使用两个集合
      set<string> q1, q2, tmp;
      int level = 0;
      q1.insert("0000");
      q2.insert(target);

      while (!q1.empty() && !q2.empty()) {
        // 选择一个较小的集合进行扩散
        if (q1.size() > q2.size()) swap(q1, q2);
        // 将q1的节点向周围扩散
        for (string cur : q1) {
          if (visited.count(cur)) continue;  // 跳过已经访问过的
          if (q2.count(cur)) return level;  // 已经到达目标集合
          visited.insert(cur);

          // 遍历8种可能
          for (int t = -1; t <= 1; t+=2) {
            for (int j = 0; j < 4; ++j) {
              char y = (cur[j] - '0' + 10 + t) % 10 + '0';
              string next = cur;
              next[j] = y;
              if (!visited.count(next)) tmp.insert(next);  // 加入到tmp中
            }
          }
        }
        ++level;
        q1 = q2;  // 交换 q1 q2
        q2 = tmp;  // tmp 是下一轮要扩散的节点
        tmp.clear();
      }
      return -1;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}