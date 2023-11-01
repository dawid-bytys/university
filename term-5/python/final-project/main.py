import sys

from graph import Graph

if __name__ == "__main__":
    graph = Graph(weighted=True, directed=False, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")
    graph.add_node("D")

    nodes = graph.adjacent_nodes(5)

    sys.exit(0)
