//
// Created by timking.nf@foxmail.com on 2021/1/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_1004.hpp"

namespace CIG_1_1004 {

typedef vector<string> operators;
typedef vector<pair<string, int>> operator_argument;
typedef tuple<operators, operator_argument> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_1004_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_1004_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ostringstream os;
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  operators ops;
  operator_argument args;
  tie(ops, args) = argument;

  CatDogQueue queue;
  for (int i = 0; i < ops.size(); ++i) {
    if (ops[i] == "CatDogQueue") {
      queue = CatDogQueue();
      os << "null,";
    } else if (ops[i] == "add") {
      // cout << "push " << args[i].first << "," << args[i].second << endl;
      // 调用 add 方法
      if (args[i].first == "cat") {
        queue.add(new Cat(args[i].second));
      } else if (args[i].first == "dog") {
        queue.add(new Dog(args[i].second));
      }
      os << "null,";
    } else if (ops[i] == "pollDog") {
      auto x = queue.pollDog();
      os << '<' << x->getPetType() << "," << x->getId() << ">,";
    } else if (ops[i] == "pollCat") {
      auto x = queue.pollCat();
      os << '<' << x->getPetType() << "," << x->getId() << ">,";
    } else if (ops[i] == "pollAll") {
      auto x = queue.pollAll();
      os << '<' << x->getPetType() << "," << x->getId() << ">,";
    } else if (ops[i] == "isEmpty") {
      os << (queue.isEmpty() ? "true" : "false") << ",";
    } else if (ops[i] == "isDogEmpty") {
      os << (queue.isDogEmpty() ? "true" : "false") << ",";
    } else if (ops[i] == "isCatEmpty") {
      os << (queue.isCatEmpty() ? "true" : "false") << ",";
    }
  }

  string oss = os.str();
  ASSERT_EQ(oss.substr(0, oss.size()-1), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"CatDogQueue","add","add","add","add","pollDog","pollAll",
                          "pollCat","isDogEmpty","isCatEmpty","pollAll", "isEmpty"},
                         {{},{"cat",0},{"dog",1},{"cat",2},{"cat",3},{},{},{},{},{},{},{}}),
            "null,null,null,null,null,<dog,1>,<cat,0>,<cat,2>,true,false,<cat,3>,true")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_1004_ParamTest, CIG_1_1004_Test, values);

}