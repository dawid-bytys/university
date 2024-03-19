#include <iostream>

template <typename T, int N>
class Stack {
 public:
  Stack() {
    std::cout << "Generic Stack<T, N> created" << std::endl;
  }
};

template <typename T>
class Stack<T, 666> {
 public:
  Stack() {
    std::cout << "Specialized Stack<T, 666> created" << std::endl;
  }
};

template <typename T, int N>
class Stack<T*, N> {
 public:
  Stack() {
    std::cout << "Specialized Stack<T*, N> created" << std::endl;
  }
};

template <int N>
class Stack<double, N> {
 public:
  Stack() {
    std::cout << "Specialized Stack<double, N> created" << std::endl;
  }
};

template <int N>
class Stack<int*, N> {
 public:
  Stack() {
    std::cout << "Specialized Stack<int*, N> created" << std::endl;
  }
};

template <>
class Stack<double, 666> {
 public:
  Stack() {
    std::cout << "Specialized Stack<double, 666> created" << std::endl;
  }
};

template <>
class Stack<double*, 44> {
 public:
  Stack() {
    std::cout << "Specialized Stack<double*, 44> created" << std::endl;
  }
};

int main() {
  Stack<int, 10> stack1;
  Stack<int*, 10> stack2;
  Stack<double, 10> stack3;
  Stack<int*, 5> stack4;
  Stack<double, 666> stack5;
  Stack<double*, 44> stack6;
  Stack<double, 100> stack7;

  return 0;
}
