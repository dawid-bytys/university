from typing import TypeVar

from .node import Node

Edge = TypeVar("Edge", bound="str")


class Edge:
    def __init__(
        self,
        start_node: Node,
        end_node: Node,
        directed: bool,
        weighted: bool,
        weight: int = 1,
    ) -> None:
        self._start_node = start_node
        self._end_node = end_node
        self._directed = directed
        self._weighted = weighted
        self._weight = weight

    @property
    def start_node(self) -> Node:
        return self._start_node

    @property
    def end_node(self) -> Node:
        return self._end_node

    @property
    def weight(self) -> int:
        return self._weight

    def __str__(self) -> str:
        if self._directed:
            if self._weighted:
                return f"({self._start_node.get_index}) -- {self._weight} --> ({self._end_node.get_index})"

            return f"({self._start_node.get_index}) --> ({self._end_node.get_index})"
        else:
            if self._weighted:
                return f"({self._start_node.get_index}) -- {self._weight} -- ({self._end_node.get_index})"

            return f"({self._start_node.get_index}) -- ({self._end_node.get_index})"
