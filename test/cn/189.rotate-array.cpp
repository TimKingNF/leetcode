//
// Created by timking.nf@foxmail.com on 2020/5/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "189.rotate-array.h"

namespace LeetCode189 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode189Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode189Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode189::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums = get<0>(arguments);
  int k = get<1>(arguments);

  solution->rotate(nums, k);
  ASSERT_EQ(nums, ret);  // 断言结果
}

vector<int> p1_0{1,2,3,4,5,6,7};
vector<int> p2_0{-1,-100,3,99};

ArgumentType p1(p1_0, 3);
ArgumentType p2(p2_0, 2);

ResultType r1{5,6,7,1,2,3,4};
ResultType r2{3,99,-1,-100};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode189ParamTest, LeetCode189Test, values);

}
