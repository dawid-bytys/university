#include <iostream>
#include <vector>

template <typename T>
struct is_class {
  private:
    template <typename U>
    static char test(int U::*);

    template <typename U>
    static int test(...);

  public:
    static constexpr bool value = (sizeof(test<T>(0)) == sizeof(char));
};

class MyClass {};
struct MyStruct {};

int main() {
  std::cout << is_class<MyClass>::value << std::endl;
  std::cout << is_class<MyStruct>::value << std::endl;
  std::cout << is_class<int>::value << std::endl;

  return 0;
}
