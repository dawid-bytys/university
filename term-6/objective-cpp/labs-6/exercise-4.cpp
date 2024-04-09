#include <type_traits>
#include <iostream>

template <typename T>
struct strip_reference {
  using type = T;
};

template <typename T>
struct strip_reference<const T> {
  using type = T;
};

template <typename T>
struct strip_reference<T&> {
  using type = T;
};

template <typename T>
struct strip_reference<const T&> {
  using type = T;
};

template <typename T>
using strip = typename strip_reference<T>::type;

int main() {
  const int x = 42;
  const int &y = x;

  std::cout << std::is_same<strip<decltype(x)>, int>::value << std::endl;
  std::cout << std::is_same<strip<decltype(y)>, int>::value << std::endl;

  return 0;
}
