//不使用任何内建的哈希表库设计一个哈希映射 
//
// 具体地说，你的设计应该包含以下的功能 
//
// 
// put(key, value)：向哈希映射中插入(键,值)的数值对。如果键对应的值已经存在，更新这个值。 
// get(key)：返回给定的键所对应的值，如果映射中不包含这个键，返回-1。 
// remove(key)：如果映射中存在这个键，删除这个数值对。 
// 
//
// 
//示例： 
//
// MyHashMap hashMap = new MyHashMap();
//hashMap.put(1, 1);          
//hashMap.put(2, 2);         
//hashMap.get(1);            // 返回 1
//hashMap.get(3);            // 返回 -1 (未找到)
//hashMap.put(2, 1);         // 更新已有的值
//hashMap.get(2);            // 返回 1 
//hashMap.remove(2);         // 删除键为2的数据
//hashMap.get(2);            // 返回 -1 (未找到) 
// 
//
// 
//注意： 
//
// 
// 所有的值都在 [0, 1000000]的范围内。 
// 操作的总数目在[1, 10000]范围内。 
// 不要使用内建的哈希库。 
// 
// Related Topics 设计 哈希表

#include "header.h"

namespace LeetCode706 {

//leetcode submit region begin(Prohibit modification and deletion)
struct Node {
  int key;
  int val;
  Node* next;
  Node(int key, int val): key(key), val(val), next(nullptr) {};
};

class MyHashMap {
 private:
  vector<Node*> _set;
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
    _set = vector<Node*>(capacity, nullptr);
    for (auto cur : origSet) {
      while (cur) {
        put(cur->key, cur->val);
        cur = cur->next;
      }
    }
  }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
      _has_count = 0;
      _set = vector<Node*>(capacity, nullptr);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
      int hash_key = hash(key);
      if (!_set[hash_key]) {
        _set[hash_key] = new Node(key, value);
        ++_has_count;
        rehash(false);
      } else {
        Node *cur = _set[hash_key], *tail;
        int count = 0;
        while (cur) {
          if (cur->key == key) {  // 更新集合元素
            cur->val = value;
            return;
          }
          tail = cur;
          cur = cur->next;
          ++count;
        }
        // 在tail后面追加
        tail->next = new Node(key, value);
        if (++count > _max_length) rehash(true);  // 超过了链表最大长度，需要扩容
      }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
      int hash_key = hash(key);
      if (!_set[hash_key]) return -1;
      Node* cur = _set[hash_key];
      while (cur) {
        if (cur->key == key) return cur->val;
        cur = cur->next;
      }
      return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
      int hash_key = hash(key);
      if (!_set[hash_key]) return;
      Node *cur = _set[hash_key], *dummy = new Node(-1, -1), *pre = dummy;
      pre->next = cur;
      while (cur) {
        if (cur->key == key) {
          pre->next = cur->next;
          break;
        }
        pre = cur;
        cur = cur->next;
      }
      _set[hash_key] = dummy->next;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
//leetcode submit region end(Prohibit modification and deletion)

}