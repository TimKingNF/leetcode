//
// Created by timking.nf@foxmail.com on 2020/5/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_09.yong-liang-ge-zhan-shi-xian-dui-lie-lcof.h"

namespace LeetCode_09 {

typedef tuple<vector<string>, vector<vector<int>>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;
int INVALID = -2;

class LeetCode_09Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_09Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  CQueue* obj;
  vector<int> res;
  vector<vector<int>> input;
  vector<string> orders;
  tie(orders, input) = arguments;

  for (int i = 0; i < orders.size(); ++i) {
    if (orders[i] == "CQueue") {
      obj = new CQueue();
      res.push_back(INVALID);
    } else if (orders[i] == "appendTail") {
      obj->appendTail(input[i][0]);
      res.push_back(INVALID);
    } else if (orders[i] == "deleteHead") {
      res.push_back(obj->deleteHead());
    }
  }
  ASSERT_EQ(res, ret);
}

vector<string> p1_0{"CQueue","appendTail","deleteHead","deleteHead"};
vector<vector<int>> p1_1{{}, {3}, {}, {}};
ArgumentType p1(p1_0, p1_1);

vector<string> p2_0{"CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"};
vector<vector<int>> p2_1{{}, {}, {5}, {2}, {}, {}};
ArgumentType p2(p2_0, p2_1);

ResultType r1{INVALID,INVALID,3,-1};
ResultType r2{INVALID,-1,INVALID,INVALID,5,2};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_09ParamTest, LeetCode_09Test, values);

}