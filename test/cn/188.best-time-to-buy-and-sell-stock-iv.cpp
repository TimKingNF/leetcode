//
// Created by timking.nf@foxmail.com on 2020/5/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "188.best-time-to-buy-and-sell-stock-iv.h"

namespace LeetCode188 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode188Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode188Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode188::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums = get<0>(arguments);
  int k = get<1>(arguments);

  ASSERT_EQ(solution->maxProfit(k, nums), ret);  // 断言结果
}

vector<int> p1_0{2,4,1};
vector<int> p2_0{3,2,6,5,0,3};

ArgumentType p1(p1_0, 2);
ArgumentType p2(p2_0, 2);

ResultType r1 = 2;
ResultType r2 = 7;

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode188ParamTest, LeetCode188Test, values);

}
