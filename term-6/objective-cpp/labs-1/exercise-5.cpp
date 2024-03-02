#include <iostream>
#include <stack>

template <typename Stack>
typename Stack::value_type stack_sum(const Stack& stack) {
  typename Stack::value_type sum = 0;

  Stack tempStack = stack;

  while (!tempStack.empty()) {
    sum += tempStack.top();
    tempStack.pop();
  }

  return sum;
}

int main() {
  std::stack<int> int_stack;

  for (int i = 0; i < 10; ++i) {
    int_stack.push(i);
  }

  std::cout << "Sum of the stack is " << stack_sum(int_stack) << std::endl;

  std::stack<double> double_stack;

  for (int i = 0; i < 10; ++i) {
    double_stack.push(i + 0.5);
  }

  std::cout << "Sum of the stack is " << stack_sum(double_stack) << std::endl;

  return 0;
}