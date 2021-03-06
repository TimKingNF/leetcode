//假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。 
//
// 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。 
//
// 示例 1: 
//
// 输入:
//["Shogun", "Tapioca Express", "Burger King", "KFC"]
//["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
//输出: ["Shogun"]
//解释: 他们唯一共同喜爱的餐厅是“Shogun”。
// 
//
// 示例 2: 
//
// 输入:
//["Shogun", "Tapioca Express", "Burger King", "KFC"]
//["KFC", "Shogun", "Burger King"]
//输出: ["Shogun"]
//解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
// 
//
// 提示: 
//
// 
// 两个列表的长度范围都在 [1, 1000]内。 
// 两个列表中的字符串的长度将在[1，30]的范围内。 
// 下标从0开始，到列表的长度减1。 
// 两个列表都没有重复的元素。 
// 
// Related Topics 哈希表

#include "header.h"

namespace LeetCode599 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
      return solution1(list1, list2);
    }

    vector<string> solution1(vector<string>& list1, vector<string>& list2) {
      if (list1.size() > list2.size()) swap(list1, list2);
      unordered_map<string, int> dict;
      for (int i = 0; i < list1.size(); ++i) dict.insert({list1[i], i});  // 用较小的数组构造map
      vector<string> ans;
      int min_index = list1.size() + list2.size() - 2;
      unordered_map<string, int>::iterator find;
      for (int i = 0; i < list2.size(); ++i) {
        find = dict.find(list2[i]);
        if (find != dict.end()) {
          if (find->second + i < min_index) {
            ans.clear();
            ans.push_back(find->first);
            min_index = find->second + i;
          } else if (find->second + i == min_index) ans.push_back(find->first);
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}