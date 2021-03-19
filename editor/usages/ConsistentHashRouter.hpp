//
// Created by timking.nf@foxmail.com on 2021/3/19.
//

#ifndef LEETCODE_CONSISTENTHASHROUTER_HPP
#define LEETCODE_CONSISTENTHASHROUTER_HPP

#include <iostream>
#include <map>
#include <stdexcept>
#include <cstring>
#include <string>
#include <sstream>
#include <openssl/md5.h>

namespace Usages {

// 用于计算 MD5
struct Hash_MD5 {
  uint32_t operator()(std::string key) {
    unsigned char md[16];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, key.c_str(), key.size());
    MD5_Final(md, &ctx);

    // 只取前4位拿来计算
    uint32_t h = 0;
    for (int i = 0; i < 4; ++i) {
      h <<= 8;
      h |= (md[i] & 0xFF);
    }
    return h;
  }
};

template <typename T>
class VirtualNode {
 public:
  using physical_node_ptr = T*;

 public:
  VirtualNode(T& node, int idx) : node_(&node), index_(idx) {}
  ~VirtualNode() = default;
  T* get_physical_node() { return node_; }

  std::string get_key() {
    std::ostringstream oss;
    oss << node_->get() << "-" << index_;  // XXX: 这里需要调用 T::get 方法，需要限定
    return oss.str();
  }

  // 比较两个节点之间是否相同
  bool is_virtual_node_of(T& node) {
    return node_->get() == node.get();
  }

 private:
  physical_node_ptr node_;
  int index_;
};

template <typename T, typename hash = Hash_MD5>
class ConsistentHashRouter {
 public:
  using this_type = ConsistentHashRouter;
  using node_t = VirtualNode<T>;
  using node_ptr = node_t *;
  using ring_t = std::map<uint32_t, node_ptr>;

 public:
  ConsistentHashRouter() = default;
  ~ConsistentHashRouter() {
    for (auto v: ring_) delete v.second;
  }
  ConsistentHashRouter(const this_type&) = delete;  // 拷贝构造
  this_type& operator=(const this_type&) = delete;  // 赋值构造
  ConsistentHashRouter(this_type&&) = delete;  // 移动构造
  this_type& operator=(this_type&&) = delete;  // 移动赋值

 public:
  /**
  * 添加节点，会批量添加虚拟节点进去
  * @param node
  * @param vNodeCount
  */
  void add_node(T& node, int vNodeCount) {
    if (vNodeCount < 0) {
      throw std::runtime_error("illegal virtual node counts");
    }
    int existing_replicas = get_existing_replicas(node);
    for (int i = 0; i < vNodeCount; ++i) {
      auto vnode = new node_t(node, i + existing_replicas);
      ring_.insert({hash_(vnode->get_key()), vnode});
    }
  }

  /**
  * 移除节点
  * @param node
  */
  void remove_node(T& node) {
    std::map<int, int> a;
    for (auto iter = ring_.begin(); iter != ring_.end();) {
      if (iter->second->is_virtual_node_of(node)) {
        ring_.erase(iter++);
      } else {
        ++iter;
      }
    }
  }

  /**
  * 获取对应路由的节点
  * @param key
  * @return
  */
  T* rout_node(std::string key) {
    if (ring_.empty()) return nullptr;
    auto hash_key = hash_(key);
    auto iter = ring_.upper_bound(hash_key);
    if (iter == ring_.end()) {
      return ring_.begin()->second->get_physical_node();
    }
    return iter->second->get_physical_node();
  }

 private:
  /**
  * 如果当前环中已经有了该节点，再次添加，返回最大序号
  * 多次添加同一个节点，可以提高权重
  * @param node
  * @return
  */
  int get_existing_replicas(T& node) {
    int replicas = 0;
    for (const auto& v : ring_) {
      if (v.second->is_virtual_node_of(node)) ++replicas;
    }
    return replicas;
  }

 private:
  ring_t ring_;
  hash hash_;
};

}

#endif  // LEETCODE_CONSISTENTHASHROUTER_HPP
