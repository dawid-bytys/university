#include <cassert>
#include <iostream>

#include "doublelist.hpp"

void test_default_constructor() {
  DoubleList<int> list;
  assert(list.head == nullptr);
  assert(list.tail == nullptr);
  assert(list.get_size() == 0);
  assert(list.empty());
  std::cout << "test_default_constructor passed" << std::endl;
}

void test_copy_constructor() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);

  DoubleList<int> list2(list);
  assert(list2.head->value == 1);
  assert(list2.tail->value == 5);
  assert(list2.get_size() == 5);
  assert(!list2.empty());
  std::cout << "test_copy_constructor passed" << std::endl;
}

void test_move_constructor() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);

  DoubleList<int> list2(std::move(list));
  assert(list2.head->value == 1);
  assert(list2.tail->value == 5);
  assert(list2.get_size() == 5);
  assert(!list2.empty());
  std::cout << "test_move_constructor passed" << std::endl;
}

void test_copy_assignment() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);

  DoubleList<int> list2;
  list2 = list;
  assert(list2.head->value == 1);
  assert(list2.tail->value == 5);
  assert(list2.get_size() == 5);
  assert(!list2.empty());
  std::cout << "test_copy_assignment passed" << std::endl;
}

void test_move_assignment() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);

  DoubleList<int> list2;
  list2 = std::move(list);
  assert(list2.head->value == 1);
  assert(list2.tail->value == 5);
  assert(list2.get_size() == 5);
  assert(!list2.empty());
  std::cout << "test_move_assignment passed" << std::endl;
}

void test_empty() {
  DoubleList<int> list;
  assert(list.empty());
  list.push_back(1);
  assert(!list.empty());
  std::cout << "test_empty passed" << std::endl;
}

void test_get_size() {
  DoubleList<int> list;
  assert(list.get_size() == 0);
  list.push_back(1);
  assert(list.get_size() == 1);
  list.push_back(2);
  assert(list.get_size() == 2);
  list.push_back(3);
  assert(list.get_size() == 3);
  list.push_back(4);
  assert(list.get_size() == 4);
  list.push_back(5);
  assert(list.get_size() == 5);
  std::cout << "test_get_size passed" << std::endl;
}

void test_push_front() {
  DoubleList<int> list;
  list.push_front(1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);
  assert(list.get_size() == 1);
  list.push_front(2);
  assert(list.head->value == 2);
  assert(list.tail->value == 1);
  assert(list.get_size() == 2);
  list.push_front(3);
  assert(list.head->value == 3);
  assert(list.tail->value == 1);
  assert(list.get_size() == 3);
  list.push_front(4);
  assert(list.head->value == 4);
  assert(list.tail->value == 1);
  assert(list.get_size() == 4);
  list.push_front(5);
  assert(list.head->value == 5);
  assert(list.tail->value == 1);
  assert(list.get_size() == 5);
  std::cout << "test_push_front passed" << std::endl;
}

void test_push_front_move() {
  DoubleList<int> list;
  list.push_front(std::move(1));
  assert(list.head->value == 1);
  assert(list.tail->value == 1);
  assert(list.get_size() == 1);
  list.push_front(std::move(2));
  assert(list.head->value == 2);
  assert(list.tail->value == 1);
  assert(list.get_size() == 2);
  list.push_front(std::move(3));
  assert(list.head->value == 3);
  assert(list.tail->value == 1);
  assert(list.get_size() == 3);
  list.push_front(std::move(4));
  assert(list.head->value == 4);
  assert(list.tail->value == 1);
  assert(list.get_size() == 4);
  list.push_front(std::move(5));
  assert(list.head->value == 5);
  assert(list.tail->value == 1);
  assert(list.get_size() == 5);
  std::cout << "test_push_front_move passed" << std::endl;
}

void test_push_back() {
  DoubleList<int> list;
  list.push_back(1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);
  assert(list.get_size() == 1);
  list.push_back(2);
  assert(list.head->value == 1);
  assert(list.tail->value == 2);
  assert(list.get_size() == 2);
  list.push_back(3);
  assert(list.head->value == 1);
  assert(list.tail->value == 3);
  assert(list.get_size() == 3);
  list.push_back(4);
  assert(list.head->value == 1);
  assert(list.tail->value == 4);
  assert(list.get_size() == 4);
  list.push_back(5);
  assert(list.head->value == 1);
  assert(list.tail->value == 5);
  assert(list.get_size() == 5);
  std::cout << "test_push_back passed" << std::endl;
}

void test_push_back_move() {
  DoubleList<int> list;
  list.push_back(std::move(1));
  assert(list.head->value == 1);
  assert(list.tail->value == 1);
  assert(list.get_size() == 1);
  list.push_back(std::move(2));
  assert(list.head->value == 1);
  assert(list.tail->value == 2);
  assert(list.get_size() == 2);
  list.push_back(std::move(3));
  assert(list.head->value == 1);
  assert(list.tail->value == 3);
  assert(list.get_size() == 3);
  list.push_back(std::move(4));
  assert(list.head->value == 1);
  assert(list.tail->value == 4);
  assert(list.get_size() == 4);
  list.push_back(std::move(5));
  assert(list.head->value == 1);
  assert(list.tail->value == 5);
  assert(list.get_size() == 5);
  std::cout << "test_push_back_move passed" << std::endl;
}

