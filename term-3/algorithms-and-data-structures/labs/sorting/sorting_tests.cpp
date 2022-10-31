#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

#include "bubblesort.hpp"
#include "mergesort.hpp"

#define CONTAINER_SIZE 10

template <typename Container, typename Func>
void test_sorting_algorithm(Container &container, Func func);

int main() {
  std::array<int, CONTAINER_SIZE> bubble_abstract_array = {12, 64, 24, 19, 39,
                                                           33, 75, 70, 84, 51};
  std::vector<int> bubble_vector = {12, 64, 24, 19, 39, 33, 75, 70, 84, 51};
  int bubble_array[CONTAINER_SIZE] = {12, 64, 24, 19, 39, 33, 75, 70, 84, 51};

  // [BUBBLESORT]
  std::cout << "[BUBBLESORT]" << std::endl;
  test_sorting_algorithm(bubble_abstract_array,
                         bubblesort<std::array<int, CONTAINER_SIZE>::iterator>);
  test_sorting_algorithm(bubble_vector, bubblesort<std::vector<int>::iterator>);
  test_sorting_algorithm(bubble_array, bubblesort<int *>);

  // [MERGESORT]
  std::cout << "[MERGESORT]" << std::endl;
  test_sorting_algorithm(bubble_abstract_array,
                         mergesort<std::array<int, CONTAINER_SIZE>::iterator>);
  test_sorting_algorithm(bubble_vector, mergesort<std::vector<int>::iterator>);
  test_sorting_algorithm(bubble_array, mergesort<int *>);

  return 0;
}

template <typename Container, typename Func>
void test_sorting_algorithm(Container &container, Func func) {
  func(std::begin(container), std::end(container));
  assert(std::is_sorted(std::begin(container), std::end(container)));
  std::cout << "Passed!" << std::endl;
}