//
// Created by timking.nf@foxmail.com on 2020/7/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1441.build-an-array-with-stack-operations.h"

namespace LeetCode1441 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1441Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1441Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1441::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> target;
  int n;
  tie(target, n) = arguments;

  ASSERT_EQ(solution->buildArray(target, n), ret);  // 断言结果
}

vector<int> p1_0 = {1,3};
int p1_1 = 3;
ArgumentType p1(p1_0, p1_1);
ResultType r1 = {"Push","Push","Pop","Push"};

vector<int> p2_0 = {1,2,3};
int p2_1 = 3;
ArgumentType p2(p2_0, p2_1);
ResultType r2 = {"Push","Push","Push"};

vector<int> p3_0 = {1,2};
int p3_1 = 4;
ArgumentType p3(p3_0, p3_1);
ResultType r3 = {"Push","Push"};

vector<int> p4_0 = {2,3,4};
int p4_1 = 4;
ArgumentType p4(p4_0, p4_1);
ResultType r4 = {"Push","Pop","Push","Push","Push"};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3),
  ParamType(p4, r4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1441ParamTest, LeetCode1441Test, values);

}