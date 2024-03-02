#include <iostream>

template <typename T>
struct CustomTemplate {
  T value;
};

template <template <typename> class C, typename K>
void f(C<K> instance) {
  std::cout << "Value: " << instance.value << std::endl;
}

int main() {
  CustomTemplate<int> instance;
  instance.value = 42;
  f(instance);

  return 0;
}
