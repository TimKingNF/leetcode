//
// Created by timking.nf@foxmail.com on 2020/7/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "49.group-anagrams.h"

namespace LeetCode49 {

typedef vector<string> ArgumentType;
typedef vector<vector<string>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode49Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode49Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode49::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<vector<string>> asserted = solution->groupAnagrams(argument);
  ASSERT_TRUE(double_vector_cmp<string>(asserted, ret));
}

auto values = ::testing::Values(
  ParamType({"eat", "tea", "tan", "ate", "nat", "bat"},
            {{"ate","eat","tea"},
             {"nat","tan"},
             {"bat"}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode49ParamTest, LeetCode49Test, values);

}