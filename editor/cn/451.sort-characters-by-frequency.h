//给定一个字符串，请将字符串里的字符按照出现的频率降序排列。 
//
// 示例 1: 
//
// 
//输入:
//"tree"
//
//输出:
//"eert"
//
//解释:
//'e'出现两次，'r'和't'都只出现一次。
//因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
// 
//
// 示例 2: 
//
// 
//输入:
//"cccaaa"
//
//输出:
//"cccaaa"
//
//解释:
//'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
//注意"cacaca"是不正确的，因为相同的字母必须放在一起。
// 
//
// 示例 3: 
//
// 
//输入:
//"Aabb"
//
//输出:
//"bbAa"
//
//解释:
//此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
//注意'A'和'a'被认为是两种不同的字符。
// 
// Related Topics 堆 哈希表

#include "header.h"

namespace LeetCode451 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string frequencySort(string s) {
      return solution1(s);
    }

    // O( 3N ), O( N+1 )
    // 可以尝试在原字符串上输出
    string solution1(string s) {
      int n = s.size(), dict[256] = {0};
      if (n <= 1) return s;
      vector<string> cnt(n+1, "");  // 空出0不使用，极端情况所有字符都是同一个，所以是 n+1
      for (char c : s) ++dict[c];
      // cnt 里记录要输出的字符串
      for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < dict[i]; ++j) cnt[dict[i]] += (char) i;
      }
      ostringstream os;
      for (int i = n; i >= 0; --i) {
        if (cnt[i].size() != 0) {
          os << cnt[i];
        }
      }
      return os.str();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}