#include <iostream>
#include <set>

int main() {
  std::set<int, std::greater<int>> descending_set;

  descending_set.insert(10);
  descending_set.insert(5);
  descending_set.insert(20);
  descending_set.insert(8);
  descending_set.insert(15);

  std::cout << "Numbers in descending set:" << std::endl;
  for (const auto& num : descending_set) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
