#include <algorithm>

template <typename Iterator>
void bubblesort(Iterator begin, Iterator end) {
  for (Iterator i = begin; i != end; ++i) {
    for (Iterator j = begin; j != end - 1; ++j) {
      if (*j > *(j + 1)) {
        std::swap(*j, *(j + 1));
      }
    }
  }
}
