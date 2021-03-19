//
// Created by timking.nf@foxmail.com on 2021/3/19.
//

#ifndef LEETCODE_FUNNEL_HPP
#define LEETCODE_FUNNEL_HPP

#include "header.h"
#include <ctime>

namespace Usages {

class Funnel {
 private:
  int _capacity;  // 漏斗的容量
  float _leaking_rate;  // 漏斗流水速率 quota/s
  int _left_quota;  // 漏斗剩余空间
  std::time_t _leaking_ts;  // 漏斗上一次漏水的时间
 public:
  Funnel(int capacity, float leaking_rate)
    : _capacity(capacity), _leaking_rate(leaking_rate) {
    _left_quota = capacity;
    _leaking_ts = std::time(nullptr);
  }

  // 返回上次漏水时间
  std::time_t leaking_ts() const {
    return _leaking_ts;
  }

  // 参数 quota 表示一次漏水消耗多少剩余空间
  bool watering(int quota) {
    make_space();  // 更新剩余空间
    if (_left_quota >= quota) {
      _left_quota -= quota;
      return true;
    }
    return false;
  }

  // 计算剩余空间
  void make_space() {
    auto now_ts = std::time(nullptr);  // 获取当前的时间
    auto delta_ts = now_ts - _leaking_ts;  // 距离上一次漏水过去了多久

    // 过去的时间 * 漏水速率, 得出漏了多少水，也就是可以腾出多少空间
    float delta_quota = delta_ts * _leaking_rate;
    if (delta_quota < 1) return;  // 腾的空间太少，那就等下次吧
    _left_quota += (int) delta_quota;  // 增加剩余的空间
    _leaking_ts = now_ts;

    // 剩余空间不得高于容量
    if (_left_quota > _capacity) _left_quota = _capacity;
  }
};

}

#endif  // LEETCODE_FUNNEL_HPP
