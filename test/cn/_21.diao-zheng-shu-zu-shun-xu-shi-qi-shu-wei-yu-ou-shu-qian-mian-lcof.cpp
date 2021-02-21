//
// Created by timking.nf@foxmail.com on 2020/5/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_21.diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof.h"

namespace LeetCode_21 {

typedef vector<int> ArgumentType;
typedef set<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_21Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_21Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_21::Solution();
  ArgumentType argument = GetParam();

  vector<int> asserted = solution->exchange(argument);
  // 校验
  ASSERT_EQ(asserted.size(), argument.size());
  unordered_map<int, int> checked;
  for (auto num : argument) ++checked[num];

  bool odd = true;
  for (int i = 0; i < asserted.size(); ++i) {
    ASSERT_TRUE(checked.count(asserted[i]));  // 先检查是否存在

    // 检查一开始全是奇数，后面全是偶数
    int mod = asserted[i] % 2;
    if (mod == 0) odd = false;
    ASSERT_TRUE(odd ? mod == 1 : mod == 0);

    // 已经出现过，从 checked 扣除
    if (--checked[asserted[i]] == 0) checked.erase(asserted[i]);
  }
  ASSERT_TRUE(checked.size() == 0);  // 最后全部移除
}

auto values = ::testing::Values(
  ArgumentType{1,2,3,4},
  ArgumentType{1,2,3,4,5,3},
  ArgumentType{2,16,3,5,13,1,16,1,12,18,11,8,11,11,5,1}
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_21ParamTest, LeetCode_21Test, values);

}

