import sys

from graph import Graph

if __name__ == "__main__":
    graph = Graph(weighted=True, directed=False, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")
    graph.add_node("D")
    graph.add_node("E")
    graph.add_node("F")

    graph.add_edge(1, 2, 10)
    graph.add_edge(1, 3, 20)
    graph.add_edge(1, 4, 30)
    graph.add_edge(2, 5, 40)
    graph.add_edge(3, 5, 50)
    graph.add_edge(3, 6, 60)
    graph.add_edge(4, 6, 70)
    graph.add_edge(5, 6, 80)

    weight, nodes = graph.dijkstra(1, 6)

    print(f"Weight: {weight}")
    listed = list(nodes)
    print(f"Path: {' -> '.join([str(node.index()) for node in listed])}")
