//
// Created by timking.nf@foxmail.com on 2020/5/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_06.cong-wei-dao-tou-da-yin-lian-biao-lcof.h"

namespace LeetCode_06 {

typedef ListNode* ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_06Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_06Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_06::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->reversePrint(argument), ret);  // 断言结果

  // 清理指针
  delete argument;
}

vector<int> p1_0{1, 3, 2};
ArgumentType p1 = construct_link_list<ListNode, int>(p1_0);

ResultType r1{2, 3, 1};

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_06ParamTest, LeetCode_06Test, values);

}
