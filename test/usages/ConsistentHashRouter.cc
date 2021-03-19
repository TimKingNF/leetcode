//
// Created by timking.nf@foxmail.com on 2021/3/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "ConsistentHashRouter.hpp"

namespace Usages {

// 集群中写入的数据键总量
// 原始集群的节点数
// 一个节点对应的虚拟节点数
typedef tuple<int, int, int> ArgumentType;
// typedef vector<int> ResultType;
// typedef tuple<ArgumentType, ResultType> ParamType;

// 服务器节点
class Srv {
 public:
  Srv(string&& ip, int port) : ip_(ip), port_(port) {}
  string get() {
    ostringstream oss;
    oss << ip_ << ":" << port_;
    return oss.str();
  }
  // ~Srv() {
  //   cout << "~Srv" << endl;
  // }

  string ip() const { return ip_; }
  int port() const { return port_; }

 private:
  string ip_;
  int port_ = 0;
};


class ConsistentHashRouter_Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(ConsistentHashRouter_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  int keys, nodes, vnodes;
  tie(keys, nodes, vnodes) = GetParam();

  map<string, int> cnt;
  map<int, string> dict;  // 用于记录每个 key 对应的服务器, 判断有多少发生了变动

  // 添加服务器
  vector<Srv*> srvs(nodes);
  for (int i = 0; i < nodes; ++i)
    srvs[i] = new Srv("node-" + to_string(i), i);

  ConsistentHashRouter<Srv> c;
  // 添加服务器节点
  for (auto* srv : srvs) c.add_node(*srv, vnodes);

  for (int i = 0; i < keys; ++i) {
    auto srv_ptr = c.rout_node(to_string(i));  // 传入主键，判断应路由到哪个服务器
    auto host = srv_ptr->ip();
    ++cnt[host];  // 计数
    dict[i] = host;
  }

  // 打印路由结果的概率
  for (const auto& v : cnt) {
    cout << v.first << "=" << v.second << "," << ((float) v.second / keys) * 100 << "%" << endl;
  }

  // 重新路由一次, 两次结果应当一致
  cnt.clear();
  for (int i = 0; i < keys; ++i) {
    auto srv_ptr = c.rout_node(to_string(i));  // 传入主键，判断应路由到哪个服务器
    auto host = srv_ptr->ip();
    ++cnt[host];  // 计数
  }
  for (const auto& v : cnt) {
    cout << v.first << "=" << v.second << "," << ((float) v.second / keys) * 100 << "%" << endl;
  }

  // 移除一个节点
  cout << "remove a node" << endl;
  c.remove_node(*srvs[0]);
  cnt.clear();

  // 重新路由
  int changes = 0;
  for (int i = 0; i < keys; ++i) {
    auto srv_ptr = c.rout_node(to_string(i));  // 传入主键，判断应路由到哪个服务器
    auto host = srv_ptr->ip();
    ++cnt[host];
    if (host != dict[i]) ++changes;  // 记录有多少个节点发生了变动
  }
  // 剩下的节点应当平摊到 剩下的个服务器上
  for (const auto& v : cnt) {
    cout << v.first << "=" << v.second << "," << ((float) v.second / keys) * 100 << "%" << endl;
  }
  cout << changes << " node has change" << endl;

  // 释放 Srv 内存
  for (auto* srv : srvs) delete srv;
}

auto values = ::testing::Values(
  ArgumentType(10000, 3, 200)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(ConsistentHashRouter_ParamTest, ConsistentHashRouter_Test, values);

}