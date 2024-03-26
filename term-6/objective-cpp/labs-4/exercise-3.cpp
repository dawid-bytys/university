#include <iostream>

template <typename T>
struct sum_traits;

template <>
struct sum_traits<char> {
  typedef int sum_type;

  static const sum_type initial_value() {
    return 0;
  }
};

template <>
struct sum_traits<int> {
  typedef long int sum_type;

  static const sum_type initial_value() {
    return 0;
  }
};

template <>
struct sum_traits<float> {
  typedef double sum_type;

  static const sum_type initial_value() {
    return 0.0;
  }
};

template <>
struct sum_traits<double> {
  typedef double sum_type;

  static const sum_type initial_value() {
    return 0.0;
  }
};

template <typename T>
typename sum_traits<T>::sum_type sum(T *begin, T *end) {
  typename sum_traits<T>::sum_type total = sum_traits<T>::initial_value();

  while (begin != end) {
    total += *begin;
    ++begin;
  }

  return total;
}

template <>
typename sum_traits<char>::sum_type sum(char *begin, char *end) {
  typename sum_traits<char>::sum_type total = sum_traits<char>::initial_value();

  while (begin != end) {
    total += *begin;
    ++begin;
  }

  return total;
}

int main() {
  int int_array[] = {1, 2, 3, 4, 5};
  std::cout << "Sum of int_array: " << sum(int_array, int_array + 5)
            << std::endl;

  char char_array[] = {'a', 'b', 'c', 'd', 'e'};
  std::cout << "Sum of char_array: " << static_cast<int>(sum(char_array, char_array + 5))
            << std::endl;

  float float_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::cout << "Sum of float_array: " << sum(float_array, float_array + 5)
            << std::endl;

  double double_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::cout << "Sum of double_array: " << sum(double_array, double_array + 5)
            << std::endl;

  return 0;
}
