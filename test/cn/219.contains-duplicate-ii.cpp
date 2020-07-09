//
// Created by timking.nf@foxmail.com on 2020/5/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "219.contains-duplicate-ii.h"

namespace LeetCode219 {

typedef tuple<vector<int>, int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode219Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode219Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode219::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int k;
  tie(nums, k) = arguments;
  ASSERT_EQ(solution->containsNearbyDuplicate(nums, k), ret);  // 断言结果
}

vector<int> p1_0{1,2,3,1};
vector<int> p2_0{1,0,1,1};
vector<int> p3_0{1,2,3,1,2,3};
vector<int> p4_0{99, 99};

ArgumentType p1(p1_0, 3);
ArgumentType p2(p2_0, 1);
ArgumentType p3(p3_0, 2);
ArgumentType p4(p4_0, 2);

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, true),
  ParamType(p3, false),
  ParamType(p4, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode219ParamTest, LeetCode219Test, values);

}
