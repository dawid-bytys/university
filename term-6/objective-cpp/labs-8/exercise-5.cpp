#include <iostream>

template <size_t N>
constexpr double dot_product(const double *x, const double *y, size_t index = 0) {
  if (index < N) {
    return x[index] * y[index] + dot_product<N>(x, y, index + 1);
  }

  return 0.0;
}

int main() {
  constexpr double arr_1[3] = {1.0, 2.0, 3.0};
  constexpr double arr_2[3] = {4.0, 5.0, 6.0};

  constexpr double result = dot_product<3>(arr_1, arr_2);  
  std::cout << "Iloczyn skalarny = " << result << std::endl;

  return 0;
}
