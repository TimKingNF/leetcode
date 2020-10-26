//你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。 
//
// 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。 
//
// 
//
// 示例 1： 
//
// 输入：name = "alex", typed = "aaleex"
//输出：true
//解释：'alex' 中的 'a' 和 'e' 被长按。
// 
//
// 示例 2： 
//
// 输入：name = "saeed", typed = "ssaaedd"
//输出：false
//解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
// 
//
// 示例 3： 
//
// 输入：name = "leelee", typed = "lleeelee"
//输出：true
// 
//
// 示例 4： 
//
// 输入：name = "laiden", typed = "laiden"
//输出：true
//解释：长按名字中的字符并不是必要的。
// 
//
// 
//
// 提示： 
//
// 
// name.length <= 1000 
// typed.length <= 1000 
// name 和 typed 的字符都是小写字母。 
// 
//
// 
//
// 
// Related Topics 双指针 字符串 
// 👍 135 👎 0

#include "header.h"

namespace LeetCode925 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
      return solution2(name, typed);
    }

    bool solution1(string name, string typed) {
      // if (name == typed) return true;
      int n = name.size(), m = typed.size();
      if (n > m) return false;  // typed 的长度比 name 长度还要小，一定不是

      int i = 0, j = 0;
      while (j < m) {
        char name_char = name[i];
        int name_count = 1;
        while (++i < n) {
          if (name[i] == name_char) name_count += 1;
          else break;
        }
        char typed_char = typed[j];
        int typed_count = 1;
        while (++j < m) {
          if (typed[j] == typed_char) typed_count += 1;
          else break;
        }
        if (name_char != typed_char || name_count > typed_count) return false;
      }
      return i == n;  // 是否遍历完
    }

    // 在 solution1 的基础上简化一下
    bool solution2(string name, string typed) {
      int i = 0, j = 0;
      int n = name.size(), m = typed.size();
      while (j < m) {
        if (i < n && name[i] == typed[j]) {
          ++i;
          ++j;
        } else if (j > 0 && typed[j] == typed[j-1]) {
          ++j;
        } else {
          return false;
        }
      }
      return i == n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}