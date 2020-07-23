//
// Created by timking.nf@foxmail.com on 2020/7/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "841.keys-and-rooms.h"

namespace LeetCode841 {

typedef vector<vector<int>> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode841Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode841Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode841::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->canVisitAllRooms(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({{}}, true),
  ParamType({{1}, {2}, {3}, {}}, true),
  ParamType({{1,3}, {3,0,1}, {2}, {0}}, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode841ParamTest, LeetCode841Test, values);

}