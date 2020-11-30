//给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。 
//
// 如果不能形成任何面积不为零的三角形，返回 0。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：[2,1,2]
//输出：5
// 
//
// 示例 2： 
//
// 输入：[1,2,1]
//输出：0
// 
//
// 示例 3： 
//
// 输入：[3,2,3,4]
//输出：10
// 
//
// 示例 4： 
//
// 输入：[3,6,2,3]
//输出：8
// 
//
// 
//
// 提示： 
//
// 
// 3 <= A.length <= 10000 
// 1 <= A[i] <= 10^6 
// 
// Related Topics 排序 数学 
// 👍 102 👎 0

#include "header.h"

namespace LeetCode976 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
      return solution1(A);
    }

    // 要满足两边之和大于第三边
    // 排序之后，如果 选定最长边，且最长边的后两个数不能满足和大于最长边
    // 则后续的数也都不能满足
    int solution1(vector<int>& A) {
      sort(A.begin(), A.end());
      for (int i = A.size() - 1; i >= 2; --i) {
        if (A[i-2] + A[i-1] > A[i]) {
          return A[i-2] + A[i-1] + A[i];
        }
      }
      return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}