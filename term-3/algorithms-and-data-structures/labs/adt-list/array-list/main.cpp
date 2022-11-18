#include <iostream>
#include <string>

#include "arraylist.hpp"
#include "cassert"

int main() {
  ArrayList<int> list(10);

  // create an array list of integers
  std::cout << "(1) push_back()" << std::endl;
  assert(list.empty());
  for (int i = 0; i < 10; ++i) {
    list.push_back(i);
  }
  assert(list.size() == 10);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // check if the list is empty
  std::cout << "(2) empty()" << std::endl;
  assert(!list.empty());
  std::cout << "    "
            << "Integer list is not empty" << std::endl;

  // check if the list is full
  std::cout << "(3) full()" << std::endl;
  assert(list.full());
  std::cout << "    "
            << "Integer list is full" << std::endl;

  // check the size of the list
  std::cout << "(4) size()" << std::endl;
  assert(list.size() == 10);
  std::cout << "    "
            << "Integer list size is 10" << std::endl;

  // get the maximum size of the list
  std::cout << "(5) max_size()" << std::endl;
  assert(list.max_size() == 10);
  std::cout << "    "
            << "Integer list max size is 10" << std::endl;

  // get the first element of the list
  std::cout << "(6) front()" << std::endl;
  assert(list.front() == 0);
  std::cout << "    "
            << "Integer list front is 0" << std::endl;

  // get the last element of the list
  std::cout << "(7) back()" << std::endl;
  assert(list.back() == 9);
  std::cout << "    "
            << "Integer list back is 9" << std::endl;

  // remove the first element of the list
  std::cout << "(8) pop_front()" << std::endl;
  list.pop_front();
  assert(list.front() == 1);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // add an element to the beginning of the list
  std::cout << "(9) push_front()" << std::endl;
  list.push_front(0);
  assert(list.front() == 0);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // remove the last element of the list
  std::cout << "(10) pop_back()" << std::endl;
  list.pop_back();
  assert(list.back() == 8);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // add an element to the end of the list
  std::cout << "(11) push_back()" << std::endl;
  list.push_back(9);
  assert(list.back() == 9);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // reverse the list
  std::cout << "(12) reverse()" << std::endl;
  list.reverse();
  assert(list.front() == 9);
  assert(list.back() == 0);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // sort the list
  std::cout << "(13) sort()" << std::endl;
  list.sort();
  assert(list.front() == 0);
  assert(list.back() == 9);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // remove all elements from the list
  std::cout << "(14) clear()" << std::endl;
  list.clear();
  assert(list.empty());
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // push 10 elements to the list
  std::cout << "(15) push_back()" << std::endl;
  for (int i = 0; i < 10; ++i) {
    list.push_back(i);
  }
  assert(list.size() == 10);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // create another list of integers starting from 10
  std::cout << "(16) push_back()" << std::endl;
  ArrayList<int> list2(10);
  for (int i = 10; i < 20; ++i) {
    list2.push_back(i);
  }
  assert(list2.size() == 10);
  std::cout << "    "
            << "Integer list2: " << list2 << std::endl;

  // change the size of the list
  std::cout << "(17) resize()" << std::endl;
  list.resize(20);
  assert(list.max_size() == 20);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // merge the two lists
  std::cout << "(18) merge()" << std::endl;
  list.merge(list2);
  assert(list.size() == 20);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  // insert an element at a specific position
  std::cout << "(19) insert()" << std::endl;
  list.resize(21);
  list.insert(5, 100);
  assert(list[5] == 100);
  std::cout << "    "
            << "Integer list: " << list << std::endl;

  return 0;
}