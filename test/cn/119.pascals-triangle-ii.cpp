//
// Created by timking.nf@foxmail.com on 2020/5/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "119.pascals-triangle-ii.h"

namespace LeetCode119 {

typedef int ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode119Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode119Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode119::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<int> r = solution->getRow(argument);
  ASSERT_EQ(r, ret);  // 断言结果
}

ResultType r1{1,3,3,1};
ResultType r2{1,32,496,4960,35960,201376,906192,3365856,10518300,28048800,
              64512240,129024480,225792840,347373600,471435600,565722720,
              601080390,565722720,471435600,347373600,225792840,129024480,
              64512240,28048800,10518300,3365856,906192,201376,35960,
              4960,496,32,1};

auto values = ::testing::Values(
  ParamType(3, r1),
  ParamType(2, {1,2,1}),
  ParamType(32, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode119ParamTest, LeetCode119Test, values);

}