import numpy as np
from collections import defaultdict


def read_graph_from_file(filename):
    graph = defaultdict(list)

    with open(filename, "r") as file:
        for line in file.readlines():
            vertex1, vertex2 = map(int, line.split())
            graph[vertex1].append(vertex2)
            graph[vertex2].append(vertex1)

    return graph


def greedy_max_cut(graph):
    visited = set()
    groups = defaultdict(int)

    for vertex in graph:
        if vertex not in visited:
            group0, group1 = 0, 0
            for neighbor in graph[vertex]:
                if groups[neighbor] == 0:
                    group0 += 1
                else:
                    group1 += 1
            groups[vertex] = 0 if group0 > group1 else 1
            visited.add(vertex)

    cut_edges = 0

    for vertex, group in groups.items():
        for neighbor in graph[vertex]:
            if groups[neighbor] != group:
                cut_edges += 1

    cut_edges //= 2

    return cut_edges, groups


def max_cut_from_file(filename):
    graph = read_graph_from_file(filename)
    cut_edges, groups = greedy_max_cut(graph)
    print(f"Max cut edges: {cut_edges}")
    print("Group 0: ", [v for v, g in groups.items() if g == 0])
    print("Group 1: ", [v for v, g in groups.items() if g == 1])


if __name__ == "__main__":
    max_cut_from_file("graph.txt")
