#include <cassert>
#include <iostream>
#include <sstream>

#include "setArr.h"

void test_setArr_constructor() {
  setArr set1;
  assert(set1.getSize() == 0);

  std::cout << "test_constructor passed" << std::endl;
}

void test_setArr_insert() {
  setArr set1;

  set1.insert(0);
  set1.insert(50);
  set1.insert(99);
  assert(set1.isInSet(0) == true);
  assert(set1.isInSet(50) == true);
  assert(set1.isInSet(99) == true);
  assert(set1.isInSet(1) == false);
  assert(set1.isInSet(98) == false);

  std::cout << "test_insert() passed" << std::endl;
}

void test_setArr_withdraw() {
  setArr set1;

  set1.insert(0);
  set1.insert(50);
  set1.insert(99);
  assert(set1.getSize() == 3);

  set1.withdraw(50);
  assert(set1.isInSet(50) == false);
  assert(set1.getSize() == 2);

  std::cout << "test_withdraw() passed" << std::endl;
}

void test_setArr_isInSet() {
  setArr set1;

  set1.insert(0);
  set1.insert(50);
  set1.insert(99);
  assert(set1.isInSet(0) == true);
  assert(set1.isInSet(50) == true);
  assert(set1.isInSet(99) == true);

  std::cout << "test_isInSet() passed" << std::endl;
}

void test_setArr_getSize() {
  setArr set1;

  assert(set1.getSize() == 0);

  set1.insert(0);
  set1.insert(50);
  set1.insert(99);
  assert(set1.getSize() == 3);

  set1.clearSet();
  assert(set1.getSize() == 0);

  std::cout << "test_getSize() passed" << std::endl;
}

void test_setArr_clearSet() {
  setArr set1;

  set1.insert(0);
  set1.insert(50);
  set1.insert(99);
  assert(set1.getSize() == 3);

  set1.clearSet();
  assert(set1.getSize() == 0);
  assert(set1.isInSet(0) == false);
  assert(set1.isInSet(50) == false);
  assert(set1.isInSet(99) == false);

  std::cout << "test_clearSet() passed" << std::endl;
}

void test_setArr_printSet() {
  setArr set1;

  set1.insert(0);
  set1.insert(50);
  set1.insert(99);

  // Redirect cout to a stringstream
  std::stringstream buffer;
  std::streambuf* orig_cout = std::cout.rdbuf(buffer.rdbuf());

  set1.printSet();
  assert(buffer.str() == "{ 0, 50, 99 }\n");

  // Restore cout
  std::cout.rdbuf(orig_cout);

  std::cout << "test_printSet() passed" << std::endl;
}

void test_setArr_setOperations() {
  setArr set1, set2;

  set1.insert(1);
  set1.insert(2);
  set1.insert(3);
  set1.insert(4);

  set2.insert(2);
  set2.insert(3);

  setArr set3 = set1 + set2;
  assert(set3.getSize() == 4);
  assert(set3.isInSet(1) == true);
  assert(set3.isInSet(2) == true);
  assert(set3.isInSet(3) == true);
  assert(set3.isInSet(4) == true);

  setArr set4 = set1 * set2;
  assert(set4.getSize() == 2);
  assert(set4.isInSet(2) == true);
  assert(set4.isInSet(3) == true);

  setArr set5 = set1 - set2;
  assert(set5.getSize() == 2);
  assert(set5.isInSet(1) == true);
  assert(set5.isInSet(4) == true);

  assert(set1 == set1);
  assert(!(set1 == set2));
  assert(set1 >= set2);
  assert(!(set1 <= set2));
  assert(set5 <= set1);
  assert(set1 >= set3);

  std::cout << "test_setOperations() passed" << std::endl;
}

void run_setArr_tests() {
  test_setArr_constructor();
  test_setArr_insert();
  test_setArr_withdraw();
  test_setArr_isInSet();
  test_setArr_getSize();
  test_setArr_clearSet();
  test_setArr_printSet();
  test_setArr_setOperations();
  std::cout << "All tests passed for setArr" << std::endl;
}
