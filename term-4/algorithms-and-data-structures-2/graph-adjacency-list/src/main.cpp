#include "../include/graph.h"
#include "tests.cpp"

int main() {
  run_all_tests();

  Graph graph;
  graph.read_from_file("graph.txt");
  graph.print();

  return 0;
}