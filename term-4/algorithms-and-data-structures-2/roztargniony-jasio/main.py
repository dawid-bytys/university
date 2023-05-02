from collections import defaultdict

from typing_extensions import Self


class Graph:
    def __init__(self: Self) -> None:
        self._vertices_count = 0
        self._adjacency_list = defaultdict(set)

    def get_connected_vertices(self: Self) -> tuple[set, int]:
        visited = [False] * (self._vertices_count + 1)
        connected_vertices = set()
        for vertex in self._adjacency_list:
            if not visited[vertex]:
                connected_vertices.add(vertex)
                self._dfs(vertex, visited)
        return connected_vertices, len(connected_vertices)

    def add_edge(self: Self, start_vertex: int, end_vertex: int) -> None:
        self._adjacency_list[start_vertex].add(end_vertex)
        self._adjacency_list[end_vertex].add(start_vertex)

    def read_from_file(self: Self, filepath: str) -> None:
        try:
            with open(filepath, "r") as file:
                self._vertices_count = int(file.readline())
                for idx, line in enumerate(file, start=1):
                    vertex = int(line)
                    self.add_edge(vertex, idx)
        except FileNotFoundError:
            print("File not found!")

    def _dfs(self: Self, vertex: int, visited: list) -> None:
        visited[vertex] = True
        for neighbour in self._adjacency_list[vertex]:
            if not visited[neighbour]:
                self._dfs(neighbour, visited)


if __name__ == "__main__":
    graph = Graph()
    graph.read_from_file("input.txt")
    connected_vertices, connected_vertices_count = graph.get_connected_vertices()
    print(f"Minimalna liczba skarbonek do zbicia: {connected_vertices_count}")
    print(f"Numery skarbonek do zbicia: {connected_vertices}")
