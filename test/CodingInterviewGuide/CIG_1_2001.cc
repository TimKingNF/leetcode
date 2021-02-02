//
// Created by timking.nf@foxmail.com on 2021/2/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_2001.hpp"

namespace CIG_1_2001 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_2001_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_2001_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_2001::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> v1, v2;
  tie(v1, v2) = arguments;
  auto l1 = construct_link_list<ListNode>(v1);
  auto l2 = construct_link_list<ListNode>(v2);
  ASSERT_EQ(solution->getCommonPart(l1, l2), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({2,3,5,6}, {1,2,5,7,8}), {2,5}),
  ParamType(ArgumentType({1,2,3}, {4,5,6}), {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_2001_ParamTest, CIG_1_2001_Test, values);

}