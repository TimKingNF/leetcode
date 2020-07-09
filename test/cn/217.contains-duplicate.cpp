//
// Created by timking.nf@foxmail.com on 2020/5/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "217.contains-duplicate.h"

namespace LeetCode217 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode217Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode217Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode217::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->containsDuplicate(argument), ret);  // 断言结果
}

ArgumentType p1{1,2,3,1};
ArgumentType p2{1,2,3,4};
ArgumentType p3{1,1,1,3,3,4,3,2,4,2};
ArgumentType p4{2};
ArgumentType p5{};

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false),
  ParamType(p3, true),
  ParamType(p4, false),
  ParamType(p5, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode217ParamTest, LeetCode217Test, values);

}
