//
// Created by timking.nf@foxmail.com on 2020/5/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "118.pascals-triangle.h"

namespace LeetCode118 {

typedef int ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode118Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode118Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode118::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->generate(argument), ret);  // 断言结果
}

vector<int> r1_0{1};
vector<int> r1_1{1,1};
vector<int> r1_2{1,2,1};
vector<int> r1_3{1,3,3,1};
vector<int> r1_4{1,4,6,4,1};
ResultType r1{r1_0, r1_1, r1_2, r1_3, r1_4};

auto values = ::testing::Values(
  ParamType(5, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode118ParamTest, LeetCode118Test, values);

}