from collections import defaultdict
from typing import Any, Iterator, Literal

from typing_extensions import Self

from .edge import Edge
from .node import Node


class Graph:
    def __init__(
        self: Self,
        directed: bool = True,
        weighted: bool = True,
        first_idx: Literal[0, 1] = 0,
    ) -> None:
        self._directed = directed
        self._weighted = weighted
        self._first_idx = first_idx
        self._nodes: dict[int, Node] = defaultdict()
        self._edges: set[Edge] = set()

    def nodes(self: Self) -> Iterator[Node]:
        return iter(self._nodes.values())

    def edges(self: Self) -> Iterator[Edge]:
        return iter(self._edges)

    def is_directed(self: Self) -> bool:
        return self._directed

    def is_weighted(self: Self) -> bool:
        return self._weighted

    def add_node(self: Self, value: Any = None) -> None:
        idx = len(self._nodes) + self._first_idx
        self._nodes[idx] = Node(idx, value)

    def add_edge(
        self: Self, start_node_idx: int, end_node_idx: int, weight: int = 1
    ) -> None:
        start_node = self._nodes.get(start_node_idx)
        end_node = self._nodes.get(end_node_idx)

        if start_node is None or end_node is None:
            raise KeyError("Invalid node index.")

        edge = Edge(start_node, end_node, self._directed, self._weighted, weight)
        self._edges.add(edge)

        if not self._directed:
            edge = Edge(end_node, start_node, self._directed, self._weighted, weight)
            self._edges.add(edge)

    def remove_node(self: Self, idx: int) -> None:
        node = self._nodes.pop(idx, None)

        if node is None:
            raise KeyError("Invalid node index.")

        for edge in self._edges.copy():
            if edge.start_node() == node or edge.end_node() == node:
                self._edges.remove(edge)

    def remove_edge(self: Self, start_node_idx: int, end_node_idx: int) -> None:
        start_node = self._nodes.get(start_node_idx)
        end_node = self._nodes.get(end_node_idx)

        if start_node is None or end_node is None:
            raise KeyError("Invalid node index.")

        for edge in self._edges.copy():
            if edge.start_node() == start_node and edge.end_node() == end_node:
                self._edges.remove(edge)

    def get_node(self: Self, idx: int) -> Node:
        node = self._nodes.get(idx)

        if node is None:
            raise KeyError("Invalid node index.")

        return node

    def get_edge(self: Self, start_node_idx: int, end_node_idx: int) -> Edge:
        start_node = self._nodes.get(start_node_idx)
        end_node = self._nodes.get(end_node_idx)

        if start_node is None or end_node is None:
            raise KeyError("Invalid node index.")

        for edge in self._edges:
            if edge.start_node() == start_node and edge.end_node() == end_node:
                return edge

        raise KeyError("Invalid edge index.")

    def adjacent_nodes(self: Self, idx: int) -> Iterator[Node]:
        node = self._nodes.get(idx)

        if node is None:
            raise KeyError("Invalid node index.")

        for edge in self._edges:
            if edge.start_node() == node:
                yield edge.end_node()
