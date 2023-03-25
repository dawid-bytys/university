#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "edge.h"

/**
 * Class representing a directed graph using adjacency matrix.
 */
class Graph {
 private:
  int vertices_count;
  int adjacency_matrix[100][100];
  void clear() {
    for (int i = 0; i < vertices_count; ++i) {
      for (int j = 0; j < vertices_count; ++j) {
        adjacency_matrix[i][j] = 0;
      }
    }
  }

 public:
  /**
   * Constructs a new Graph object
   */
  Graph(){};

  /**
   * Creates vertices in the graph.
   *
   * @param vertices_count Number of vertices to create.
   */
  void create_vertices(const int vertices_count) {
    this->vertices_count = vertices_count;
    clear();
  }

  /**
   * Adds an edge to the graph.
   *
   * @param src_vertex_idx Index of the source vertex.
   * @param dest_vertex_idx Index of the destination vertex.
   */
  void add_edge(const int src_vertex_idx, const int dest_vertex_idx, const float weight = 0.0f) {
    adjacency_matrix[src_vertex_idx][dest_vertex_idx] = 1;
  }

  /**
   * Removes an edge from the graph.
   *
   * @param src_vertex_idx Index of the source vertex.
   * @param dest_vertex_idx Index of the destination vertex.
   * @return true if the edge was removed, false otherwise.
   */
  const bool remove_edge(const int src_vertex_idx, const int dest_vertex_idx) {
    if (adjacency_matrix[src_vertex_idx][dest_vertex_idx] == 1) {
      adjacency_matrix[src_vertex_idx][dest_vertex_idx] = 0;
      return true;
    }
    return false;
  }

  /**
   * Checks if an edge exists in the graph.
   *
   * @param src_vertex_idx Index of the vertex node.
   * @param dest_vertex_indx Index of the vertex node.
   * @return true if the edge exists, false otherwise.
   */
  const bool check_edge(const int src_vertex_idx, const int dest_vertex_idx) const {
    return adjacency_matrix[src_vertex_idx][dest_vertex_idx] == 1;
  }

  /**
   * Gets the degree of a vertex.
   *
   * @param vertex_idx Index of the vertex.
   * @return Degree of the vertex.
   */
  const int get_vertex_degree(const int vertex_idx) const {
    int degree = 0;
    for (int i = 0; i < vertices_count; ++i) {
      if (adjacency_matrix[vertex_idx][i] == 1) {
        ++degree;
      }
    }
    return degree;
  }

  /**
   * Gets the number of vertices in the graph.
   *
   * @return Number of vertices in the graph.
   */
  const int get_vertices_count() const {
    return vertices_count;
  }

  /**
   * Gets the indices of the neighbours of a vertex.
   *
   * @param vertex_idx Index of the vertex.
   * @return Vector of indices of the neighbours.
   */
  const std::vector<int> get_neighbour_indices(const int vertex_idx) const {
    std::vector<int> neighbour_indices;
    for (int i = 0; i < vertices_count; ++i) {
      if (adjacency_matrix[vertex_idx][i] == 1) {
        neighbour_indices.push_back(i);
      }
    }
    return neighbour_indices;
  }

  /**
   * Prints the indices of the neighbours of a vertex.
   *
   * @param vertex_idx Index of the vertex.
   */
  void print_neighbour_indices(const int vertex_idx) const {
    std::vector<int> neighbour_indices = get_neighbour_indices(vertex_idx);
    for (int i = 0; i < neighbour_indices.size(); ++i) {
      std::cout << neighbour_indices[i] << " ";
    }
    std::cout << std::endl;
  }

  /**
   * Gets the number of edges in the graph.
   *
   * @return Number of edges in the graph.
   */
  const int get_edges_count() const {
    int edges_count = 0;
    for (int i = 0; i < vertices_count; ++i) {
      for (int j = 0; j < vertices_count; ++j) {
        if (adjacency_matrix[i][j] == 1) {
          ++edges_count;
        }
      }
    }
    return edges_count;
  }

  /**
   * Prints the graph.
   */
  void print() const {
    for (int i = 0; i < vertices_count; ++i) {
      for (int j = 0; j < vertices_count; ++j) {
        if (adjacency_matrix[i][j] == 1) {
          std::cout << "(" << i << ") --- " << 0.0f << " ---> (" << j << ")" << std::endl;
        }
      }
    }
  }

  /**
   * Reads a graph from a file.
   *
   * @param path Path to the file.
   */
  void read_from_file(const std::string path) {
    std::ifstream file;
    file.open(path);
    if (file.is_open()) {
      int vertices_count;
      file >> vertices_count;
      create_vertices(vertices_count);
      int src_vertex_idx;
      int dest_vertex_idx;
      while (file >> src_vertex_idx >> dest_vertex_idx) {
        add_edge(src_vertex_idx, dest_vertex_idx);
      }
      file.close();
    } else {
      std::cout << "Unable to open file" << std::endl;
    }
  }
};

#endif  // GRAPH_H