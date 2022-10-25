#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename Iterator>
void merge(Iterator &begin, Iterator &middle, Iterator &end) {
  std::vector<typename std::iterator_traits<Iterator>::value_type> sorted;
  Iterator left = begin;
  Iterator right = middle;

  while (left != middle && right != end) {
    if (*left < *right) {
      sorted.push_back(*left++);
    } else {
      sorted.push_back(*right++);
    }
  }

  while (left != middle) {
    sorted.push_back(*left++);
  }

  std::copy(sorted.begin(), sorted.end(), begin);
}

template <typename Iterator>
void mergesort(Iterator begin, Iterator end) {
  auto const size = std::distance(begin, end);
  if (size < 2) {
    return;
  }

  auto middle = begin + size / 2;
  mergesort(begin, middle);
  mergesort(middle, end);
  merge(begin, middle, end);
}
