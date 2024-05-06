#include <iostream>

// O(log N)
template <int X, int N>
constexpr int fast_pow = N % 2 == 0 ? fast_pow<X * X, N / 2> : X * fast_pow<X, N - 1>;

template <int X>
constexpr int fast_pow<X, 0> = 1;

template <int X>
constexpr int fast_pow<X, 1> = X;

int main() {
  std::cout << "2^5 = " << fast_pow<2, 5> << std::endl;
  std::cout << "3^4 = " << fast_pow<3, 4> << std::endl;

  return 0;
}
