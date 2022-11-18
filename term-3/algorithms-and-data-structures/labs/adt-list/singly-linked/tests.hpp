#ifndef TESTS_HPP
#define TESTS_HPP

#include <cassert>
#include <iostream>

#include "singlelist.hpp"

void test_copy_constructor() {
  SingleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  SingleList<int> list2(list);
  assert(list2.size() == 3);
  assert(list2.head->value == 3);
  assert(list2.tail->value == 1);
  assert(list2.head->next->value == 2);
  assert(list2.tail->next == nullptr);
  assert(list2.head->next->next->value == 1);
  assert(list2.head->next->next->next == nullptr);
  std::cout << "test_copy_constructor passed" << std::endl;
}

void test_move_constructor() {
  SingleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  SingleList<int> list2(std::move(list));
  assert(list.size() == 0);
  assert(list.head == nullptr);
  assert(list.tail == nullptr);
  assert(list2.size() == 3);
  assert(list2.head->value == 3);
  assert(list2.tail->value == 1);
  assert(list2.head->next->value == 2);
  assert(list2.tail->next == nullptr);
  assert(list2.head->next->next->value == 1);
  assert(list2.head->next->next->next == nullptr);
  std::cout << "test_move_constructor passed" << std::endl;
}

void test_copy_assignment_operator() {
  SingleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  SingleList<int> list2;
  list2 = list;
  assert(list2.size() == 3);
  assert(list2.head->value == 3);
  assert(list2.tail->value == 1);
  assert(list2.head->next->value == 2);
  assert(list2.tail->next == nullptr);
  assert(list2.head->next->next->value == 1);
  assert(list2.head->next->next->next == nullptr);
  std::cout << "test_copy_assignment_operator passed" << std::endl;
}

void test_move_assignment_operator() {
  SingleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  SingleList<int> list2;
  list2 = std::move(list);
  assert(list.size() == 0);
  assert(list.head == nullptr);
  assert(list.tail == nullptr);
  assert(list2.size() == 3);
  assert(list2.head->value == 3);
  assert(list2.tail->value == 1);
  assert(list2.head->next->value == 2);
  assert(list2.tail->next == nullptr);
  assert(list2.head->next->next->value == 1);
  assert(list2.head->next->next->next == nullptr);
  std::cout << "test_move_assignment_operator passed" << std::endl;
}

void test_empty() {
  SingleList<int> list;
  assert(list.empty() == true);
  list.push_front(1);
  assert(list.empty() == false);
  std::cout << "test_empty passed" << std::endl;
}

void test_size() {
  SingleList<int> list;
  assert(list.size() == 0);
  list.push_front(1);
  assert(list.size() == 1);
  list.push_front(2);
  assert(list.size() == 2);
  list.push_front(3);
  assert(list.size() == 3);
  std::cout << "test_size passed" << std::endl;
}

void test_push_front() {
  SingleList<int> list;
  list.push_front(1);
  assert(list.size() == 1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);
  assert(list.head->next == nullptr);
  assert(list.tail->next == nullptr);
  list.push_front(2);
  assert(list.size() == 2);
  assert(list.head->value == 2);
  assert(list.tail->value == 1);
  assert(list.head->next->value == 1);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next == nullptr);
  list.push_front(3);
  assert(list.size() == 3);
  assert(list.head->value == 3);
  assert(list.tail->value == 1);
  assert(list.head->next->value == 2);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next->value == 1);
  assert(list.head->next->next->next == nullptr);
  std::cout << "test_push_front passed" << std::endl;
}

void test_push_front_move() {
  SingleList<int> list;
  list.push_front(1);
  assert(list.size() == 1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);
  assert(list.head->next == nullptr);
  assert(list.tail->next == nullptr);
  list.push_front(std::move(2));
  assert(list.size() == 2);
  assert(list.head->value == 2);
  assert(list.tail->value == 1);
  assert(list.head->next->value == 1);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next == nullptr);
  list.push_front(std::move(3));
  assert(list.size() == 3);
  assert(list.head->value == 3);
  assert(list.tail->value == 1);
  assert(list.head->next->value == 2);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next->value == 1);
  assert(list.head->next->next->next == nullptr);
  std::cout << "test_push_front_move passed" << std::endl;
}

