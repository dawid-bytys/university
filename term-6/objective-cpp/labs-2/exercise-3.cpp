#include <iostream>
#include <iterator>
#include <numeric>

template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type accumulate(Iterator start,
                                                               Iterator end) {
  typename std::iterator_traits<Iterator>::value_type sum = 0;

  for (Iterator it = start; it != end; ++it) {
    sum += *it;
  }

  return sum;
}

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  auto sum = accumulate(numbers.begin(), numbers.end());
  std::cout << "Sum: " << sum << std::endl;

  return 0;
}
