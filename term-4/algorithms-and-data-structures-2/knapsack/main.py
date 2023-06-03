import sys


def knapsack(items: list[int], max_weight: int) -> tuple[list[int], int]:
    n = len(items)
    K = [[0 for w in range(max_weight + 1)] for i in range(n + 1)]

    for i in range(n + 1):
        for w in range(max_weight + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif items[i - 1][0] <= w:
                K[i][w] = max(
                    items[i - 1][1] + K[i - 1][w - items[i - 1][0]], K[i - 1][w]
                )
            else:
                K[i][w] = K[i - 1][w]

    max_value = K[n][max_weight]
    selected_items = []

    w = max_weight
    for i in range(n, 0, -1):
        if max_value <= 0:
            break
        if max_value == K[i - 1][w]:
            continue
        else:
            selected_items.append(i)
            max_value -= items[i - 1][1]
            w -= items[i - 1][0]

    return selected_items, K[n][max_weight]


def read_data_from_file(file_path: str) -> tuple[int, list[int, int]]:
    with open(file_path, "r") as file:
        lines = file.readlines()
        max_weight = int(lines[0].strip())
        items = []
        for line in lines[1:]:
            weight, value = map(int, line.strip().split())
            items.append((weight, value))
    return max_weight, items


if __name__ == "__main__":
    max_weight, items = read_data_from_file("input.txt")
    selected_items, max_value = knapsack(items, max_weight)
    print("Selected items:", selected_items)
    print("Maximum value:", max_value)

    sys.exit(0)
