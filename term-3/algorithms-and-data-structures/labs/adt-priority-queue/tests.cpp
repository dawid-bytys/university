#include <iostream>

#include "assert.h"
#include "mypriorityqueue.hpp"

void test_default_constructor() {
  MyPriorityQueue<int> queue;
  assert(queue.empty());
  assert(queue.size() == 0);
  std::cout << "test_default_constructor passed" << std::endl;
}

void test_copy_constructor() {
  MyPriorityQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  MyPriorityQueue<int> queue2(queue);
  assert(queue2.size() == 3);
  assert(queue2.top() == 3);
  queue2.dequeue();
  assert(queue2.top() == 2);
  queue2.dequeue();
  assert(queue2.top() == 1);
  queue2.dequeue();
  assert(queue2.empty());
  std::cout << "test_copy_constructor passed" << std::endl;
}

void test_move_constructor() {
  MyPriorityQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  MyPriorityQueue<int> queue2(std::move(queue));
  assert(queue2.size() == 3);
  assert(queue2.top() == 3);
  queue2.dequeue();
  assert(queue2.top() == 2);
  queue2.dequeue();
  assert(queue2.top() == 1);
  queue2.dequeue();
  assert(queue2.empty());
  std::cout << "test_move_constructor passed" << std::endl;
}

void test_copy_assignment() {
  MyPriorityQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  MyPriorityQueue<int> queue2;
  queue2 = queue;
  assert(queue2.size() == 3);
  assert(queue2.top() == 3);
  queue2.dequeue();
  assert(queue2.top() == 2);
  queue2.dequeue();
  assert(queue2.top() == 1);
  queue2.dequeue();
  assert(queue2.empty());
  std::cout << "test_copy_assignment passed" << std::endl;
}

void test_move_assignment() {
  MyPriorityQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  MyPriorityQueue<int> queue2;
  queue2 = std::move(queue);
  assert(queue2.size() == 3);
  assert(queue2.top() == 3);
  queue2.dequeue();
  assert(queue2.top() == 2);
  queue2.dequeue();
  assert(queue2.top() == 1);
  queue2.dequeue();
  assert(queue2.empty());
  std::cout << "test_move_assignment passed" << std::endl;
}

void test_empty() {
  MyPriorityQueue<int> queue;
  assert(queue.empty());
  queue.enqueue(1);
  assert(!queue.empty());
  queue.dequeue();
  assert(queue.empty());
  std::cout << "test_empty passed" << std::endl;
}

void test_size() {
  MyPriorityQueue<int> queue;
  assert(queue.size() == 0);
  queue.enqueue(1);
  assert(queue.size() == 1);
  queue.enqueue(2);
  assert(queue.size() == 2);
  queue.dequeue();
  assert(queue.size() == 1);
  queue.dequeue();
  assert(queue.size() == 0);
  std::cout << "test_size passed" << std::endl;
}

void test_enqueue() {
  MyPriorityQueue<int> queue;
  queue.enqueue(1);
  assert(queue.size() == 1);
  assert(queue.top() == 1);
  queue.enqueue(2);
  assert(queue.size() == 2);
  assert(queue.top() == 2);
  queue.enqueue(3);
  assert(queue.size() == 3);
  assert(queue.top() == 3);
  std::cout << "test_enqueue passed" << std::endl;
}

void test_top() {
  MyPriorityQueue<int> queue;
  queue.enqueue(1);
  assert(queue.top() == 1);
  queue.enqueue(2);
  assert(queue.top() == 2);
  queue.enqueue(3);
  assert(queue.top() == 3);
  std::cout << "test_top passed" << std::endl;
}

void test_dequeue() {
  MyPriorityQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(3);
  queue.dequeue();
  assert(queue.size() == 3);
  assert(queue.top() == 3);
  queue.dequeue();
  assert(queue.size() == 2);
  assert(queue.top() == 2);
  queue.dequeue();
  assert(queue.size() == 1);
  assert(queue.top() == 1);
  queue.dequeue();
  assert(queue.size() == 0);
  std::cout << "test_dequeue passed" << std::endl;
}

void test_clear() {
  MyPriorityQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.clear();
  assert(queue.size() == 0);
  std::cout << "test_clear passed" << std::endl;
}

void test_display() {
  MyPriorityQueue<int> queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.display();
  std::cout << "test_display passed" << std::endl;
}

void run_tests() {
  test_default_constructor();
  test_copy_constructor();
  test_move_constructor();
  test_copy_assignment();
  test_move_assignment();
  test_empty();
  test_size();
  test_enqueue();
  test_top();
  test_dequeue();
  test_clear();
  test_display();
}