//
// Created by timking.nf@foxmail.com on 2020/6/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_40.zui-xiao-de-kge-shu-lcof.h"

namespace LeetCode_40 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_40Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_40Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_40::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> arr;
  int k;
  tie(arr, k) = arguments;
  vector<int> ans = solution->getLeastNumbers(arr, k);
  ASSERT_TRUE(vector_unordered_cmp<int>(ans, ret));  // 断言结果
}

vector<int> p1_0{1,2,3};
ArgumentType p1(p1_0, 2);

vector<int> p2_0{0, 1, 2, 1};
ArgumentType p2(p2_0, 1);

vector<int> p3_0{0,0,1,2,4,2,2,3,1,4};
ArgumentType p3(p3_0, 8);

ResultType r1{1, 2};
ResultType r2{0};
ResultType r3{0,0,1,1,2,2,2,3};

auto values = ::testing::Values(
  // ParamType(p1, r1),
  // ParamType(p2, r2),
  ParamType(p3, r3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_40ParamTest, LeetCode_40Test, values);

}