void test_push_back() {
  SingleList<int> list;
  list.push_back(1);
  assert(list.size() == 1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);
  assert(list.head->next == nullptr);
  assert(list.tail->next == nullptr);
  list.push_back(2);
  assert(list.size() == 2);
  assert(list.head->value == 1);
  assert(list.tail->value == 2);
  assert(list.head->next->value == 2);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next == nullptr);
  list.push_back(3);
  assert(list.size() == 3);
  assert(list.head->value == 1);
  assert(list.tail->value == 3);
  assert(list.head->next->value == 2);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next->value == 3);
  assert(list.head->next->next->next == nullptr);
  std::cout << "test_push_back passed" << std::endl;
}

void test_push_back_move() {
  SingleList<int> list;
  list.push_back(1);
  assert(list.size() == 1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);
  assert(list.head->next == nullptr);
  assert(list.tail->next == nullptr);
  list.push_back(std::move(2));
  assert(list.size() == 2);
  assert(list.head->value == 1);
  assert(list.tail->value == 2);
  assert(list.head->next->value == 2);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next == nullptr);
  list.push_back(std::move(3));
  assert(list.size() == 3);
  assert(list.head->value == 1);
  assert(list.tail->value == 3);
  assert(list.head->next->value == 2);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next->value == 3);
  assert(list.head->next->next->next == nullptr);
  std::cout << "test_push_back_move passed" << std::endl;
}

void test_front() {
  SingleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  assert(list.front() == 3);
  list.pop_front();
  assert(list.front() == 2);
  list.pop_front();
  assert(list.front() == 1);
  list.pop_front();
  std::cout << "test_front passed" << std::endl;
}

void test_back() {
  SingleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  assert(list.back() == 1);
  list.pop_back();
  assert(list.back() == 2);
  list.pop_back();
  assert(list.back() == 3);
  list.pop_back();
  std::cout << "test_back passed" << std::endl;
}

void test_pop_front() {
  SingleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.pop_front();
  assert(list.size() == 2);
  assert(list.head->value == 2);
  assert(list.tail->value == 1);
  assert(list.head->next->value == 1);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next == nullptr);
  list.pop_front();
  assert(list.size() == 1);
  assert(list.head->value == 1);
  assert(list.tail->value == 1);
  assert(list.head->next == nullptr);
  assert(list.tail->next == nullptr);
  list.pop_front();
  assert(list.size() == 0);
  assert(list.head == nullptr);
  assert(list.tail == nullptr);
  std::cout << "test_pop_front passed" << std::endl;
}

void test_pop_back() {
  SingleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.pop_back();
  assert(list.size() == 2);
  assert(list.head->value == 3);
  assert(list.tail->value == 2);
  assert(list.head->next->value == 2);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next == nullptr);
  list.pop_back();
  assert(list.size() == 1);
  assert(list.head->value == 3);
  assert(list.tail->value == 3);
  assert(list.head->next == nullptr);
  assert(list.tail->next == nullptr);
  list.pop_back();
  assert(list.size() == 0);
  assert(list.head == nullptr);
  assert(list.tail == nullptr);
  std::cout << "test_pop_back passed" << std::endl;
}

void test_clear() {
  SingleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.clear();
  assert(list.size() == 0);
  assert(list.head == nullptr);
  assert(list.tail == nullptr);
  std::cout << "test_clear passed" << std::endl;
}

void test_reverse() {
  SingleList<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.reverse();
  assert(list.size() == 3);
  assert(list.head->value == 1);
  assert(list.tail->value == 3);
  assert(list.head->next->value == 2);
  assert(list.tail->next == nullptr);
  assert(list.head->next->next->value == 3);
  assert(list.head->next->next->next == nullptr);
  std::cout << "test_reverse passed" << std::endl;
}

#endif