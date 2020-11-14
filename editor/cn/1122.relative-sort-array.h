//给你两个数组，arr1 和 arr2， 
//
// 
// arr2 中的元素各不相同 
// arr2 中的每个元素都出现在 arr1 中 
// 
//
// 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末
//尾。 
//
// 
//
// 示例： 
//
// 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
//输出：[2,2,2,1,4,3,3,9,6,7,19]
// 
//
// 
//
// 提示： 
//
// 
// arr1.length, arr2.length <= 1000 
// 0 <= arr1[i], arr2[i] <= 1000 
// arr2 中的元素 arr2[i] 各不相同 
// arr2 中的每个元素 arr2[i] 都出现在 arr1 中 
// 
// Related Topics 排序 数组 
// 👍 113 👎 0

#include "header.h"

namespace LeetCode1122 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
      return solution1(arr1, arr2);
    }

    vector<int> solution1(vector<int>& arr1, vector<int>& arr2) {
      if (arr1.empty()) return {};
      map<int, int> dict;  // 使用 map 保持升序
      // 对arr1计数
      for (int v : arr1) ++dict[v];

      // 原地排序
      int k = 0;
      for (int v : arr2) {
        for (int i = 0; i < dict[v]; ++i) {
          arr1[k++] = v;
        }
        dict.erase(v);  // 删除该元素
      }
      // dict 最后剩余的元素
      for (auto kv : dict) {
        for (int i = 0; i  < kv.second; ++i) {
          arr1[k++] = kv.first;
        }
      }
      return arr1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}