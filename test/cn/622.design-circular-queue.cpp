//
// Created by timking.nf@foxmail.com on 2020/7/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "622.design-circular-queue.h"

namespace LeetCode622 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;
int Null = INT32_MIN;

class LeetCode622Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode622Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  MyCircularQueue* q;
  vector<int> res;
  vector<vector<int>> input;
  vector<string> orders;
  tie(orders, input) = arguments;

  for (int i = 0; i < orders.size(); ++i) {
    if (orders[i] == "MyCircularQueue") {
      q = new MyCircularQueue(input[i][0]);
      res.push_back(Null);
    } else if (orders[i] == "enQueue") {
      res.push_back((int) q->enQueue(input[i][0]));
    } else if (orders[i] == "Rear") {
      res.push_back(q->Rear());
    } else if (orders[i] == "isFull") {
      res.push_back((int) q->isFull());
    } else if (orders[i] == "deQueue") {
      res.push_back((int) q->deQueue());
    } else if (orders[i] == "Front") {
      res.push_back(q->Front());
    } else if (orders[i] == "isEmpty") {
      res.push_back((int) q->isEmpty());
    }
  }
  ASSERT_EQ(res, ret);
}


vector<string> p1_0{"MyCircularQueue","enQueue","enQueue","enQueue","enQueue",
                    "Rear","isFull","deQueue","enQueue","Rear"};
vector<vector<int>> p1_1{{3},{1},{2},{3},{4},{},{},{},{4},{}};
ArgumentType p1(p1_0, p1_1);
ResultType r1{Null,1,1,1,0,3,1,1,1,4};

vector<string> p2_0{"MyCircularQueue","enQueue","deQueue","enQueue","enQueue","deQueue","isFull","isFull","Front"};
vector<vector<int>> p2_1{{81},{69},{},{92},{12},{},{},{},{}};
ArgumentType p2(p2_0, p2_1);
ResultType r2{Null,1,1,1,1,1,0,0,12};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode622ParamTest, LeetCode622Test, values);

}