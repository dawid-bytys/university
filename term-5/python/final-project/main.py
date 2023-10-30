import sys

from graph import Graph

if __name__ == "__main__":
    graph = Graph(directed=False, weighted=False)

    graph.add_node(0)
    graph.add_node(1)

    graph.add_edge(0, 1)

    print([node for node in graph.nodes])
    print([edge for edge in graph.edges])

    graph.remove_node(0)

    print([node for node in graph.nodes])
    print([edge for edge in graph.edges])

    sys.exit(0)
