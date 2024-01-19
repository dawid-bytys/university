import sys

from graph import Graph

if __name__ == "__main__":
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    graph.add_edge(1, 2, 10)
    graph.add_edge(2, 3, 20)
    graph.add_edge(3, 1, 30)

    graph.remove_node(1)

    print(len(list(graph.nodes)))
    print(len(list(graph.edges)))
