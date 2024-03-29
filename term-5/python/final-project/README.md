# Graph Class README

This README provides an overview of the `Graph` class and its methods. The `Graph` class is designed for representing a graph data structure and includes functionalities for manipulating nodes and edges, as well as performing various graph algorithms.

## Table of Contents

1. [Initialization](#initialization)
2. [Node and Edge Management](#node-and-edge-management)
3. [Graph Properties](#graph-properties)
4. [Graph Algorithms](#graph-algorithms)
5. [File I/O](#file-io)
6. [Examples](#examples)

---

## Initialization<a name="initialization"></a>

### `__init__(directed: bool = True, weighted: bool = True, first_idx: Literal[0, 1] = 0) -> None`

- Initializes a new graph.
- Parameters:
  - `directed`: Indicates whether the graph is directed (default is True).
  - `weighted`: Indicates whether the graph is weighted (default is True).
  - `first_idx`: Specifies the starting index for node indices (default is 0).

---

## Node and Edge Management<a name="node-and-edge-management"></a>

### `add_node(value: Any = None) -> None`

- Adds a new node to the graph.
- Parameters:
  - `value`: The value associated with the new node (default is None).

### `add_edge(start_node_idx: int, end_node_idx: int, weight: float = 1.0) -> None`

- Adds a new edge between two nodes.
- Parameters:
  - `start_node_idx`: Index of the starting node.
  - `end_node_idx`: Index of the ending node.
  - `weight`: Weight of the edge (default is 1).

### `remove_node(idx: int) -> None`

- Removes a node and all its incident edges from the graph.
- Parameters:
  - `idx`: Index of the node to be removed.

### `remove_edge(start_node_idx: int, end_node_idx: int) -> None`

- Removes an edge between two nodes.
- Parameters:
  - `start_node_idx`: Index of the starting node.
  - `end_node_idx`: Index of the ending node.

---

## Graph Properties<a name="graph-properties"></a>

### `nodes() -> Iterator[Node]`

- Returns an iterator over all nodes in the graph.

### `edges() -> Iterator[Edge]`

- Returns an iterator over all edges in the graph.

### `is_directed() -> bool`

- Returns True if the graph is directed, False otherwise.

### `is_weighted() -> bool`

- Returns True if the graph is weighted, False otherwise.

### `get_node(idx: int) -> Node`

- Retrieves a node by its index.
- Parameters:
  - `idx`: Index of the node to be retrieved.

### `get_edge(start_node_idx: int, end_node_idx: int) -> Edge`

- Retrieves an edge by the indices of its starting and ending nodes.
- Parameters:
  - `start_node_idx`: Index of the starting node.
  - `end_node_idx`: Index of the ending node.

### `adjacent_nodes(idx: int) -> Iterator[Node]`

- Returns an iterator over nodes adjacent to the specified node.
- Parameters:
  - `idx`: Index of the node.

### `edge_weight(start_node_idx: int, end_node_idx: int) -> int`

- Returns the weight of the edge between two nodes.
- Parameters:
  - `start_node_idx`: Index of the starting node.
  - `end_node_idx`: Index of the ending node.

---

## Graph Algorithms<a name="graph-algorithms"></a>

### `bfs(start_node_idx: int) -> Iterator[Node]`

- Performs Breadth-First Search starting from the specified node.
- Parameters:
  - `start_node_idx`: Index of the starting node.
- Returns an iterator over visited nodes in BFS order.

### `dfs(start_node_idx: int) -> Iterator[Node]`

- Performs Depth-First Search starting from the specified node.
- Parameters:
  - `start_node_idx`: Index of the starting node.
- Returns an iterator over visited nodes in DFS order.

### `dijkstra(start_node_idx: int, end_node_idx: int) -> tuple[float, Iterator[Node]]`

- Applies Dijkstra's algorithm to find the shortest path and its weight between two nodes.
- Parameters:
  - `start_node_idx`: Index of the starting node.
  - `end_node_idx`: Index of the ending node.
- Returns a tuple containing the weight of the shortest path and an iterator over the nodes in the path.

**Note:** This method assumes that the graph is weighted. If the graph is not weighted, a `ValueError` will be raised.

---

## File I/O<a name="file-io"></a>

### `read_from_file(file_path: str) -> None`

- Reads a graph from a file.
- Parameters:
  - `file_path`: Path to the file containing graph information.
- File Format (weighted graph): Each line represents an edge in the format `start_node_idx end_node_idx weight`.
- File Format (unweighted graph): Each line represents an edge in the format `start_node_idx end_node_idx`.

---

## Examples<a name="examples"></a>

Here are some examples demonstrating the usage of the `Graph` class:

```python
# Example 1: Creating a directed, weighted graph
graph = Graph(directed=True, weighted=True, first_idx=1)

graph.add_node(1)
graph.add_node(2)
graph.add_node(3)
graph.add_node(4)
graph.add_node(5)

graph.add_edge(1, 2, 11)
graph.add_edge(2, 4, 5)
graph.add_edge(2, 5, 5)
graph.add_edge(5, 3, 5)
graph.add_edge(4, 3, 11)

# Example 2: performing a Dijkstra algorithm between node "1" and "3"
distance, path = graph.dijstra(1, 3)

print(f'Distance: {distance}') # 21
print(f'Path: {[node.value for node in path]}') # 1 2 5 3

# Example 3: performing a BFS algorithm
bfs_path = graph.bfs(1)
print(f'BFS Path: {[node.value for node in bfs_path]}') # 1 2 5 4 3

# Example 4: performing a DFS algorithm
dfs_path = graph.dfs(1)
print(f'DFS Path: {[node.value for node in dfs_path]}') # 1 2 4 3 5



```
