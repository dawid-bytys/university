#include "../include/graph.h"
#include "cassert"
#include "iostream"

void test_create_vertices() {
  Graph graph;
  graph.create_vertices(5);
  assert(graph.get_vertices_count() == 5);

  std::cout << "test_create_vertices passed" << std::endl;
}

void test_add_edge() {
  Graph graph;
  graph.create_vertices(5);
  graph.add_edge(0, 1);
  assert(graph.get_vertex_degree(0) == 1);
  assert(graph.get_vertex_degree(1) == 0);

  std::cout << "test_add_edge passed" << std::endl;
}

void test_remove_edge() {
  Graph graph;
  graph.create_vertices(5);
  graph.add_edge(0, 1);
  graph.add_edge(1, 2);
  graph.add_edge(2, 3);
  assert(graph.remove_edge(0, 1));
  assert(graph.get_vertex_degree(0) == 0);
  assert(graph.get_vertex_degree(1) == 1);

  std::cout << "test_remove_edge passed" << std::endl;
}

void test_check_edge() {
  Graph graph;
  graph.create_vertices(5);
  graph.add_edge(0, 1);
  graph.add_edge(1, 2);
  graph.add_edge(2, 3);
  assert(graph.check_edge(0, 1));
  assert(graph.check_edge(1, 2));
  assert(graph.check_edge(2, 3));
  assert(!graph.check_edge(0, 2));
  assert(!graph.check_edge(0, 3));
  assert(!graph.check_edge(1, 3));

  std::cout << "test_check_edge passed" << std::endl;
}

void test_get_vertex_degree() {
  Graph graph;
  graph.create_vertices(5);
  graph.add_edge(0, 1);
  graph.add_edge(1, 2);
  graph.add_edge(2, 3);
  assert(graph.get_vertex_degree(0) == 1);
  assert(graph.get_vertex_degree(1) == 1);
  assert(graph.get_vertex_degree(2) == 1);
  assert(graph.get_vertex_degree(3) == 0);

  std::cout << "test_get_vertex_degree passed" << std::endl;
}

void test_get_vertices_count() {
  Graph graph;
  graph.create_vertices(5);
  assert(graph.get_vertices_count() == 5);

  std::cout << "test_get_vertices_count passed" << std::endl;
}

void test_get_neighbour_indices() {
  Graph graph;
  graph.create_vertices(5);
  graph.add_edge(0, 1);
  graph.add_edge(1, 2);
  graph.add_edge(2, 3);
  assert(graph.get_neighbour_indices(0).size() == 1);
  assert(graph.get_neighbour_indices(1).size() == 1);
  assert(graph.get_neighbour_indices(2).size() == 1);
  assert(graph.get_neighbour_indices(3).size() == 0);

  std::cout << "test_get_neighbour_indices passed" << std::endl;
}

void test_edges_count() {
  Graph graph;
  graph.create_vertices(5);
  graph.add_edge(0, 1);
  graph.add_edge(1, 2);
  graph.add_edge(2, 3);
  assert(graph.get_edges_count() == 3);

  std::cout << "test_edges_count passed" << std::endl;
}

void test_read_from_file() {
  Graph graph;
  graph.read_from_file("graph.txt");
  assert(graph.get_vertices_count() == 100);

  std::cout << "test_read_graph_from_file passed" << std::endl;
}

void run_all_tests() {
  test_create_vertices();
  test_add_edge();
  test_remove_edge();
  test_check_edge();
  test_get_vertex_degree();
  test_get_vertices_count();
  test_get_neighbour_indices();
  test_edges_count();
  test_read_from_file();

  std::cout << "All tests passed" << std::endl;
}