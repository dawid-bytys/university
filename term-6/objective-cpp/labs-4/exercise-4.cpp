#include <iostream>

template <typename T>
struct sum_traits;

template <>
struct sum_traits<char> {
  using sum_type = int;

  static const sum_type initial_value() {
    return 0;
  }
};

template <>
struct sum_traits<int> {
  using sum_type = long int;

  static const sum_type initial_value() {
    return 0;
  }
};

template <>
struct sum_traits<float> {
  using sum_type = double;

  static const sum_type initial_value() {
    return 0.0;
  }
};

template <>
struct sum_traits<double> {
  using sum_type = double;

  static const sum_type initial_value() {
    return 0.0;
  }
};

template <typename Iterator>
typename sum_traits<typename std::iterator_traits<Iterator>::value_type>::sum_type sum(Iterator begin, Iterator end) {
  using value_type = typename std::iterator_traits<Iterator>::value_type;
  typename sum_traits<value_type>::sum_type total = sum_traits<value_type>::initial_value();

  while (begin != end) {
    total += *begin;
    ++begin;
  }

  return total;
}

int main() {
  int int_array[] = {1, 2, 3, 4, 5};
  std::cout << "Sum of int_array: " << sum(std::begin(int_array), std::end(int_array))
            << std::endl;

  char char_array[] = {'a', 'b', 'c', 'd', 'e'};
  std::cout << "Sum of char_array: " << sum(std::begin(char_array), std::end(char_array))
            << std::endl;

  float float_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::cout << "Sum of float_array: " << sum(std::begin(float_array), std::end(float_array))
            << std::endl;

  double double_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::cout << "Sum of double_array: " << sum(std::begin(double_array), std::end(double_array))
            << std::endl;

  return 0;
}
