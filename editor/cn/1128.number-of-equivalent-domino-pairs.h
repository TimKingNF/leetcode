//给你一个由一些多米诺骨牌组成的列表 dominoes。 
//
// 如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。 
//
// 形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 
//b==c。 
//
// 在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i,
// j) 的数量。 
//
// 
//
// 示例： 
//
// 输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= dominoes.length <= 40000 
// 1 <= dominoes[i][j] <= 9 
// 
// Related Topics 数组 
// 👍 99 👎 0

#include "header.h"

namespace LeetCode1128 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
      return solution1(dominoes);
    }

    int solution1(vector<vector<int>>& dominoes) {
      int dict[100] = {0};
      for (const auto& e : dominoes) {
        if (e[0] > e[1]) ++dict[e[1] * 10 + e[0]];
        else ++dict[e[0] * 10 + e[1]];
      }

      int ans = 0;
      for (int i = 0; i < 100; ++i) {
        int cnt = dict[i];
        if (cnt != 1) ans += cnt * (cnt - 1) / 2;  // 从 cnt 个中取 2 个，共有几种取法
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}