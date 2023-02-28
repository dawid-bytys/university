#include <cassert>
#include <iostream>
#include <sstream>

#include "setList.h"

void test_setList_constructor() {
  setList set1;
  assert(set1.getSize() == 0);

  std::cout << "test_constructor passed" << std::endl;
}

void test_setList_insert() {
  setList set1;

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

void test_setList_withdraw() {
  setList set1;

  set1.insert(0);
  set1.insert(50);
  set1.insert(99);
  assert(set1.getSize() == 3);

  set1.withdraw(50);
  assert(set1.isInSet(50) == false);
  assert(set1.getSize() == 2);

  std::cout << "test_withdraw() passed" << std::endl;
}

void test_setList_isInSet() {
  setList set1;

  set1.insert(0);
  set1.insert(50);
  set1.insert(99);
  assert(set1.isInSet(0) == true);
  assert(set1.isInSet(50) == true);
  assert(set1.isInSet(99) == true);

  std::cout << "test_isInSet() passed" << std::endl;
}

void test_setList_getSize() {
  setList set1;

  assert(set1.getSize() == 0);

  set1.insert(0);
  set1.insert(50);
  set1.insert(99);
  assert(set1.getSize() == 3);

  set1.clearSet();
  assert(set1.getSize() == 0);

  std::cout << "test_getSize() passed" << std::endl;
}

void test_setList_clearSet() {
  setList set1;

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

void test_setList_printSet() {
  setList set1;

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

void test_setList_setOperations() {
  setList set1, set2;

  set1.insert(1);
  set1.insert(2);
  set1.insert(3);
  set1.insert(4);

  set2.insert(2);
  set2.insert(3);

  setList set3 = set1 + set2;
  assert(set3.getSize() == 4);
  assert(set3.isInSet(1) == true);
  assert(set3.isInSet(2) == true);
  assert(set3.isInSet(3) == true);
  assert(set3.isInSet(4) == true);

  setList set4 = set1 * set2;
  assert(set4.getSize() == 2);
  assert(set4.isInSet(2) == true);
  assert(set4.isInSet(3) == true);

  setList set5 = set1 - set2;
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

void run_setList_tests() {
  test_setList_constructor();
  test_setList_insert();
  test_setList_withdraw();
  test_setList_isInSet();
  test_setList_getSize();
  test_setList_clearSet();
  test_setList_printSet();
  test_setList_setOperations();
  std::cout << "All tests passed for setList" << std::endl;
}
