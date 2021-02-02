//
// Created by timking.nf@foxmail.com on 2021/1/31.
//

#ifndef LEETCODE_CIG_1_1004_HPP
#define LEETCODE_CIG_1_1004_HPP

#include "header.h"

namespace CIG_1_1004 {

class Pet {
 private:
  string type;
  int id;

 public:
  Pet(string type, int id) : type(type), id(id) {}
  string& getPetType() { return type; }
  int getId() { return id; }
};

class Dog : public Pet {
 public:
  Dog(int id) : Pet("dog", id) {}
};

class Cat : public Pet {
 public:
  Cat(int id) : Pet("cat", id) {}
};

class CatDogQueue {
 private:
  class item {
   public:
    Pet *pet;
    int count;
    item(Pet *pet, int count) : pet(pet), count(count) {}
  };

  queue<item> cats;
  queue<item> dogs;
  int cnt = 0;
 public:
  void add(Pet* pet) {
    if (!pet) return;
    auto& type = pet->getPetType();
    if (type == "cat") {
      cats.emplace(pet, cnt++);
    } else if (type == "dog") {
      dogs.emplace(pet, cnt++);
    } else {
      throw invalid_argument("error type");
    }
  }

  Pet* pollAll() {
    if (isEmpty()) return nullptr;
    if (cats.empty() || dogs.empty()) {
      auto& q = cats.empty() ? dogs : cats;
      auto res = q.front();
      q.pop();
      return res.pet;
    }

    // 比较两个队列的头一个元素
    auto dog = dogs.front();
    auto cat = cats.front();
    if (dog.count < cat.count) {
      dogs.pop();
      return dog.pet;
    } else {
      cats.pop();
      return cat.pet;
    }
  }

  Dog* pollDog() {
    if (isDogEmpty()) return nullptr;
    auto ans = dogs.front();
    dogs.pop();
    return static_cast<Dog*>(ans.pet);
  }

  Cat* pollCat() {
    if (isCatEmpty()) return nullptr;
    auto ans = cats.front();
    cats.pop();
    return static_cast<Cat*>(ans.pet);
  }

  bool isEmpty() {
    return cats.empty() && dogs.empty();
  }

  bool isDogEmpty() {
    return dogs.empty();
  }

  bool isCatEmpty() {
    return cats.empty();
  }
};

}

#endif  // LEETCODE_CIG_1_1004_HPP
