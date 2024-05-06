#include <iostream>

template <unsigned int N>
constexpr unsigned long long factorial = N * factorial<N - 1>;

template <>
constexpr unsigned long long factorial<0> = 1;

int main() {
  std::cout << "5! = " << factorial<5> << std::endl;
  std::cout << "10! = " << factorial<10> << std::endl;

  return 0;
}
