import pytest

from graph import Graph


def test_graph_initialization() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    assert graph.is_directed is True
    assert graph.is_weighted is True

    assert list(graph.nodes) == []
    assert list(graph.edges) == []


def test_graph_add_node() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    assert len(list(graph.nodes)) == 3
    assert len(list(graph.edges)) == 0


def test_graph_add_edge() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    graph.add_edge(1, 2, 10)
    graph.add_edge(2, 3, 20)
    graph.add_edge(3, 1, 30)

    assert len(list(graph.nodes)) == 3
    assert len(list(graph.edges)) == 3


def test_graph_remove_node() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    graph.add_edge(1, 2, 10)
    graph.add_edge(2, 3, 20)
    graph.add_edge(3, 1, 30)

    graph.remove_node(1)

    assert len(list(graph.nodes)) == 2
    assert len(list(graph.edges)) == 1


def test_graph_remove_node_with_invalid_index() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    graph.add_edge(1, 2, 10)
    graph.add_edge(2, 3, 20)
    graph.add_edge(3, 1, 30)

    with pytest.raises(KeyError):
        graph.remove_node(4)


def test_graph_remove_edge() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    graph.add_edge(1, 2, 10)
    graph.add_edge(2, 3, 20)
    graph.add_edge(3, 1, 30)

    graph.remove_edge(1, 2)

    assert len(list(graph.nodes)) == 3
    assert len(list(graph.edges)) == 2


def test_graph_remove_edge_with_invalid_index() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    graph.add_edge(1, 2, 10)
    graph.add_edge(2, 3, 20)
    graph.add_edge(3, 1, 30)

    with pytest.raises(KeyError):
        graph.remove_edge(1, 4)


def test_graph_get_node() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    assert graph.get_node(1).index == 1
    assert graph.get_node(1).value == "A"

    assert graph.get_node(2).index == 2
    assert graph.get_node(2).value == "B"

    assert graph.get_node(3).index == 3
    assert graph.get_node(3).value == "C"


def test_graph_get_node_with_invalid_index() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    with pytest.raises(KeyError):
        graph.get_node(4)


def test_graph_get_edge() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    graph.add_edge(1, 2, 10)
    graph.add_edge(2, 3, 20)
    graph.add_edge(3, 1, 30)

    assert graph.get_edge(1, 2).weight == 10
    assert graph.get_edge(2, 3).weight == 20
    assert graph.get_edge(3, 1).weight == 30


def test_graph_get_edge_with_invalid_index() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")

    graph.add_edge(1, 2, 10)
    graph.add_edge(2, 3, 20)
    graph.add_edge(3, 1, 30)

    with pytest.raises(KeyError):
        graph.get_edge(1, 4)


def test_graph_adjacent_nodes() -> None:
    graph = Graph(weighted=True, directed=False, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")
    graph.add_node("D")

    graph.add_edge(1, 2, 10)
    graph.add_edge(1, 3, 20)
    graph.add_edge(1, 4, 30)

    assert len(list(graph.adjacent_nodes(1))) == 3
    assert len(list(graph.adjacent_nodes(2))) == 1
    assert len(list(graph.adjacent_nodes(3))) == 1
    assert len(list(graph.adjacent_nodes(4))) == 1


def test_graph_adjacent_nodes_with_invalid_index() -> None:
    graph = Graph(weighted=True, directed=False, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")
    graph.add_node("D")

    with pytest.raises(KeyError):
        list(graph.adjacent_nodes(5))


def test_graph_edge_weight() -> None:
    graph = Graph(weighted=True, directed=False, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")
    graph.add_node("D")

    graph.add_edge(1, 2, 10)
    graph.add_edge(1, 3, 20)
    graph.add_edge(1, 4, 30)

    assert graph.edge_weight(1, 2) == 10
    assert graph.edge_weight(1, 3) == 20
    assert graph.edge_weight(1, 4) == 30


def test_graph_edge_weight_with_invalid_index() -> None:
    graph = Graph(weighted=True, directed=False, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")
    graph.add_node("D")

    with pytest.raises(KeyError):
        graph.edge_weight(1, 5)


def test_graph_bfs() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")
    graph.add_node("D")
    graph.add_node("E")

    graph.add_edge(1, 2, 10)
    graph.add_edge(2, 3, 20)
    graph.add_edge(3, 1, 30)
    graph.add_edge(4, 5, 40)

    assert len(list(graph.bfs(1))) == 3
    assert len(list(graph.bfs(4))) == 2


def test_graph_dfs() -> None:
    graph = Graph(weighted=True, directed=True, first_idx=1)

    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")
    graph.add_node("D")
    graph.add_node("E")
    graph.add_node("F")

    graph.add_edge(1, 2)
    graph.add_edge(2, 3)
    graph.add_edge(3, 6)
    graph.add_edge(1, 4)
    graph.add_edge(4, 5)

    assert len(list(graph.dfs(1))) == 6
    assert len(list(graph.dfs(2))) == 3


def test_graph_dijkstra() -> None:
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
    list_nodes = list(nodes)

    assert weight == 80
    assert len(list_nodes) == 3
    assert list_nodes[0].index == 1
    assert list_nodes[1].index == 3
    assert list_nodes[2].index == 6
