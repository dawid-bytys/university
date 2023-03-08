#include <cassert>
#include <iostream>

#include "Poly.hpp"

void test_default_constructor() {
  Poly<int> poly;
  assert(poly.get_degree() == 0);
  assert(poly[0] == 0);
  assert(poly.is_zero());
  std::cout << "test_default_constructor passed" << std::endl;
}

void test_copy_constructor() {
  int coeffs[3] = {1, 2, 3};
  Poly<int> poly(coeffs, 2);
  assert(poly.get_degree() == 2);
  assert(poly[2] = 3);
  assert(poly[1] = 2);
  assert(poly[0] = 1);
  assert(!poly.is_zero());
  std::cout << "test_copy_constructor passed" << std::endl;
}

void test_copy_constructor_from_poly() {
  int coeffs[3] = {1, 2, 3};
  Poly<int> poly(coeffs, 2);
  Poly<int> poly2(poly);
  assert(poly2.get_degree() == 2);
  assert(poly2[2] == 1);
  assert(poly2[1] == 2);
  assert(poly2[0] == 3);
  assert(!poly2.is_zero());
  std::cout << "test_copy_constructor_from_poly passed" << std::endl;
}

void test_get_degree() {
  int coeffs[3] = {1, 2, 3};
  Poly<int> poly(coeffs, 2);
  assert(poly.get_degree() == 2);
  std::cout << "test_get_degree passed" << std::endl;
}

void test_evaluate() {
  int coeffs[3] = {1, 2, 3};
  Poly<int> poly(coeffs, 2);
  assert(poly.evaluate(1) == 6);
  assert(poly.evaluate(2) == 11);
  assert(poly.evaluate(3) == 18);
  std::cout << "test_evaluate passed" << std::endl;
}

void test_addition() {
  int coeffs[3] = {1, 2, 3};
  Poly<int> poly(coeffs, 2);
  Poly<int> poly2(coeffs, 2);
  Poly<int> poly3 = poly + poly2;
  assert(poly3.get_degree() == 2);
  assert(poly3[2] == 2);
  assert(poly3[1] == 4);
  assert(poly3[0] == 6);
  assert(!poly3.is_zero());
  std::cout << "text_addition passed" << std::endl;
}

void test_subtraction() {
  int coeffs[3] = {1, 2, 3};
  Poly<int> poly(coeffs, 2);
  Poly<int> poly2(coeffs, 2);
  Poly<int> poly3 = poly - poly2;
  assert(poly3.get_degree() == 2);
  assert(poly3[2] == 0);
  assert(poly3[1] == 0);
  assert(poly3[0] == 0);
  assert(poly3.is_zero());
  std::cout << "text_subtraction passed" << std::endl;
}

void test_multiplication() {
  int coeffs[3] = {1, 2, 3};
  Poly<int> poly(coeffs, 2);
  Poly<int> poly2(coeffs, 2);
  Poly<int> poly3 = poly * poly2;
  assert(poly3.get_degree() == 4);
  assert(poly3[4] == 1);
  assert(poly3[3] == 4);
  assert(poly3[2] == 10);
  assert(poly3[1] == 12);
  assert(poly3[0] == 9);
  assert(!poly3.is_zero());
  std::cout << "text_multiplication passed" << std::endl;
}

void test_equal() {
  int coeffs[3] = {1, 2, 3};
  Poly<int> poly(coeffs, 2);
  Poly<int> poly2(coeffs, 2);
  assert(poly == poly2);
  std::cout << "text_equal passed" << std::endl;
}

void test_not_equal() {
  int coeffs[3] = {1, 2, 3};
  int coeffs2[3] = {1, 2, 4};
  Poly<int> poly(coeffs, 2);
  Poly<int> poly2(coeffs2, 2);
  assert(poly != poly2);
  std::cout << "text_not_equal passed" << std::endl;
}

void test_array_index_operator() {
  int coeffs[3] = {1, 2, 3};
  Poly<int> poly(coeffs, 2);
  assert(poly[0] == 3);
  assert(poly[1] == 2);
  assert(poly[2] == 1);
  std::cout << "text_array_index_operator passed" << std::endl;
}

void test_print() {
  int coeffs[3] = {1, 2, -3};
  Poly<int> poly(coeffs, 2);
  poly.print();
  std::cout << "text_print passed" << std::endl;
}

void run_all_tests() {
  test_default_constructor();
  test_copy_constructor();
  test_copy_constructor_from_poly();
  test_get_degree();
  test_evaluate();
  test_addition();
  test_subtraction();
  test_multiplication();
  test_equal();
  test_not_equal();
  test_array_index_operator();
  test_print();
}