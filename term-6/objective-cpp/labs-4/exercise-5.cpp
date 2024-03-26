#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <forward_list>

template<typename Iterator>
struct traits_category {
  using iterator_category = typename std::iterator_traits<Iterator>::iterator_category;

  static constexpr int value =
    std::is_same<iterator_category, std::random_access_iterator_tag>::value ? 0 :
    std::is_same<iterator_category, std::bidirectional_iterator_tag>::value ? 1 : 2;
};

template<typename Iterator>
void select_algorithm(Iterator begin, Iterator end) {
  if constexpr (traits_category<Iterator>::value == 0) {
    std::cout << "Wybieram algorytm dla swobodnego dostepu" << std::endl;
  } else if constexpr (traits_category<Iterator>::value == 1) {
    std::cout << "Wybieram algorytm dla iteratorów dwukierunkowych" << std::endl;
  } else {
    std::cout << "Wybieram algorytm dla iteratorów gorszych niż dwukierunkowe" << std::endl;
  }
}

int main() {
  std::vector<int> vector = {1, 2, 3, 4, 5};
  select_algorithm(vector.begin(), vector.end());

  std::list<int> list = {1, 2, 3, 4, 5};
  select_algorithm(list.begin(), list.end());

  std::forward_list<int> forward_list = {1, 2, 3, 4, 5};
  select_algorithm(forward_list.begin(), forward_list.end());

  return 0;
}
