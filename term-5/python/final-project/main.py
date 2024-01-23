import sys

from graph import Graph

if __name__ == "__main__":
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")
    graph.add_node("D")
    graph.add_node("E")

    graph.add_edge(1, 2, 11)
    graph.add_edge(2, 4, 5)
    graph.add_edge(2, 5, 5)
    graph.add_edge(4, 3, 11)
    graph.add_edge(5, 3, 5)

    weight, path = graph.dijkstra(1, 3)

    dfs = graph.dfs(1)
    dfs_path = graph.dfs(1)
    print(f"DFS Path: {[node.value for node in dfs_path]}")
