#include "set_array/setArr.h"
#include "set_array/tests_arr.cpp"
#include "set_list/setList.h"
#include "set_list/tests_list.cpp"

int main() {
  run_setArr_tests();
  run_setList_tests();

  setArr set1;
  setList set2;

  set1.insert(0);
  set1.insert(50);
  set1.insert(99);

  set2.insert(32);
  set2.insert(22);
  set2.insert(12);

  set1.printSet();
  set2.printSet();

  return 0;
}