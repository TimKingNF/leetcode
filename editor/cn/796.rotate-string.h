//给定两个字符串, A 和 B。 
//
// A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后
//，A 能变成B，那么返回True。 
//
// 
//示例 1:
//输入: A = 'abcde', B = 'cdeab'
//输出: true
//
//示例 2:
//输入: A = 'abcde', B = 'abced'
//输出: false 
//
// 注意： 
//
// 
// A 和 B 长度不超过 100。 
// 
// 👍 118 👎 0

#include "header.h"

namespace LeetCode796 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool rotateString(string A, string B) {
      return solution1(A, B);
    }

    // O( N )
    int solution1(string A, string B) {
      if (A.size() != B.size()) return false;
      // 也可以将此处替换为 KMP 算法，一样是 O( N ) 的时间复杂度
      return (A+A).find(B, 0) != string::npos;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}