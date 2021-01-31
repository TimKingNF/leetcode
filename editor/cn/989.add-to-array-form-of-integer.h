//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。 
//
// 给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：A = [1,2,0,0], K = 34
//输出：[1,2,3,4]
//解释：1200 + 34 = 1234
// 
//
// 示例 2： 
//
// 输入：A = [2,7,4], K = 181
//输出：[4,5,5]
//解释：274 + 181 = 455
// 
//
// 示例 3： 
//
// 输入：A = [2,1,5], K = 806
//输出：[1,0,2,1]
//解释：215 + 806 = 1021
// 
//
// 示例 4： 
//
// 输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
//输出：[1,0,0,0,0,0,0,0,0,0,0]
//解释：9999999999 + 1 = 10000000000
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 10000 
// 0 <= A[i] <= 9 
// 0 <= K <= 10000 
// 如果 A.length > 1，那么 A[0] != 0 
// 
// Related Topics 数组 
// 👍 122 👎 0

#include "header.h"

namespace LeetCode989 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
      return solution1(A, K);
    }

    vector<int> solution1(vector<int>& A, int K) {
      // 将 K 转为数组
      vector<int> B;
      while (K != 0) {
        B.emplace_back(K % 10);
        K /= 10;
      }
      reverse(B.begin(), B.end());
      // 取两个数组哪一个长
      if (A.size() < B.size()) swap(A, B);
      int i = A.size() - 1, j = B.size() - 1, carry = 0;
      while (i >= 0) {
        int added = A[i] + (j >= 0 ? B[j] : 0) + carry;
        carry = added / 10;
        A[i] = added % 10;
        --i;
        --j;
      }
      if (carry != 0) {  // 说明需要全部进位
        vector<int> ans(A.size() + 1);
        ans[0] = carry;
        copy(A.begin(), A.end(), ans.begin()+1);
        return ans;
      }
      return A;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}