//实现 strStr() 函数。 
//
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如
//果不存在，则返回 -1。 
//
// 示例 1: 
//
// 输入: haystack = "hello", needle = "ll"
//输出: 2
// 
//
// 示例 2: 
//
// 输入: haystack = "aaaaa", needle = "bba"
//输出: -1
// 
//
// 说明: 
//
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 
//
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。 
// Related Topics 双指针 字符串

#include "header.h"

namespace LeetCode28 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO: 字符串
    int strStr(string haystack, string needle) {
      return solution2(haystack, needle);
    }

    // 双指针法
    // 最坏时间复杂度为 O((N - L)L)O((N−L)L)，最优时间复杂度为 O(N)O(N). L 为 needle 长度
    // 空间 O(1)
    int solution1(string haystack, string needle) {
      if (needle.size() - haystack.size() > 0) return -1;
      if (needle.empty()) return 0;
      int i = 0, j = 0, ans = -1;
      while (i < haystack.size() && j < needle.size()) {
        if (j == 0) ans = i;  // 每次都记录比较开始的 i 点
        if (haystack[i++] != needle[j++]) {
          j = 0;
          i = ans + 1;  // i 重置回 ans 下一个字符继续比较
        }
        if (j == needle.size()) return ans;  // 如果最后比较完全，则返回 ans
      }
      return -1;
    }

    // Sunday 算法
    // 通过偏移表计算下一步需要移动的最小路径
    // m = needle.size
    // shift[w] = { m - max{i < m|needle[i] = w}   if w in needle
    //            { m + 1                          otherwise
    int solution2(string haystack, string needle) {
      int haystack_size = haystack.size();
      int needle_size = needle.size();
      if (needle_size > haystack_size) return -1;
      if (needle_size == 0) return 0;

      // 计算偏移表，保存 needle 相同字符离尾端的最短距离
      unordered_map<int, int> shift;
      for (int i = 0; i < needle_size; ++i)
        shift[needle[i]] = needle_size - i;

      unordered_map<int, int>::iterator find;
      int idx = 0;
      string cur;
      while (idx + needle_size <= haystack_size) {
        // 匹配从 idx 到 idx + needle_size 是否和 needle 匹配
        cur = haystack.substr(idx, needle_size);
        if (cur == needle) return idx;
        else {
          if (idx + needle_size > haystack_size) return -1;  // 处理边界
          // 在不匹配的情况下，根据下一个字符判断 idx 需要移动多少
          // 这里的移动是为了保证 下一个字符和 needle 中该字符的最后一次出现对齐
          find = shift.find(haystack[idx + needle_size]);
          if (find != shift.end()) {
            idx += find->second;  // 找到了则偏移 shift[w]
          } else {
            idx += needle_size + 1;  // 否则移动全部
          }
        }
      }
      return idx + needle_size >= haystack_size ? -1 : idx;
    }

    // TODO: KMP
    int solution3(string haystack, string needle) {
      int haystack_size = haystack.size();
      int needle_size = needle.size();
      if (needle_size > haystack_size) return -1;
      if (needle_size == 0) return 0;

      return 0;
    }

    // TODO: BM

    // TODO: RK
  };
//leetcode submit region end(Prohibit modification and deletion)

}