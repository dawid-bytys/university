#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T, int size = 0, typename Container = T*>
class Stack;

template <typename T, int size>
class Stack<T, size> {
 private:
  T elements[size];
  int top_index;

 public:
  Stack() : top_index(-1) {}

  void push(const T& value) {
    if (top_index >= size - 1) {
      throw std::out_of_range("Stack<>::push(): stack full");
    }

    elements[++top_index] = value;
  }

  void pop() {
    if (top_index < 0) {
      throw std::out_of_range("Stack<>::pop(): empty stack");
    }

    --top_index;
  }

  T& top() {
    if (top_index < 0) {
      throw std::out_of_range("Stack<>::top(): empty stack");
    }

    return elements[top_index];
  }

  bool empty() const {
    return top_index < 0;
  }

  size_t current_size() const {
    return top_index + 1;
  }
};

template <typename T>
class Stack<T, 0, std::vector<T>> {
 private:
  std::vector<T> elements;

 public:
  Stack() {}

  void push(const T& value) {
    elements.push_back(value);
  }

  void pop() {
    if (elements.empty()) {
      throw std::out_of_range("Stack<>::pop(): empty stack");
    }

    elements.pop_back();
  }

  T& top() {
    if (elements.empty()) {
      throw std::out_of_range("Stack<>::top(): empty stack");
    }

    return elements.back();
  }

  bool empty() const {
    return elements.empty();
  }

  size_t current_size() const {
    return elements.size();
  }
};

int main() {
  Stack<int, 10> table_stack;
  Stack<int, 0, std::vector<int>> vector_stack;

  table_stack.push(1);
  table_stack.push(2);
  vector_stack.push(3);
  vector_stack.push(4);

  std::cout << "Stack<int, 10> elements: ";
  while (!table_stack.empty()) {
    std::cout << table_stack.top() << " ";
    table_stack.pop();
  }
  std::cout << std::endl;

  std::cout << "Stack<int, 0, std::vector<int>> elements: ";
  while (!vector_stack.empty()) {
    std::cout << vector_stack.top() << " ";
    vector_stack.pop();
  }
  std::cout << std::endl;

  return 0;
}
