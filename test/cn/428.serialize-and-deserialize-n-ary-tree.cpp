//
// Created by timking.nf@foxmail.com on 2020/8/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "428.serialize-and-deserialize-n-ary-tree.h"

namespace LeetCode428 {

typedef string ArgumentType;
// typedef int ResultType;
// typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode428Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode428Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  Codec codec;
  ArgumentType argument = GetParam();

  Node* root = codec.deserialize(argument);

  // cout << root->val << endl;
  // for (auto v : root->children) {
  //   cout << v->val << "-";
  //   for (auto i : v->children) {
  //     cout << i->val << ",";
  //   }
  //   cout << endl;
  // }

  ASSERT_EQ(codec.serialize(root), argument);
}

auto values = ::testing::Values(
  "[12 [3 [5 6 ] 2 4 ] ]",
  "[12 [3 [5 6 ] 2 [7 8 ] 4 ] ]",
  "[44 ]"
  // "12[3[5[]6[]]2[]4[]]"
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode428ParamTest, LeetCode428Test, values);

}