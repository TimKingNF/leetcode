//不使用任何内建的哈希表库设计一个哈希集合 
//
// 具体地说，你的设计应该包含以下的功能 
//
// 
// add(value)：向哈希集合中插入一个值。 
// contains(value) ：返回哈希集合中是否存在这个值。 
// remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。 
// 
//
// 
//示例: 
//
// MyHashSet hashSet = new MyHashSet();
//hashSet.add(1);         
//hashSet.add(2);         
//hashSet.contains(1);    // 返回 true
//hashSet.contains(3);    // 返回 false (未找到)
//hashSet.add(2);          
//hashSet.contains(2);    // 返回 true
//hashSet.remove(2);          
//hashSet.contains(2);    // 返回  false (已经被删除)
// 
//
// 
//注意： 
//
// 
// 所有的值都在 [0, 1000000]的范围内。 
// 操作的总数目在[1, 10000]范围内。 
// 不要使用内建的哈希集合库。 
// 
// Related Topics 设计 哈希表

#include "header.h"

namespace LeetCode705 {

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int val): val(val), next(nullptr) {};
};

//leetcode submit region begin(Prohibit modification and deletion)
class MyHashSet {
 private:
  vector<ListNode*> _set;
  int capacity = 10001;  // 直接调大数量，避免rehash
  int _has_count;  // 表示桶里已经有值的key数量
  int _max_length = 8;  // 链表长度超过该值则需要扩容

  int hash(int key) {
    return key % capacity;
  }

  void rehash(bool ignore_capacity) {
    if (!ignore_capacity && _has_count < 0.75 * capacity) return;
    // cout << "rehash. now _has_count=" << _has_count << endl;
    auto origSet = _set;
    capacity *= 2;
    _has_count = 0;
    _set = vector<ListNode*>(capacity, nullptr);
    for (auto cur : origSet) {
      while (cur) {
        add(cur->val);
        cur = cur->next;
      }
    }
  }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
      _has_count = 0;
      _set = vector<ListNode*>(capacity, nullptr);
    }
    
    void add(int key) {
      int hash_key = hash(key);
      if (!_set[hash_key]) {
        _set[hash_key] = new ListNode(key);
        ++_has_count;
        rehash(false);
      } else {
        ListNode *cur = _set[hash_key];
        if (cur->val == key) return;
        int count = 1;
        while (cur->next) {
          if (cur->next->val == key) return;  // 已经在集合中存在
          cur = cur->next;
          ++count;
        }
        // 在tail后面追加
        cur->next = new ListNode(key);
        if (++count > _max_length) rehash(true);  // 超过了链表最大长度，需要扩容
      }
    }
    
    void remove(int key) {
      int hash_key = hash(key);
      if (!_set[hash_key]) return;
      ListNode *cur = _set[hash_key], *dummy = new ListNode(-1), *pre = dummy;
      pre->next = cur;
      while (cur) {
        if (cur->val == key) {
          pre->next = cur->next;
          break;
        }
        pre = cur;
        cur = cur->next;
      }
      _set[hash_key] = dummy->next;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
      int hash_key = hash(key);
      if (!_set[hash_key]) return false;
      ListNode* cur = _set[hash_key];
      while (cur) {
        if (cur->val == key) return true;
        cur = cur->next;
      }
      return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
//leetcode submit region end(Prohibit modification and deletion)

}