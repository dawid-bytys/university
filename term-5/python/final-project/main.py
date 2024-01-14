import sys

from graph import Graph

if __name__ == "__main__":
    graph = Graph(weighted=True, directed=True, first_idx=0)
    graph.read_from_file("graph.txt")

    dist = graph.floyd_warshall()
    print(dist)
