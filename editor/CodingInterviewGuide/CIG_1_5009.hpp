//
// Created by timking.nf@foxmail.com on 2021/2/28.
//

#ifndef LEETCODE_CIG_1_5009_HPP
#define LEETCODE_CIG_1_5009_HPP

#include "header.h"

namespace CIG_1_5009 {

class Solution {
 public:
  bool isUnique(vector<char>& chas) {
    return solution2(chas);
  }

  // O( N ), O( N )
  bool solution1(vector<char>& chas) {
    unordered_set<char> dict;
    for (auto c : chas) {
      if (dict.count(c)) return false;
      dict.insert(c);
    }
    return true;
  }

  // 使用堆排序排序 chas, 保证 空间O( 1 )
  // O( NlogN ), O( 1 )
  bool solution2(vector<char>& chas) {
    if (chas.empty()) return true;
    heapSort(chas);
    for (int i = 1; i < chas.size(); ++i) {
      if (chas[i] == chas[i-1]) return false;
    }
    return true;
  }

  // 非递归的堆排序
  void heapSort(vector<char>& chas) {
    for (int i = 0; i < chas.size(); ++i) heapInsert(chas, i);
    for (int i = chas.size()-1; i > 0; --i) {
      swap(chas[0], chas[i]);
      heapify(chas, 0, i);
    }
  }

  void heapInsert(vector<char>& chas, int i) {
    int parent;
    while (i != 0) {
      parent = (i-1) / 2;
      if (chas[parent] < chas[i]) {
        swap(chas[parent], chas[i]);
        i = parent;
      } else {
        break;
      }
    }
  }

  // 维护节点 i 到 size 之前保持大顶堆
  void heapify(vector<char>& chas, int i, int size) {
    int left = i * 2 + 1, right = left + 1;
    int largest = i;
    while (left < size) {
      if (chas[left] > chas[i]) {
        largest = left;
      }
      if (right < size && chas[right] < chas[largest]) {
        largest = right;
      }
      if (largest != i) {
        swap(chas[largest], chas[i]);
      } else {
        break;
      }
      i = largest;
      left = i * 2 + 1;
      right = left + 1;
    }
  }
};

}

#endif  // LEETCODE_CIG_1_5009_HPP
