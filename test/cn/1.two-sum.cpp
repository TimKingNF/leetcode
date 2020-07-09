//
// Created by timking.nf@foxmail.com on 2020/5/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1.two-sum.h"

namespace LeetCode1 {

TEST(LeetCode1Test, main) {
  auto solution = new LeetCode1::Solution();
  vector<int> nums = {2, 7, 11, 15};
  vector<int> asserts = {0, 1};
  ASSERT_EQ(solution->twoSum(nums, 9), asserts);
}

}
