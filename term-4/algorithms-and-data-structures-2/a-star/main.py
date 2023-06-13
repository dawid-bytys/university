import sys
from collections import deque
from heapq import heappop, heappush
from typing import List, Tuple


def parse_maze(maze: str) -> List[List[int]]:
    return [[int(j) for j in i.split(";")] for i in maze.split("\n") if i]


def find_start_end(maze: List[List[int]]) -> Tuple[Tuple[int, int], Tuple[int, int]]:
    start, end = None, None

    for i in range(len(maze)):
        for j in range(len(maze[i])):
            if maze[i][j] == 2:
                start = (i, j)
            elif maze[i][j] == 3:
                end = (i, j)

    return start, end


def is_within_maze(maze: List[List[int]], x: int, y: int) -> bool:
    return 0 <= x < len(maze) and 0 <= y < len(maze[0]) and maze[x][y] != 0


def bfs(
    maze: List[List[int]], start: Tuple[int, int], end: Tuple[int, int]
) -> Tuple[int, int]:
    visited = [[False for _ in range(len(maze[0]))] for _ in range(len(maze))]
    visited[start[0]][start[1]] = True
    queue = deque([(start, 0)])
    fields_analyzed = 1

    while queue:
        current, path_length = queue.popleft()
        fields_analyzed += 1

        if current == end:
            return path_length, fields_analyzed

        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            next_x, next_y = current[0] + dx, current[1] + dy
            if is_within_maze(maze, next_x, next_y) and not visited[next_x][next_y]:
                visited[next_x][next_y] = True
                queue.append(((next_x, next_y), path_length + 1))

    return -1, fields_analyzed


def a_star(
    maze: List[List[int]], start: Tuple[int, int], end: Tuple[int, int]
) -> Tuple[int, int]:
    visited = [[False for _ in range(len(maze[0]))] for _ in range(len(maze))]
    visited[start[0]][start[1]] = True
    queue = [(0, start, 0)]
    fields_analyzed = 1

    while queue:
        _, current, path_length = heappop(queue)
        fields_analyzed += 1

        if current == end:
            return path_length, fields_analyzed

        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            next_x, next_y = current[0] + dx, current[1] + dy
            if is_within_maze(maze, next_x, next_y) and not visited[next_x][next_y]:
                visited[next_x][next_y] = True
                heappush(
                    queue,
                    (
                        path_length + 1 + abs(end[0] - next_x) + abs(end[1] - next_y),
                        (next_x, next_y),
                        path_length + 1,
                    ),
                )

    return -1, fields_analyzed


if __name__ == "__main__":
    with open("maze.txt", "r") as f:
        maze_str = f.read()

    maze = parse_maze(maze_str)
    start, end = find_start_end(maze)

    print(f"BFS: {bfs(maze, start, end)}")
    print(f"A*: {a_star(maze, start, end)}")

    sys.exit(0)
