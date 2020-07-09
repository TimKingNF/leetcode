//
// Created by timking.nf@foxmail.com on 2020/5/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "605.can-place-flowers.h"

namespace LeetCode605 {

typedef tuple<vector<int>, int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode605Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode605Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode605::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int n;
  tie(nums, n) = arguments;

  ASSERT_EQ(solution->canPlaceFlowers(nums, n), ret);  // 断言结果
}

vector<int> p1_0{1,0,0,0,1};
ArgumentType p1(p1_0, 1);

ArgumentType p2(p1_0, 2);

vector<int> p3_0{0,1,0};
ArgumentType p3(p3_0, 1);

vector<int> p4_0{1,0,0,0,1,0,0};
ArgumentType p4(p4_0, 2);

vector<int> p5_0{0,0,1,0,0};
ArgumentType p5(p5_0, 2);

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false),
  ParamType(p3, false),
  ParamType(p4, true),
  ParamType(p5, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode605ParamTest, LeetCode605Test, values);

}
