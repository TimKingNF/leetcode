//
// Created by timking.nf@foxmail.com on 2021/3/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "Funnel.hpp"

namespace Usages {

typedef tuple<string, string, int, float> ArgumentType;
// typedef vector<int> ResultType;
// typedef tuple<ArgumentType, ResultType> ParamType;

int random(int low, int hight) {
  return (rand() % (hight - low + 1)) + low;
}

class Funnel_Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(Funnel_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  srand(time(nullptr));

  string user_id, action_key;
  int capacity;
  float leaking_rate;
  tie(user_id, action_key, capacity, leaking_rate) = GetParam();

  // user_id, action_key 用于作为漏斗的主键
  // unordered_map<string, Funnel> funnels;
  auto funnel = new Usages::Funnel(capacity, leaking_rate);
  for (int i = 0; i < 20; ++i) {
    cout << (funnel->watering(1) ? 1 : 0) << endl;  // 一次减少 1
    sleep(random(0, 1));
  }
}

auto values = ::testing::Values(
  ArgumentType("ladqian", "reply", 5, 0.5)  // 2秒释放一个
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(Funnel_ParamTest, Funnel_Test, values);

}