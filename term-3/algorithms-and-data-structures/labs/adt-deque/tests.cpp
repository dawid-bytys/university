#include <cassert>
#include <iostream>

#include "mydeque.hpp"

void test_default_constructor() {
  MyDeque<int> deque;
  assert(deque.empty());
  assert(deque.size() == 0);
  assert(deque.max_size() == 10);
  std::cout << "test_default_constructor passed" << std::endl;
}

void test_parameterized_constructor() {
  MyDeque<int> deque(5);
  assert(deque.empty());
  assert(deque.size() == 0);
  assert(deque.max_size() == 5);
  try {
    MyDeque<int> deque(-10);
    assert(false);
  } catch (std::invalid_argument &e) {
    assert(true);
  }
  std::cout << "test_parameterized_constructor passed" << std::endl;
}

void test_initializer_copy_list_constructor() {
  MyDeque<int> deque = {1, 2, 3, 4, 5};
  assert(!deque.empty());
  assert(deque.size() == 5);
  assert(deque.max_size() == 5);
  std::cout << "test_initializer_copy_list_constructor passed" << std::endl;
}

void test_initializer_list_constructor() {
  MyDeque<int> deque({1, 2, 3, 4, 5});
  assert(!deque.empty());
  assert(deque.size() == 5);
  assert(deque.max_size() == 5);
  std::cout << "test_initializer_list_constructor passed" << std::endl;
}

void test_copy_constructor() {
  MyDeque<int> deque1 = {1, 2, 3, 4, 5};
  MyDeque<int> deque2(deque1);
  assert(!deque2.empty());
  assert(deque2.size() == 5);
  assert(deque2.max_size() == 5);
  assert(!deque1.empty());
  assert(deque1.size() == 5);
  assert(deque1.max_size() == 5);
  std::cout << "test_copy_constructor passed" << std::endl;
}

void test_move_constructor() {
  MyDeque<int> deque1 = {1, 2, 3, 4, 5};
  MyDeque<int> deque2(std::move(deque1));
  assert(!deque2.empty());
  assert(deque2.size() == 5);
  assert(deque2.max_size() == 5);
  assert(deque1.empty());
  assert(deque1.size() == 0);
  assert(deque1.max_size() == 5);
  std::cout << "test_move_constructor passed" << std::endl;
}

void test_copy_assignment_operator() {
  MyDeque<int> deque1 = {1, 2, 3, 4, 5};
  MyDeque<int> deque2;
  deque2 = deque1;
  assert(!deque2.empty());
  assert(deque2.size() == 5);
  assert(deque2.max_size() == 5);
  assert(!deque1.empty());
  assert(deque1.size() == 5);
  assert(deque1.max_size() == 5);
  std::cout << "test_copy_assignment_operator passed" << std::endl;
}

void test_move_assignment_operator() {
  MyDeque<int> deque1 = {1, 2, 3, 4, 5};
  MyDeque<int> deque2;
  deque2 = std::move(deque1);
  assert(!deque2.empty());
  assert(deque2.size() == 5);
  assert(deque2.max_size() == 5);
  assert(deque1.empty());
  assert(deque1.size() == 0);
  assert(deque1.max_size() == 5);
  std::cout << "test_move_assignment_operator passed" << std::endl;
}

void test_empty() {
  MyDeque<int> deque;
  assert(deque.empty());
  deque.push_back(1);
  assert(!deque.empty());
  deque.pop_back();
  assert(deque.empty());
  std::cout << "test_empty passed" << std::endl;
}

void test_full() {
  MyDeque<int> deque(5);
  assert(!deque.full());
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  assert(deque.full());
  deque.pop_back();
  assert(!deque.full());
  std::cout << "test_full passed" << std::endl;
}

