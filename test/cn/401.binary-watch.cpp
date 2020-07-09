//
// Created by timking.nf@foxmail.com on 2020/7/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "401.binary-watch.h"

namespace LeetCode401 {

typedef int ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode401Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode401Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode401::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<string> asserted = solution->readBinaryWatch(argument);
  // vector_print(asserted);
  ASSERT_TRUE(vector_unordered_cmp<string>(asserted, ret));  // 断言结果
}

ArgumentType p1 = 1;
ResultType r1 = {"1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"};

ArgumentType p2 = 2;
ResultType r2 = {"0:03","0:05","0:06","0:09","0:10","0:12","0:17","0:18","0:20","0:24","0:33",
  "0:34","0:36","0:40","0:48","1:01","1:02","1:04","1:08","1:16","1:32","2:01",
  "2:02","2:04","2:08","2:16","2:32","3:00","4:01","4:02","4:04","4:08","4:16","4:32",
  "5:00","6:00","8:01","8:02","8:04","8:08","8:16","8:32","9:00","10:00"};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode401ParamTest, LeetCode401Test, values);

}