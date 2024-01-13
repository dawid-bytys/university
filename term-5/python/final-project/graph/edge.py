from typing import Self, TypeVar

from .node import Node


class Edge:
    def __init__(
        self: Self,
        start_node: Node,
        end_node: Node,
        directed: bool,
        weighted: bool,
        weight: float = 1.0,
    ) -> None:
        self._start_node = start_node
        self._end_node = end_node
        self._directed = directed
        self._weighted = weighted
        self._weight = weight

    @property
    def start_node(self: Self) -> Node:
        return self._start_node

    @property
    def end_node(self: Self) -> Node:
        return self._end_node

    @property
    def weight(self: Self) -> float:
        return self._weight

    def __str__(self: Self) -> str:
        if self._directed:
            if self._weighted:
                return f"({self._start_node.index}) -- {self._weight} --> ({self._end_node.index})"

            return f"({self._start_node.index}) --> ({self._end_node.index})"

        if self._weighted:
            return f"({self._start_node.index}) -- {self._weight} -- ({self._end_node.index})"

        return f"({self._start_node.index}) -- ({self._end_node.index})"