void test_size() {
  MyDeque<int> deque;
  assert(deque.size() == 0);
  deque.push_back(1);
  assert(deque.size() == 1);
  deque.push_back(2);
  assert(deque.size() == 2);
  deque.push_back(3);
  assert(deque.size() == 3);
  deque.push_back(4);
  assert(deque.size() == 4);
  deque.push_back(5);
  assert(deque.size() == 5);
  deque.pop_back();
  assert(deque.size() == 4);
  deque.pop_back();
  assert(deque.size() == 3);
  deque.pop_back();
  assert(deque.size() == 2);
  deque.pop_back();
  assert(deque.size() == 1);
  deque.pop_back();
  assert(deque.size() == 0);
  std::cout << "test_size passed" << std::endl;
}

void test_max_size() {
  MyDeque<int> deque;
  assert(deque.max_size() == 10);
  MyDeque<int> deque2(5);
  assert(deque2.max_size() == 5);
  std::cout << "test_max_size passed" << std::endl;
}

void test_push_front() {
  MyDeque<int> deque(5);
  deque.push_front(1);
  assert(deque.front() == 1);
  deque.push_front(2);
  assert(deque.front() == 2);
  deque.push_front(3);
  assert(deque.front() == 3);
  deque.push_front(4);
  assert(deque.front() == 4);
  deque.push_front(5);
  assert(deque.front() == 5);
  try {
    deque.push_front(6);
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "push_front passed" << std::endl;
}

void test_push_front_move() {
  MyDeque<int> deque(5);
  deque.push_front(std::move(1));
  assert(deque.front() == 1);
  deque.push_front(std::move(2));
  assert(deque.front() == 2);
  deque.push_front(std::move(3));
  assert(deque.front() == 3);
  deque.push_front(std::move(4));
  assert(deque.front() == 4);
  deque.push_front(std::move(5));
  assert(deque.front() == 5);
  try {
    deque.push_front(std::move(6));
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "push_front_move passed" << std::endl;
}

void test_push_back() {
  MyDeque<int> deque(5);
  deque.push_back(1);
  assert(deque.back() == 1);
  deque.push_back(2);
  assert(deque.back() == 2);
  deque.push_back(3);
  assert(deque.back() == 3);
  deque.push_back(4);
  assert(deque.back() == 4);
  deque.push_back(5);
  assert(deque.back() == 5);
  try {
    deque.push_back(6);
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "test_push_back passed" << std::endl;
}

void test_push_back_move() {
  MyDeque<int> deque(5);
  deque.push_back(std::move(1));
  assert(deque.back() == 1);
  deque.push_back(std::move(2));
  assert(deque.back() == 2);
  deque.push_back(std::move(3));
  assert(deque.back() == 3);
  deque.push_back(std::move(4));
  assert(deque.back() == 4);
  deque.push_back(std::move(5));
  assert(deque.back() == 5);
  try {
    deque.push_back(std::move(6));
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "test_push_back_move passed" << std::endl;
}

void test_front() {
  MyDeque<int> deque(5);
  deque.push_back(1);
  assert(deque.front() == 1);
  deque.push_back(2);
  assert(deque.front() == 1);
  deque.push_back(3);
  assert(deque.front() == 1);
  deque.push_back(4);
  assert(deque.front() == 1);
  deque.push_back(5);
  assert(deque.front() == 1);
  std::cout << "test_front passed" << std::endl;
}

void test_back() {
  MyDeque<int> deque(5);
  deque.push_back(1);
  assert(deque.back() == 1);
  deque.push_back(2);
  assert(deque.back() == 2);
  deque.push_back(3);
  assert(deque.back() == 3);
  deque.push_back(4);
  assert(deque.back() == 4);
  deque.push_back(5);
  assert(deque.back() == 5);
  std::cout << "test_back passed" << std::endl;
}

void test_pop_front() {
  MyDeque<int> deque(5);
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  deque.pop_front();
  assert(deque.front() == 2);
  deque.pop_front();
  assert(deque.front() == 3);
  deque.pop_front();
  assert(deque.front() == 4);
  deque.pop_front();
  assert(deque.front() == 5);
  deque.pop_front();
  try {
    deque.front();
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "test_pop_front passed" << std::endl;
}

void test_pop_back() {
  MyDeque<int> deque(5);
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  deque.pop_back();
  assert(deque.back() == 4);
  deque.pop_back();
  assert(deque.back() == 3);
  deque.pop_back();
  assert(deque.back() == 2);
  deque.pop_back();
  assert(deque.back() == 1);
  deque.pop_back();
  try {
    deque.back();
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "test_pop_back passed" << std::endl;
}

void test_clear() {
  MyDeque<int> deque(5);
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  deque.clear();
  assert(deque.size() == 0);
  assert(deque.empty());
  try {
    deque.front();
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  try {
    deque.back();
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "test_clear passed" << std::endl;
}

void test_access_operator() {
  MyDeque<int> deque(5);
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  assert(deque[0] == 1);
  assert(deque[1] == 2);
  assert(deque[2] == 3);
  assert(deque[3] == 4);
  assert(deque[4] == 5);
  try {
    deque[5];
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "test_access_operator passed" << std::endl;
}

void test_erase() {
  MyDeque<int> deque(5);
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  deque.erase(0);
  assert(deque.size() == 4);
  assert(deque[0] == 2);
  assert(deque[1] == 3);
  assert(deque[2] == 4);
  assert(deque[3] == 5);
  deque.erase(1);
  assert(deque.size() == 3);
  assert(deque[0] == 2);
  assert(deque[1] == 4);
  assert(deque[2] == 5);
  deque.erase(2);
  assert(deque.size() == 2);
  assert(deque[0] == 2);
  assert(deque[1] == 4);
  deque.erase(1);
  assert(deque.size() == 1);
  assert(deque[0] == 2);
  deque.erase(0);
  assert(deque.size() == 0);
  try {
    deque.erase(0);
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "test_erase passed" << std::endl;
}

void test_index() {
  MyDeque<int> deque(5);
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  assert(deque.index(1) == 0);
  assert(deque.index(2) == 1);
  assert(deque.index(3) == 2);
  assert(deque.index(4) == 3);
  assert(deque.index(5) == 4);
  assert(deque.index(6) == -1);
  std::cout << "test_index passed" << std::endl;
}

void test_insert() {
  MyDeque<int> deque(6);
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  deque.insert(0, 6);
  assert(deque.size() == 6);
  assert(deque[0] == 6);
  assert(deque[1] == 1);
  assert(deque[2] == 2);
  assert(deque[3] == 3);
  assert(deque[4] == 4);
  assert(deque[5] == 5);
  try {
    deque.insert(7, 7);
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "test_insert passed" << std::endl;
}

void test_insert_move() {
  MyDeque<int> deque(6);
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  deque.insert(0, std::move(6));
  assert(deque.size() == 6);
  assert(deque[0] == 6);
  assert(deque[1] == 1);
  assert(deque[2] == 2);
  assert(deque[3] == 3);
  assert(deque[4] == 4);
  assert(deque[5] == 5);
  try {
    deque.insert(7, std::move(7));
    assert(false);
  } catch (std::out_of_range &e) {
    assert(true);
  }
  std::cout << "test_insert_move passed" << std::endl;
}

void run_tests() {
  test_default_constructor();
  test_parameterized_constructor();
  test_initializer_copy_list_constructor();
  test_initializer_list_constructor();
  test_copy_constructor();
  test_move_constructor();
  test_copy_assignment_operator();
  test_move_assignment_operator();
  test_empty();
  test_full();
  test_size();
  test_max_size();
  test_push_front();
  test_push_front_move();
  test_push_back();
  test_push_back_move();
  test_pop_front();
  test_pop_back();
  test_front();
  test_back();
  test_clear();
  test_access_operator();
  test_erase();
  test_index();
  test_insert();
  test_insert_move();
}