//
// Created by timking.nf@foxmail.com on 2020/7/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "641.design-circular-deque.h"

namespace LeetCode641 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;
int Null = INT_MIN;

class LeetCode641Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode641Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  MyCircularDeque* q;
  vector<int> res;
  vector<vector<int>> input;
  vector<string> orders;
  tie(orders, input) = arguments;

  for (int i = 0; i < orders.size(); ++i) {
    if (orders[i] == "MyCircularDeque") {
      q = new MyCircularDeque(input[i][0]);
      res.push_back(Null);
    } else if (orders[i] == "insertLast") {
      res.push_back((int) q->insertLast(input[i][0]));
    } else if (orders[i] == "insertFront") {
      res.push_back((int) q->insertFront(input[i][0]));
    } else if (orders[i] == "getRear") {
      res.push_back(q->getRear());
    } else if (orders[i] == "isFull") {
      res.push_back((int) q->isFull());
    } else if (orders[i] == "deleteLast") {
      res.push_back((int) q->deleteLast());
    } else if (orders[i] == "getFront") {
      res.push_back(q->getFront());
    }
  }
  ASSERT_EQ(res, ret);
}


vector<string> p1_0{"MyCircularDeque","insertLast","insertLast","insertFront","insertFront",
                    "getRear","isFull","deleteLast","insertFront","getFront"};
vector<vector<int>> p1_1{{3},{1},{2},{3},{4},{},{},{},{4},{}};
ArgumentType p1(p1_0, p1_1);
ResultType r1{Null,1,1,1,0,2,1,1,1,4};

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode641ParamTest, LeetCode641Test, values);

}