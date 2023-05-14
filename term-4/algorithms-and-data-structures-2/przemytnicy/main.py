import heapq
import sys
from collections import defaultdict


class Graph:
    def __init__(self):
        self._adj_list = defaultdict(dict)

    def add_edge(self, start, end, weight):
        self._adj_list[start][end] = weight

    def dijkstra(self, start, end):
        distances = {node: float("inf") for node in self._adj_list}
        distances[start] = 0

        priority_queue = [(0, start)]

        while priority_queue:
            (distance, node) = heapq.heappop(priority_queue)

            if distance != distances[node]:
                continue

            for neighbour, cost in self._adj_list[node].items():
                old_cost = distances[neighbour]
                new_cost = distances[node] + cost
                if new_cost < old_cost:
                    distances[neighbour] = new_cost
                    heapq.heappush(priority_queue, (new_cost, neighbour))

        return distances[end]


def read_file(filename):
    with open(filename) as file:
        m = int(next(file))
        m_costs = [int(file.readline()) for _ in range(m)]
        edges = []
        next(file)
        for line in file:
            source, changed, cost = map(int, line.split())
            edges.append((source, changed, cost))
    return m_costs, edges


def calculate_cost(m_costs, graph):
    m_cost_final = [cost * 0.5 for cost in m_costs]

    for m_cost_new in range(1, len(m_costs)):
        m_cost_final[m_cost_new] += graph.dijkstra(1, m_cost_new + 1)
        m_cost_final[m_cost_new] += graph.dijkstra(m_cost_new + 1, 1)

    return min(m_cost_final)


if __name__ == "__main__":
    m_costs, edges = read_file("input.txt")
    graph = Graph()
    for edge in edges:
        graph.add_edge(*edge)
    result = calculate_cost(m_costs, graph)
    print(result)

    sys.exit(0)
