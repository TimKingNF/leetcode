//给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i
//+1]×…×A[n-1]。不能使用除法。 
//
// 
//
// 示例: 
//
// 输入: [1,2,3,4,5]
//输出: [120,60,40,30,24] 
//
// 
//
// 提示： 
//
// 
// 所有元素乘积之和不会溢出 32 位整数 
// a.length <= 100000 
// 
//

#include "header.h"

namespace LeetCode_66 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
      return solution2(a);
    }

    vector<int> solution1(vector<int>& a) {
      if (a.empty()) return {};

      int len = a.size();
      vector<int> tmp(len);  // 辅助数组
      vector<int> ans(len);
      // 从后往前乘，直到第一个数
      for (int i = len - 1, product = 1; i > 0; --i) {
        product = product * a[i];
        tmp[i] = product;
      }
      tmp[0] = a[0];
      ans[0] = tmp[1];
      for (int i = 1; i < len - 1; ++i) {
        tmp[i] = tmp[i-1] * a[i];  // 覆盖掉原来的值，记录从左到右的乘积
        ans[i] = tmp[i+1] * tmp[i-1];
      }
      ans[len-1] = tmp[len-2];  // 记录最后一位
      return ans;
    }

    vector<int> solution2(vector<int>& a) {
      int tmp = 1, n = a.size();
      vector<int> ans(n, 1);
      for (int i = 0; i < n - 1; ++i)
        ans[i + 1] = tmp *= a[i];

      tmp = 1;
      for (int i = n - 2; i >= 0; --i)
        ans[i] *= tmp *= a[i + 1];
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}