#include <iostream>

#include "mystack.hpp"
#include "rpn.hpp"

void test_default_constructor() {
  MyStack<int> stack;
  assert(stack.empty());
  assert(!stack.full());
  assert(stack.size() == 0);
  assert(stack.max_size() == 10);
  std::cout << "test_default_constructor passed" << std::endl;
}

void test_copy_constructor() {
  MyStack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  MyStack<int> stack2(stack);
  assert(stack2.size() == 3);
  assert(stack2.top() == 3);
  stack2.pop();
  assert(stack2.top() == 2);
  stack2.pop();
  assert(stack2.top() == 1);
  stack2.pop();
  assert(stack2.empty());
  std::cout << "test_copy_constructor passed" << std::endl;
}

void test_move_constructor() {
  MyStack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  MyStack<int> stack2(std::move(stack));
  assert(stack2.size() == 3);
  assert(stack2.top() == 3);
  stack2.pop();
  assert(stack2.top() == 2);
  stack2.pop();
  assert(stack2.top() == 1);
  stack2.pop();
  assert(stack2.empty());
  std::cout << "test_move_constructor passed" << std::endl;
}

void test_copy_assignment_operator() {
  MyStack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  MyStack<int> stack2;
  stack2 = stack;
  assert(stack2.size() == 3);
  assert(stack2.top() == 3);
  stack2.pop();
  assert(stack2.top() == 2);
  stack2.pop();
  assert(stack2.top() == 1);
  stack2.pop();
  assert(stack2.empty());
  std::cout << "test_copy_assignment_operator passed" << std::endl;
}

void test_move_assignment_operator() {
  MyStack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  MyStack<int> stack2;
  stack2 = std::move(stack);
  assert(stack2.size() == 3);
  assert(stack2.top() == 3);
  stack2.pop();
  assert(stack2.top() == 2);
  stack2.pop();
  assert(stack2.top() == 1);
  stack2.pop();
  assert(stack2.empty());
  std::cout << "test_move_assignment_operator passed" << std::endl;
}

void test_empty() {
  MyStack<int> stack;
  assert(stack.empty());
  stack.push(1);
  assert(!stack.empty());
  stack.pop();
  assert(stack.empty());
  std::cout << "test_empty passed" << std::endl;
}

void test_full() {
  MyStack<int> stack;
  assert(!stack.full());
  for (int i = 0; i < 10; ++i) {
    stack.push(i);
  }
  assert(stack.full());
  std::cout << "test_full passed" << std::endl;
}

void test_size() {
  MyStack<int> stack;
  assert(stack.size() == 0);
  stack.push(1);
  assert(stack.size() == 1);
  stack.push(2);
  assert(stack.size() == 2);
  stack.pop();
  assert(stack.size() == 1);
  stack.pop();
  assert(stack.size() == 0);
  std::cout << "test_size passed" << std::endl;
}

void test_max_size() {
  MyStack<int> stack;
  assert(stack.max_size() == 10);
  std::cout << "test_max_size passed" << std::endl;
}

void test_push() {
  MyStack<int> stack;
  stack.push(1);
  assert(stack.top() == 1);
  stack.push(2);
  assert(stack.top() == 2);
  stack.push(3);
  assert(stack.top() == 3);
  std::cout << "test_push passed" << std::endl;
}

void test_top() {
  MyStack<int> stack;
  stack.push(1);
  assert(stack.top() == 1);
  stack.push(2);
  assert(stack.top() == 2);
  stack.push(3);
  assert(stack.top() == 3);
  std::cout << "test_top passed" << std::endl;
}

void test_pop() {
  MyStack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.pop();
  assert(stack.top() == 2);
  stack.pop();
  assert(stack.top() == 1);
  stack.pop();
  assert(stack.empty());
  std::cout << "test_pop passed" << std::endl;
}

void test_clear() {
  MyStack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.clear();
  assert(stack.empty());
  std::cout << "test_clear passed" << std::endl;
}

void test_display() {
  MyStack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.display();
  std::cout << "test_display passed" << std::endl;
}

void test_rpn() {
  assert(rpn({"8", "7", "+"}) == 15);
  assert(rpn({"99", "11", "+", "8", "7", "+", "+"}) == 125);
  assert(rpn({"4", "7", "*"}) == 28);
  assert(rpn({"4", "7", "*", "5", "2", "*", "*"}) == 280);
  assert(rpn({"8", "3", "-"}) == 5);
  assert(rpn({"33", "3", "-", "10", "6", "-", "-"}) == 26);
  assert(rpn({"15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-"}) == 5);
  std::cout << "test_rpn passed" << std::endl;
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
  test_push();
  test_top();
  test_pop();
  test_clear();
  test_display();
  test_rpn();
}