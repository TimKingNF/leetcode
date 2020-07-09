//
// Created by timking.nf@foxmail.com on 2020/7/5.
//

#include "gtest/gtest.h"
#include "header.h"
#include "836.rectangle-overlap.h"

namespace LeetCode836 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode836Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode836Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode836::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<int> rec1, rec2;
  tie(rec1, rec2) = arguments;

  ASSERT_EQ(solution->isRectangleOverlap(rec1, rec2), ret);  // 断言结果
}

vector<int> p1_0 = {0,0,2,2};
vector<int> p1_1 = {1,1,3,3};
ArgumentType p1(p1_0, p1_1);

vector<int> p2_0 = {0,0,1,1};
vector<int> p2_1 = {1,0,2,1};
ArgumentType p2(p2_0, p2_1);

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode836ParamTest, LeetCode836Test, values);

}