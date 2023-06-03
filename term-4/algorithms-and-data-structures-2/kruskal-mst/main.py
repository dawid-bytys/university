import sys
from typing import List, Tuple

from typing_extensions import Self


class Graph:
    def __init__(self: Self, vertices_count: int) -> None:
        self._vertices_count = vertices_count
        self._edges = []

    def add_edge(self: Self, start_vertex: int, end_vertex: int, weight: int) -> None:
        self._edges.append([start_vertex, end_vertex, weight])

    def find_parent(self: Self, parent: List[int], vertex: int) -> int:
        if parent[vertex] == vertex:
            return vertex
        return self.find_parent(parent, parent[vertex])

    def union(
        self: Self,
        parent: List[int],
        rank: List[int],
        start_vertex: int,
        end_vertex: int,
    ) -> None:
        root1 = self.find_parent(parent, start_vertex)
        root2 = self.find_parent(parent, end_vertex)

        if rank[root1] < rank[root2]:
            parent[root1] = root2
        elif rank[root1] > rank[root2]:
            parent[root2] = root1
        else:
            parent[root2] = root1
            rank[root1] += 1

    def kruskal_mst(self: Self) -> List[Tuple[int, int, int]]:
        mst_result = []
        index_edge = 0
        num_edges = 0

        self._edges = sorted(self._edges, key=lambda item: item[2])
        parent = [node for node in range(self._vertices_count)]
        rank = [0] * self._vertices_count

        while num_edges < self._vertices_count - 1:
            start_vertex, end_vertex, weight = self._edges[index_edge]
            index_edge += 1
            root_start_vertex = self.find_parent(parent, start_vertex)
            root_end_vertex = self.find_parent(parent, end_vertex)

            if root_start_vertex != root_end_vertex:
                num_edges += 1
                mst_result.append((start_vertex, end_vertex, weight))
                self.union(parent, rank, root_start_vertex, root_end_vertex)

        return mst_result


def read_graph_from_file(file_name: str) -> Graph:
    with open(file_name, "r") as f:
        lines = f.readlines()
        max_vertex = (
            max([max(int(line.split()[0]), int(line.split()[1])) for line in lines]) + 1
        )
        graph = Graph(max_vertex)

        for line in lines:
            start_vertex, end_vertex, weight = map(int, line.split())
            graph.add_edge(start_vertex, end_vertex, weight)

        return graph


if __name__ == "__main__":
    graph = read_graph_from_file("graph.txt")
    mst = graph.kruskal_mst()

    print("Edges in the constructed MST:")

    total_weight = 0
    for start_vertex, end_vertex, weight in mst:
        print(f"({start_vertex}) -- {weight} -- ({end_vertex})")
        total_weight += weight

    print("\nSum of weights in the MST: ", total_weight)

    sys.exit(0)
