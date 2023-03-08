#include "rpn.hpp"

#include "mystack.hpp"

int rpn(std::vector<std::string> input) {
  MyStack<int> stack;
  for (auto& token : input) {
    if (token == "+") {
      const int a = stack.top();
      stack.pop();
      const int b = stack.top();
      stack.pop();
      stack.push(a + b);
    } else if (token == "-") {
      const int a = stack.top();
      stack.pop();
      const int b = stack.top();
      stack.pop();
      stack.push(b - a);
    } else if (token == "*") {
      const int a = stack.top();
      stack.pop();
      const int b = stack.top();
      stack.pop();
      stack.push(a * b);
    } else if (token == "/") {
      const int a = stack.top();
      stack.pop();
      const int b = stack.top();
      stack.pop();
      stack.push(b / a);
    } else {
      stack.push(std::stoi(token));
    }
  }
  return stack.top();
}