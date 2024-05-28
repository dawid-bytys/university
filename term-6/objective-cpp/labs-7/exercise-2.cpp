#include <iostream>
#include <cstdlib>

struct No_checking_policy {
  void check_push(size_t, size_t) const {}
  void check_pop(size_t) const {}
  void check_top(size_t) const {}
};

struct Abort_on_error_policy {
  void check_push(size_t current_size, size_t max_size) const {
    if (current_size >= max_size) {
      std::cerr << "Stack overflow error\n";
      std::abort();
    }
  }

  void check_pop(size_t current_size) const {
    if (current_size == 0) {
      std::cerr << "Stack underflow error\n";
      std::abort();
    }
  }
  
  void check_top(size_t current_size) const {
    if (current_size == 0) {
      std::cerr << "Stack empty error on accessing top\n";
      std::abort();
    }
  }
};

template<typename T = int, size_t N = 100, typename Checking_policy = No_checking_policy>
class Stack {
private:
  T _rep[N];
  size_t _top;
  Checking_policy _policy;

public:
  Stack() : _top(0) {}

  void push(const T& value) {
    _policy.check_push(_top, N);
    _rep[_top++] = value;
  }

  void pop() {
    _policy.check_pop(_top);
    _top--;
  }

  T& top() {
    _policy.check_top(_top);
    return _rep[_top - 1];
  }

  const T& top() const {
    _policy.check_top(_top);
    return _rep[_top - 1];
  }

  bool empty() const {
    return _top == 0;
  }

  size_t size() const {
    return _top;
  }
};

int main() {
  Stack<int, 10, No_checking_policy> stack1;
  stack1.push(1);
  stack1.push(2);
  std::cout << "Top element of stack1: " << stack1.top() << std::endl;
  
  Stack<int, 2, Abort_on_error_policy> stack2;
  stack2.push(1);
  stack2.push(2);
  stack2.push(3);

  return 0;
}
