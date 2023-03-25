#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "edge.h"

/**
 * Class representing a directed graph using adjacency list.
 */
class Graph {
 private:
  std::vector<std::vector<Edge> > adjacency_list;

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
    adjacency_list.resize(vertices_count);
  }

  /**
   * Adds an edge to the graph.
   *
   * @param src_vertex_idx Index of the source vertex.
   * @param dest_vertex_idx Index of the destination vertex.
   */
  void add_edge(const int src_vertex_idx, const int dest_vertex_idx, const float weight = 0.0f) {
    adjacency_list[src_vertex_idx].push_back(Edge(src_vertex_idx, dest_vertex_idx, weight));
  }

  /**
   * Removes an edge from the graph.
   *
   * @param src_vertex_idx Index of the source vertex.
   * @param dest_vertex_idx Index of the destination vertex.
   * @return true if the edge was removed, false otherwise.
   */
  const bool remove_edge(const int src_vertex_idx, const int dest_vertex_idx) {
    for (int i = 0; i < adjacency_list[src_vertex_idx].size(); ++i) {
      if (adjacency_list[src_vertex_idx][i].get_dest_vertex_idx() == dest_vertex_idx) {
        adjacency_list[src_vertex_idx].erase(adjacency_list[src_vertex_idx].begin() + i);
        return true;
      }
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
    for (int i = 0; i < adjacency_list[src_vertex_idx].size(); ++i) {
      if (adjacency_list[src_vertex_idx][i].get_dest_vertex_idx() == dest_vertex_idx) {
        return true;
      }
    }
    return false;
  }

  /**
   * Gets the degree of a vertex.
   *
   * @param vertex_idx Index of the vertex.
   * @return Degree of the vertex.
   */
  const int get_vertex_degree(const int vertex_idx) const {
    return adjacency_list[vertex_idx].size();
  }

  /**
   * Gets the number of vertices in the graph.
   *
   * @return Number of vertices in the graph.
   */
  const int get_vertices_count() const {
    return adjacency_list.size();
  }

  /**
   * Gets the indices of the neighbours of a vertex.
   *
   * @param vertex_idx Index of the vertex.
   * @return Vector of indices of the neighbours.
   */
  const std::vector<int> get_neighbour_indices(const int vertex_idx) const {
    std::vector<int> neighbour_indices;
    for (int i = 0; i < adjacency_list[vertex_idx].size(); ++i) {
      neighbour_indices.push_back(adjacency_list[vertex_idx][i].get_dest_vertex_idx());
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
    for (int i = 0; i < adjacency_list.size(); ++i) {
      edges_count += adjacency_list[i].size();
    }
    return edges_count;
  }

  /**
   * Prints the graph.
   */
  void print() const {
    for (int i = 0; i < adjacency_list.size(); ++i) {
      for (int j = 0; j < adjacency_list[i].size(); ++j) {
        std::cout << "(" << adjacency_list[i][j].get_src_vertex_idx() << ") --- "
                  << adjacency_list[i][j].get_weight() << " ---> ("
                  << adjacency_list[i][j].get_dest_vertex_idx() << ")" << std::endl;
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