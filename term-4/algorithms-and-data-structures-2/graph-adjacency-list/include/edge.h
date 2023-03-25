#pragma once
#ifndef EDGE_H
#define EDGE_H

struct Edge {
 private:
  int src_vertex_idx;
  int dest_vertex_idx;
  float weight;

 public:
  Edge(const int src_vertex_idx, const int dest_vertex_idx, const float weight = 0.0f) {
    this->src_vertex_idx = src_vertex_idx;
    this->dest_vertex_idx = dest_vertex_idx;
    this->weight = weight;
  }

  const int get_src_vertex_idx() const {
    return src_vertex_idx;
  }

  const int get_dest_vertex_idx() const {
    return dest_vertex_idx;
  }

  const float get_weight() const {
    return weight;
  }
};

#endif  // EDGE_H