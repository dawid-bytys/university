#include <iostream>

template <int N, int M>
constexpr int pow = N * pow<N, M - 1>;

template <int N>
constexpr int pow<N, 0> = 1;

int main() {
  std::cout << "3^4 = " << pow<3, 4> << std::endl;
  std::cout << "2^10 = " << pow<2, 10> << std::endl;
  
  return 0;
}
