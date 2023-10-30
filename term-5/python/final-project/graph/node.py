from typing_extensions import Any, Self


class Node:
    def __init__(self: Self, index: int, value: Any) -> None:
        self._index = index
        self._value = value

    def index(self: Self) -> int:
        return self._index

    def value(self: Self) -> Any:
        return self._value

    def __lt__(self: Self, other: Self) -> bool:
        return self._index < other._index

    def __eq__(self: Self, other: object) -> bool:
        if not isinstance(other, Node):
            return False

        return self._index == other._index

    def __hash__(self: Self) -> int:
        return hash(self._index)
