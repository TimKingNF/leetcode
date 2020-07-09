//
// Created by timking.nf@foxmail.com on 2020/7/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_03_04.implement-queue-using-stacks-lcci.h"

namespace LeetCode_03_04 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;
int Null = -2;

class LeetCode_03_04Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_03_04Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  MyQueue* obj;
  vector<int> res;
  vector<vector<int>> input;
  vector<string> orders;
  tie(orders, input) = arguments;

  for (int i = 0; i < orders.size(); ++i) {
    if (orders[i] == "MyQueue") {
      obj = new MyQueue();
      res.push_back(Null);
    } else if (orders[i] == "push") {
      obj->push(input[i][0]);
      res.push_back(Null);
    } else if (orders[i] == "pop") {
      res.push_back(obj->pop());
    } else if (orders[i] == "peek") {
      res.push_back(obj->peek());
    } else if (orders[i] == "empty") {
      res.push_back((int) obj->empty());
    }
  }
  ASSERT_EQ(res, ret);
}

vector<string> p1_0{"MyQueue","push","peek","pop","empty"};
vector<vector<int>> p1_1{{}, {3}, {}, {}, {}};
ArgumentType p1(p1_0, p1_1);

vector<string> p2_0{"MyQueue","push","push","peek","pop","peek","empty"};
vector<vector<int>> p2_1{{}, {5}, {2}, {}, {}, {}};
ArgumentType p2(p2_0, p2_1);

ResultType r1{Null,Null,3,3,1};
ResultType r2{Null,Null,Null,5,5,2,0};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_03_04ParamTest, LeetCode_03_04Test, values);

}