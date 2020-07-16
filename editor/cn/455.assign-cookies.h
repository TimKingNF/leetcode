//假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干
//的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满
//足越多数量的孩子，并输出这个最大数值。 
//
// 注意： 
//
// 你可以假设胃口值为正。 
//一个小朋友最多只能拥有一块饼干。 
//
// 示例 1: 
//
// 
//输入: [1,2,3], [1,1]
//
//输出: 1
//
//解释: 
//你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
//虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
//所以你应该输出1。
// 
//
// 示例 2: 
//
// 
//输入: [1,2], [1,2,3]
//
//输出: 2
//
//解释: 
//你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
//你拥有的饼干数量和尺寸都足以让所有孩子满足。
//所以你应该输出2.
// 
// Related Topics 贪心算法

#include "header.h"

namespace LeetCode455 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      return solution1(g, s);
    }

    // 贪心，每次都从s中找出一块 >= g[i] 的饼干, 优先满足胃口大的孩子
    // 使用双重循环时需要注意分配合适的饼干，即每次循环都找出差值最小的饼干，达到最优分配
    // 直接循环的话会超时，所以使用两次排序，然后采取双指针的方式
    int solution1(vector<int>& g, vector<int>& s) {
      if (s.empty()) return 0;
      sort(g.rbegin(), g.rend());  // 降序
      sort(s.rbegin(), s.rend());
      int ans = 0, i = 0, j = 0;
      while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
          ++ans;
          ++j;
          ++i;
        } else ++i;
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}