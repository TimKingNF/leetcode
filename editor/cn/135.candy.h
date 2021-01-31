//老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。 
//
// 你需要按照以下要求，帮助老师给这些孩子分发糖果： 
//
// 
// 每个孩子至少分配到 1 个糖果。 
// 相邻的孩子中，评分高的孩子必须获得更多的糖果。 
// 
//
// 那么这样下来，老师至少需要准备多少颗糖果呢？ 
//
// 示例 1: 
//
// 输入: [1,0,2]
//输出: 5
//解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
// 
//
// 示例 2: 
//
// 输入: [1,2,2]
//输出: 4
//解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
//     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。 
// Related Topics 贪心算法 
// 👍 351 👎 0

#include "header.h"

namespace LeetCode135 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int candy(vector<int>& ratings) {
      return solution2(ratings);
    }

    // 两次遍历
    int solution1(vector<int>& ratings) {
      int n = ratings.size();
      vector<int> left(n);
      // 只满足右边孩子大于左边孩子规则, 计算所需糖果
      for (int i = 0; i < n; ++i) {
        if (i > 0 && ratings[i] > ratings[i-1]) {
          left[i] = left[i-1] + 1;
        } else {
          left[i] = 1;
        }
      }
      int right = 0, ans = 0;
      // 满足左边孩子大于右边孩子规则
      for (int i = n - 1; i >= 0; --i) {
        if (i < n-1 && ratings[i] > ratings[i+1]) {
          right++;
        } else {
          right = 1;
        }
        ans += max(left[i], right);
      }
      return ans;
    }

    int solution2(vector<int>& ratings) {
      int n = ratings.size();
      if (n == 0) return 0;
      int ans = 1;
      int inc = 1;  // 最近的递增序列长度
      int dec = 0;  // 当前递减序列长度
      int pre = 1;  // 前一个同学被分配的糖果数
      for (int i = 1; i < n; ++i) {
        if (ratings[i] >= ratings[i-1]) {  // 如果当前同学比上一个同学评分高
          dec = 0;  // 说明处于递增序列中，dec 置 0
          pre = ratings[i] == ratings[i-1] ? 1 : pre + 1;  // 相同为 1， 否则为 pre+1 即可
          ans += pre;  // 加上上一个同学的糖果数
          inc = pre; // 递增序列长度
        } else {
          dec++;
          // 当当前的递减序列长度和上一个递增序列等长时，则我们将最近递增序列的最后一个同学当成
          // 递减序列的最大值，注意，此时该同学的糖果数还是不确定的
          if (dec == inc) dec++;
          ans += dec;  // 在一个递减序列中，有新的最小值出现了，则之前所有在递减序列中的同学都需要增加一个糖果
          pre = 1;  // 在当前递减序列中，给当前同学分配 1 个糖果
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}