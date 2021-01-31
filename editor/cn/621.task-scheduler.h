//给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务
//都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。 
//
// 然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。 
//
// 你需要计算完成所有任务所需要的最短时间。 
//
// 
//
// 示例 ： 
//
// 输入：tasks = ["A","A","A","B","B","B"], n = 2
//输出：8
//解释：A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
//     在本示例中，两个相同类型任务之间必须间隔长度为 n = 2 的冷却时间，而执行一个任务只需要一个单位时间，所以中间出现了（待命）状态。 
//
// 
//
// 提示： 
//
// 
// 任务的总个数为 [1, 10000]。 
// n 的取值范围为 [0, 100]。 
// 
// Related Topics 贪心算法 队列 数组

#include "header.h"

namespace LeetCode621 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      return solution2(tasks, n);
    }

    // 贪心
    // 优先将数量多的任务放在前面执行，避免后续在一轮时间分片中出现大量的空闲时间
    // 可以使用堆代替 dict 的排序，但思想还是一样的
    int solution1(vector<char>& tasks, int n) {
      if (tasks.empty()) return 0;
      vector<int> dict(26, 0);
      for (char c : tasks) dict[c - 'A']++;

      sort(dict.begin(), dict.end());
      int ans = 0;
      while (dict[25] > 0) {
        int i = 0;
        // 每个任务都执行一遍，在 n 的时间间隔内
        while (i <= n) {
          if (dict[25] == 0) break;  // 说明所有任务都执行完毕
          if (i < 26 && dict[25 - i] > 0) dict[25-i]--;
          ++ans;
          ++i;
        }
        sort(dict.begin(), dict.end());  // 重新排序，重新考虑当前最大次数的优先安排
      }
      return ans;
    }

    // 填桶的方式
    int solution2(vector<char>& tasks, int n) {
      vector<int> dict(26, 0);
      for (char c : tasks) dict[c - 'A']++;

      sort(dict.begin(), dict.end());
      int max_val = dict[25] - 1;  // 最大任务数量 - 1
      int idle_slots = max_val * n;  // 单考虑最大数量p的任务，则总空闲时间有 (p-1) * n

      for (int i = 24; i >=0 && dict[i] > 0; --i) {  // 考虑其他任务
        idle_slots -= min(dict[i], max_val);  // 如果小于等于 max_val，则说明剩余的空间时间刚好能够放下该任务
      }
      // 最后如果还有剩余的空闲时间，则 任务数量加上空闲时间（ 即有必要的冷却时间 ）
      // 没有空闲时间，则说明所有空闲时间都被填满了，此时则说明执行任务所需的时间就是任务的数量
      return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}