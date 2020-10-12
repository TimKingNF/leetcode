//小扣出去秋游，途中收集了一些红叶和黄叶，他利用这些叶子初步整理了一份秋叶收藏集 `leaves`， 字符串 `leaves` 仅包含小写字符 `r` 和 `
//y`， 其中字符 `r` 表示一片红叶，字符 `y` 表示一片黄叶。
//出于美观整齐的考虑，小扣想要将收藏集中树叶的排列调整成「红、黄、红」三部分。每部分树叶数量可以不相等，但均需大于等于 1。每次调整操作，小扣可以将一片红叶替
//换成黄叶或者将一片黄叶替换成红叶。请问小扣最少需要多少次调整操作才能将秋叶收藏集调整完毕。
//
//**示例 1：**
//>输入：`leaves = "rrryyyrryyyrr"`
//>
//>输出：`2`
//>
//>解释：调整两次，将中间的两片红叶替换成黄叶，得到 "rrryyyyyyyyrr"
//
//**示例 2：**
//>输入：`leaves = "ryr"`
//>
//>输出：`0`
//>
//>解释：已符合要求，不需要额外操作
//
//**提示：**
//- `3 <= leaves.length <= 10^5`
//- `leaves` 中只包含字符 `'r'` 和字符 `'y'` 👍 106 👎 0

#include "header.h"

namespace LeetCodeLCP19 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumOperations(string leaves) {
      return solution2(leaves);
    }

    // dp
    // O( N ), O( N )
    int solution1(string leaves) {
      int n = leaves.size();
      // 状态 0: 表示前一部分的红， 1: 黄色， 2: 后一部分的红
      vector<vector<int>> f(n, vector<int>(3));  // 一维表示叶子，二维表示状态
      f[0][0] = (leaves[0] == 'y');  // 第一个叶子，状态需要为0，所以判断 leaves[0] 如果是黄，则需要变
      f[0][1] = f[0][2] = f[1][2] = INT32_MAX;  // 不可能的值

      for (int i = 1; i < n; ++i) {
        int isRed = (leaves[i] == 'r');
        int isYellow = (leaves[i] == 'y');
        f[i][0] = f[i-1][0] + isYellow;  // 如果i叶子状态是0，则前一个叶子状态也必须是0，并判断是否需要变
        f[i][1] = min(f[i-1][0], f[i-1][1]) + isRed;  // 前一个叶子可以是0，1，如果是红则需要变
        if (i >= 2)
          f[i][2] = min(f[i-1][1], f[i-1][2]) + isYellow;
      }
      return f[n-1][2];
    }

    // 对 solution1 做空间优化
    int solution2(string leaves) {
      vector<int> f(3);
      f[0] = (leaves[0] == 'y');
      f[1] = f[2] = 9999; // i 必须大于等于 j + 1
      for (int i = 1; i < leaves.size(); ++i) {
        int isRed = (leaves[i] == 'r');
        int isYellow = (leaves[i] == 'y');
        f[2] = min(f[1], f[2]) + isYellow;
        f[1] = min(f[0], f[1]) + isRed;
        f[0] =  f[0] + isYellow;
      }
      return f[2];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}