void test_front() {
  DoubleList<int> list;
  list.push_back(1);
  assert(list.front() == 1);
  list.push_back(2);
  assert(list.front() == 1);
  list.push_back(3);
  assert(list.front() == 1);
  list.push_back(4);
  assert(list.front() == 1);
  list.push_back(5);
  assert(list.front() == 1);
  std::cout << "test_front passed" << std::endl;
}

void test_back() {
  DoubleList<int> list;
  list.push_back(1);
  assert(list.back() == 1);
  list.push_back(2);
  assert(list.back() == 2);
  list.push_back(3);
  assert(list.back() == 3);
  list.push_back(4);
  assert(list.back() == 4);
  list.push_back(5);
  assert(list.back() == 5);
  std::cout << "test_back passed" << std::endl;
}

void test_pop_front() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  assert(list.get_size() == 5);
  list.pop_front();
  assert(list.get_size() == 4);
  assert(list.front() == 2);
  list.pop_front();
  assert(list.get_size() == 3);
  assert(list.front() == 3);
  list.pop_front();
  assert(list.get_size() == 2);
  assert(list.front() == 4);
  list.pop_front();
  assert(list.get_size() == 1);
  assert(list.front() == 5);
  list.pop_front();
  assert(list.get_size() == 0);
  std::cout << "test_pop_front passed" << std::endl;
}

void test_pop_back() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  assert(list.get_size() == 5);
  list.pop_back();
  assert(list.get_size() == 4);
  assert(list.back() == 4);
  list.pop_back();
  assert(list.get_size() == 3);
  assert(list.back() == 3);
  list.pop_back();
  assert(list.get_size() == 2);
  assert(list.back() == 2);
  list.pop_back();
  assert(list.get_size() == 1);
  assert(list.back() == 1);
  list.pop_back();
  assert(list.get_size() == 0);
  std::cout << "test_pop_back passed" << std::endl;
}

void test_clear() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  assert(list.get_size() == 5);
  list.clear();
  assert(list.get_size() == 0);
  std::cout << "test_clear passed" << std::endl;
}

void test_index_operator() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  assert(list[0] == 1);
  assert(list[1] == 2);
  assert(list[2] == 3);
  assert(list[3] == 4);
  assert(list[4] == 5);
  std::cout << "test_index_operator passed" << std::endl;
}

void test_index_operator_const() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  const DoubleList<int> &const_list = list;
  assert(const_list[0] == 1);
  assert(const_list[1] == 2);
  assert(const_list[2] == 3);
  assert(const_list[3] == 4);
  assert(const_list[4] == 5);
  std::cout << "test_index_operator_const passed" << std::endl;
}

void test_erase() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  assert(list.get_size() == 5);
  list.erase(0);
  assert(list.get_size() == 4);
  assert(list[0] == 2);
  assert(list[1] == 3);
  assert(list[2] == 4);
  assert(list[3] == 5);
  list.erase(1);
  assert(list.get_size() == 3);
  assert(list[0] == 2);
  assert(list[1] == 4);
  assert(list[2] == 5);
  list.erase(2);
  assert(list.get_size() == 2);
  assert(list[0] == 2);
  assert(list[1] == 4);
  list.erase(1);
  assert(list.get_size() == 1);
  assert(list[0] == 2);
  list.erase(0);
  assert(list.get_size() == 0);
  std::cout << "test_erase passed" << std::endl;
}

void test_index() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  assert(list.index(1) == 0);
  assert(list.index(2) == 1);
  assert(list.index(3) == 2);
  assert(list.index(4) == 3);
  assert(list.index(5) == 4);
  std::cout << "test_index passed" << std::endl;
}

void test_insert() {
  DoubleList<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  assert(list.get_size() == 5);
  list.insert(0, 0);
  assert(list.get_size() == 6);
  assert(list[0] == 0);
  assert(list[1] == 1);
  assert(list[2] == 2);
  assert(list[3] == 3);
  assert(list[4] == 4);
  assert(list[5] == 5);
  list.insert(1, 10);
  assert(list.get_size() == 7);
  assert(list[0] == 0);
  assert(list[1] == 10);
  assert(list[2] == 1);
  assert(list[3] == 2);
  assert(list[4] == 3);
  assert(list[5] == 4);
  assert(list[6] == 5);
  std::cout << "test_insert passed" << std::endl;
}

void test_insert_move() {
  DoubleList<int> list;
  list.push_back(std::move(1));
  list.push_back(std::move(2));
  list.push_back(std::move(3));
  list.push_back(std::move(4));
  list.push_back(std::move(5));
  assert(list.get_size() == 5);
  list.insert(0, std::move(0));
  assert(list.get_size() == 6);
  assert(list[0] == 0);
  assert(list[1] == 1);
  assert(list[2] == 2);
  assert(list[3] == 3);
  assert(list[4] == 4);
  assert(list[5] == 5);
  list.insert(1, std::move(10));
  assert(list.get_size() == 7);
  assert(list[0] == 0);
  assert(list[1] == 10);
  assert(list[2] == 1);
  assert(list[3] == 2);
  assert(list[4] == 3);
  assert(list[5] == 4);
  assert(list[6] == 5);
  std ::cout << "test_insert_move passed" << std::endl;
}

void run_tests() {
  test_default_constructor();
  test_copy_constructor();
  test_move_constructor();
  test_copy_assignment();
  test_move_assignment();
  test_empty();
  test_get_size();
  test_push_front();
  test_push_front_move();
  test_push_back();
  test_push_back_move();
  test_front();
  test_back();
  test_pop_front();
  test_pop_back();
  test_index_operator();
  test_index_operator_const();
  test_erase();
  test_index();
  test_insert();
  test_insert_move();
}