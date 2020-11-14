//设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。 
//
// 注意: 允许出现重复元素。 
//
// 
// insert(val)：向集合中插入元素 val。 
// remove(val)：当 val 存在时，从集合中移除一个 val。 
// getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。 
// 
//
// 示例: 
//
// // 初始化一个空的集合。
//RandomizedCollection collection = new RandomizedCollection();
//
//// 向集合中插入 1 。返回 true 表示集合不包含 1 。
//collection.insert(1);
//
//// 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
//collection.insert(1);
//
//// 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
//collection.insert(2);
//
//// getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
//collection.getRandom();
//
//// 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
//collection.remove(1);
//
//// getRandom 应有相同概率返回 1 和 2 。
//collection.getRandom();
// 
// Related Topics 设计 数组 哈希表 
// 👍 132 👎 0

#include "header.h"

namespace LeetCode381 {

//leetcode submit region begin(Prohibit modification and deletion)
class RandomizedCollection {
 private:
  unordered_map<int, unordered_set<int>> dict;  // 记录索引
  vector<int> list;  // 记录数字
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
      int idx = list.size();
      list.push_back(val);
      dict[val].insert(idx);
      return dict[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
      if (!dict.count(val)) return false;

      int idx = *(dict[val].begin());  // 要移除元素的下标
      list[idx] = list.back();
      dict[val].erase(idx);  // 这一步利用 set 可以达到 O( 1 ) 的复杂度

      // 移除 set 中记录的下标，替换成 idx
      dict[list[idx]].erase(list.size() - 1);
      if (idx < list.size() - 1) dict[list[idx]].insert(idx);  // 这里避免一种特殊情况，idx 刚好是最后一个元素

      if (dict[val].empty()) dict.erase(val);
      list.pop_back();
      return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
      return list[rand() % list.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
//leetcode submit region end(Prohibit modification and deletion)

}