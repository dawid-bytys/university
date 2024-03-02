#include <iostream>
#include <vector>

template <size_t N, typename T>
T dot_product(const T (&first_vector)[N], const T (&second_vector)[N]) {
  T result = 0.0;

  for (size_t i = 0; i < N; ++i) {
    result += first_vector[i] * second_vector[i];
  }

  return result;
}

int main() {
  int int_first_vector[3] = {1, 2, 3};
  int int_second_vector[3] = {4, 5, 6};
  int int_result = dot_product(int_first_vector, int_second_vector);

  std::cout << "Dot product between [1, 2, 3] and [4, 5, 6] is " << int_result
            << std::endl;

  double double_first_vector[3] = {1.3, 2.8, 3.2};
  double double_second_vector[3] = {4.4, 5.3, 6.8};
  double double_result = dot_product(double_first_vector, double_second_vector);

  std::cout << "Dot product between [1.3, 2.8, 3.2] and [4.4, 5.3, 6.8] is "
            << double_result << std::endl;

  return 0;
}
