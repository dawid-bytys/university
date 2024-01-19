import heapq
from collections import defaultdict
from typing import Any, Iterator, Literal, Self

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

    def _is_acyclic_helper(
        self: Self, node: Node, visited: set[Node], stack: set[Node]
    ) -> bool:
        visited.add(node)
        stack.add(node)

        for adj_node in self.adjacent_nodes(node.index):
            if adj_node not in visited:
                if self._is_acyclic_helper(adj_node, visited, stack):
                    return True
            elif adj_node in stack:
                return True

        stack.remove(node)
        return False

    @property
    def nodes(self: Self) -> Iterator[Node]:
        return iter(self._nodes.values())

    @property
    def edges(self: Self) -> Iterator[Edge]:
        return iter(self._edges)

    @property
    def is_directed(self: Self) -> bool:
        return self._directed

    @property
    def is_weighted(self: Self) -> bool:
        return self._weighted

    def add_node(self: Self, value: Any = None) -> None:
        idx = len(self._nodes) + self._first_idx
        self._nodes[idx] = Node(idx, value)

    def add_edge(
        self: Self, start_node_idx: int, end_node_idx: int, weight: float = 1.0
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
            if edge.start_node == node or edge.end_node == node:
                self._edges.remove(edge)

    def remove_edge(self: Self, start_node_idx: int, end_node_idx: int) -> None:
        start_node = self._nodes.get(start_node_idx)
        end_node = self._nodes.get(end_node_idx)

        if start_node is None or end_node is None:
            raise KeyError("Invalid node index.")

        for edge in self._edges.copy():
            if edge.start_node == start_node and edge.end_node == end_node:
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
            if edge.start_node == start_node and edge.end_node == end_node:
                return edge

        raise KeyError("Invalid edge index.")

    def adjacent_nodes(self: Self, idx: int) -> Iterator[Node]:
        node = self._nodes.get(idx)

        if node is None:
            raise KeyError("Invalid node index.")

        for edge in self._edges:
            if edge.start_node == node:
                yield edge.end_node

    def edge_weight(self: Self, start_node_idx: int, end_node_idx: int) -> float:
        edge = self.get_edge(start_node_idx, end_node_idx)

        if not self._weighted:
            raise ValueError("Graph is not weighted.")

        return edge.weight

    def is_acyclic(self: Self) -> bool:
        if not self._directed:
            raise ValueError("Graph is not directed.")

        visited: set[Node] = set()
        stack: set[Node] = set()

        for node in self.nodes:
            if node not in visited:
                if self._is_acyclic_helper(node, visited, stack):
                    return False

        return True

    def bfs(self: Self, start_node_idx: int) -> Iterator[Node]:
        start_node = self.get_node(start_node_idx)

        if not start_node:
            raise KeyError("Invalid node index.")

        visited: set[Node] = set()
        queue: list[Node] = [start_node]

        while queue:
            node = queue.pop(0)

            if node not in visited:
                yield node
                visited.add(node)

                for adj_node in self.adjacent_nodes(node.index):
                    queue.append(adj_node)

    def dfs(self: Self, start_node_idx: int) -> Iterator[Node]:
        start_node = self.get_node(start_node_idx)

        if not start_node:
            raise KeyError("Invalid node index.")

        visited: set[Node] = set()
        stack: list[Node] = [start_node]

        while stack:
            node = stack.pop()

            if node not in visited:
                yield node
                visited.add(node)

                for adj_node in self.adjacent_nodes(node.index):
                    stack.append(adj_node)

    def dijkstra(
        self: Self, start_node_idx: int, end_node_idx: int
    ) -> tuple[float, Iterator[Node]]:
        if not self._weighted:
            raise ValueError("Graph is not weighted.")

        start_node = self.get_node(start_node_idx)
        end_node = self.get_node(end_node_idx)

        if not start_node or not end_node:
            raise KeyError("Invalid node index.")

        weights: dict[Node, float] = defaultdict(lambda: float("inf"))
        previous_nodes: dict[Node, Node | None] = defaultdict(lambda: None)
        weights[start_node] = 0
        priority_queue: list[tuple[float, Node]] = [(0, start_node)]

        while priority_queue:
            _, node = heapq.heappop(priority_queue)

            for adj_node in self.adjacent_nodes(node.index):
                new_weight = weights[node] + self.edge_weight(
                    node.index, adj_node.index
                )

                if new_weight < weights[adj_node]:
                    weights[adj_node] = new_weight
                    previous_nodes[adj_node] = node
                    heapq.heappush(priority_queue, (new_weight, adj_node))

        path = [end_node]
        current_node = end_node

        while (temp := previous_nodes[current_node]) is not None:
            current_node = temp
            path.append(current_node)

        path.reverse()
        return weights[end_node], iter(path)

    def read_from_file(self: Self, file_path: str) -> None:
        with open(file_path, "r") as file:
            try:
                for index, line in enumerate(file):
                    if index == 0:
                        for _ in range(int(line)):
                            self.add_node()
                    else:
                        if self._weighted:
                            start_node_idx, end_node_idx, weight = line.split(" ")
                            self.add_edge(
                                int(start_node_idx),
                                int(end_node_idx),
                                float(weight),
                            )
                        else:
                            start_node_idx, end_node_idx = line.split(" ")
                            self.add_edge(int(start_node_idx), int(end_node_idx))
            except ValueError:
                raise ValueError("Invalid file format.")

    def __str__(self: Self) -> str:
        return_str = ""
        for index, edge in enumerate(self._edges):
            if index == len(self._edges) - 1:
                return_str += str(edge)
            else:
                return_str += str(edge) + "\n"
        return return_str
