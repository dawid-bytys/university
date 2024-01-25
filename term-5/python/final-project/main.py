import sys

from graph import Graph

if __name__ == "__main__":
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node(1)
    graph.add_node(2)
    graph.add_node(3)
    graph.add_node(4)
    graph.add_node(5)

    graph.add_edge(1, 2, 11)
    graph.add_edge(2, 4, 5)
    graph.add_edge(2, 5, 5)
    graph.add_edge(4, 3, 11)
    graph.add_edge(5, 3, 5)

    weight, path = graph.dijkstra(1, 3)

    print(f"Weight: {weight}")

    print("Path: ", end="")
    for node in path:
        print(node.value, end=" ")

    sys.exit(0)
