#include "tests.hpp"

int main() {
  test_move_constructor();
  test_copy_assignment_operator();
  test_move_assignment_operator();
  test_empty();
  test_size();
  test_push_front();
  test_push_front_move();
  test_push_back();
  test_push_back_move();
  test_front();
  test_back();
  test_pop_front();
  test_pop_back();
  test_clear();
  test_reverse();

  return 0;
}