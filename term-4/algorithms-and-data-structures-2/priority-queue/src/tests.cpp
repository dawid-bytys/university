#include <cassert>
#include <iostream>

#include "../include/PriorityQueue.h"

void test_constructor() {
  PriorityQueue queue;
  assert(queue.empty());
  assert(queue.size() == 0);

  std::cout << "test_constructor passed" << std::endl;
}

void test_empty() {
  PriorityQueue queue;
  assert(queue.empty());

  queue.enqueue(1);
  assert(!queue.empty());

  queue.dequeue();
  assert(queue.empty());

  std::cout << "test_empty passed" << std::endl;
}

void test_size() {
  PriorityQueue queue;
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
  PriorityQueue queue;
  queue.enqueue(1);
  assert(queue.top() == 1);

  queue.enqueue(2);
  assert(queue.top() == 2);

  queue.enqueue(3);
  assert(queue.top() == 3);

  std::cout << "test_enqueue passed" << std::endl;
}

void test_dequeue() {
  PriorityQueue queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  queue.dequeue();
  assert(queue.top() == 2);

  queue.dequeue();
  assert(queue.top() == 1);

  queue.dequeue();
  assert(queue.top() == -1);

  std::cout << "test_dequeue passed" << std::endl;
}

void test_top() {
  PriorityQueue queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  assert(queue.top() == 3);

  queue.dequeue();
  assert(queue.top() == 2);

  queue.dequeue();
  assert(queue.top() == 1);

  queue.dequeue();
  assert(queue.top() == -1);

  std::cout << "test_top passed" << std::endl;
}

void test_display() {
  PriorityQueue queue;
  queue.enqueue(3);
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(4);
  queue.enqueue(5);
  queue.enqueue(6);
  queue.enqueue(7);
  queue.enqueue(8);

  queue.display();

  std::cout << "test_display passed" << std::endl;
}

void run_all_tests() {
  test_constructor();
  test_empty();
  test_size();
  test_enqueue();
  test_dequeue();
  test_top();
  test_display();
}