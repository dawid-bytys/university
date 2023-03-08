#include <cassert>
#include <iostream>

#include "myqueue.hpp"

void test_default_constructor() {
  MyQueue<int> queue;
  assert(queue.empty());
  assert(!queue.full());
  assert(queue.size() == 0);
  assert(queue.max_size() == 10);
  std::cout << "test_default_constructor passed" << std::endl;
}

void test_copy_constructor() {
  MyQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  MyQueue<int> queue2(queue);
  assert(queue2.size() == 3);
  assert(queue2.front() == 1);
  assert(queue2.back() == 3);
  std::cout << "test_copy_constructor passed" << std::endl;
}

void test_move_constructor() {
  MyQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  MyQueue<int> queue2(std::move(queue));
  assert(queue2.size() == 3);
  assert(queue2.front() == 1);
  assert(queue2.back() == 3);
  assert(queue.empty());
  std::cout << "test_move_constructor passed" << std::endl;
}

void test_copy_assignment_operator() {
  MyQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  MyQueue<int> queue2;
  queue2 = queue;
  assert(queue2.size() == 3);
  assert(queue2.front() == 1);
  assert(queue2.back() == 3);
  std::cout << "test_copy_assignment_operator passed" << std::endl;
}

void test_move_assignment_operator() {
  MyQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  MyQueue<int> queue2;
  queue2 = std::move(queue);
  assert(queue2.size() == 3);
  assert(queue2.front() == 1);
  assert(queue2.back() == 3);
  assert(queue.empty());
  std::cout << "test_move_assignment_operator passed" << std::endl;
}

void test_empty() {
  MyQueue<int> queue;
  assert(queue.empty());
  queue.enqueue(1);
  assert(!queue.empty());
  std::cout << "test_empty passed" << std::endl;
}

void test_full() {
  MyQueue<int> queue;
  assert(!queue.full());
  for (int i = 0; i < 10; ++i) {
    queue.enqueue(i);
  }
  assert(queue.full());
  std::cout << "test_full passed" << std::endl;
}

void test_size() {
  MyQueue<int> queue;
  assert(queue.size() == 0);
  queue.enqueue(1);
  assert(queue.size() == 1);
  queue.enqueue(2);
  assert(queue.size() == 2);
  queue.enqueue(3);
  assert(queue.size() == 3);
  std::cout << "test_size passed" << std::endl;
}

void test_max_size() {
  MyQueue<int> queue(13);
  assert(queue.max_size() == 13);
  std::cout << "test_max_size passed" << std::endl;
}

void test_enqueue() {
  MyQueue<int> queue;
  queue.enqueue(1);
  assert(queue.size() == 1);
  assert(queue.front() == 1);
  assert(queue.back() == 1);
  queue.enqueue(2);
  assert(queue.size() == 2);
  assert(queue.front() == 1);
  assert(queue.back() == 2);
  queue.enqueue(3);
  assert(queue.size() == 3);
  assert(queue.front() == 1);
  assert(queue.back() == 3);
  std::cout << "test_enqueue passed" << std::endl;
}

void test_front() {
  MyQueue<int> queue;
  queue.enqueue(1);
  assert(queue.front() == 1);
  queue.enqueue(2);
  assert(queue.front() == 1);
  queue.enqueue(3);
  assert(queue.front() == 1);
  std::cout << "test_front passed" << std::endl;
}

void test_back() {
  MyQueue<int> queue;
  queue.enqueue(1);
  assert(queue.back() == 1);
  queue.enqueue(2);
  assert(queue.back() == 2);
  queue.enqueue(3);
  assert(queue.back() == 3);
  std::cout << "test_back passed" << std::endl;
}

void test_dequeue() {
  MyQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  assert(queue.size() == 3);
  assert(queue.front() == 1);
  assert(queue.back() == 3);
  queue.dequeue();
  assert(queue.size() == 2);
  assert(queue.front() == 2);
  assert(queue.back() == 3);
  queue.dequeue();
  assert(queue.size() == 1);
  assert(queue.front() == 3);
  assert(queue.back() == 3);
  queue.dequeue();
  assert(queue.size() == 0);
  std::cout << "test_dequeue passed" << std::endl;
}

void test_clear() {
  MyQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  assert(queue.size() == 3);
  assert(queue.front() == 1);
  assert(queue.back() == 3);
  queue.clear();
  assert(queue.size() == 0);
  std::cout << "test_clear passed" << std::endl;
}

void test_display() {
  MyQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.display();
  std::cout << "test_display passed" << std::endl;
}

void run_all_tests() {
  test_default_constructor();
  test_copy_constructor();
  test_move_constructor();
  test_copy_assignment_operator();
  test_move_assignment_operator();
  test_empty();
  test_full();
  test_size();
  test_max_size();
  test_enqueue();
  test_front();
  test_back();
  test_dequeue();
  test_clear();
  test_display();
}