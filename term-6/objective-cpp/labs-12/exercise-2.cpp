#include <compare>
#include <concepts>
#include <iostream>

class MyClass {
 public:
  int value;

  MyClass(int v) : value(v) {}

  auto operator<=>(const MyClass& other) const = default;
};


template <std::three_way_comparable T>
void compare(const T& a, const T& b) {
  if (a < b) {
    std::cout << "a is less than b" << std::endl;
  } else if (a == b) {
    std::cout << "a is equal to b" << std::endl;
  } else if (a > b) {
    std::cout << "a is greater than b" << std::endl;
  }
}

int main() {
  MyClass obj1(10);
  MyClass obj2(20);

  compare(obj1, obj2);

  int x = 5;
  int y = 10;
  compare(x, y);

  return 0;
}
