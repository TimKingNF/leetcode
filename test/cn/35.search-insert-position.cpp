//
// Created by timking.nf@foxmail.com on 2020/5/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "35.search-insert-position.h"

namespace LeetCode35 {

typedef pair<vector<int>, int> ArgumentType;
typedef tuple<ArgumentType, int> ParamType;

class LeetCode35Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode35Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode35::Solution();
  ArgumentType arguments;
  int ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums = get<0>(arguments);  // 取出函数的参数
  int target = get<1>(arguments);

  ASSERT_EQ(solution->searchInsert(nums, target), ret);  // 断言结果
}

vector<int> p1_0{1,3,5,6};
ArgumentType p1(p1_0, 5);  // 参数1

ArgumentType p2(p1_0, 2);  // 参数2

ArgumentType p3(p1_0, 7);  // 参数3
ArgumentType p4(p1_0, 0);  // 参数3

auto values = ::testing::Values(
  ParamType(p1, 2),
  ParamType(p2, 1),
  ParamType(p3, 4),
  ParamType(p4, 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode35ParamTest, LeetCode35Test, values);

}