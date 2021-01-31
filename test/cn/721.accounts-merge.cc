//
// Created by timking.nf@foxmail.com on 2021/1/18.
//

#include "gtest/gtest.h"
#include "header.h"
#include "721.accounts-merge.h"

namespace LeetCode721 {

typedef vector<vector<string>> ArgumentType;
typedef vector<vector<string>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode721Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode721Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode721::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->accountsMerge(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{"John", "johnsmith@mail.com", "john00@mail.com"},
              {"John", "johnnybravo@mail.com"},
              {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
              {"Mary", "mary@mail.com"}},
            {{"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},
              {"John", "johnnybravo@mail.com"}, 
              {"Mary", "mary@mail.com"}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode721ParamTest, LeetCode721Test, values);

}