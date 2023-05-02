def read_input_file(input_file):
    with open(input_file, "r") as file:
        n = int(file.readline().strip())
        keys = [int(line.strip()) for line in file.readlines()]
    return n, keys


def find_cycles(n, keys):
    visited = [False] * (n + 1)
    cycles = []

    for i in range(n):
        if not visited[i + 1]:
            current = i + 1
            cycle = []
            while not visited[current]:
                visited[current] = True
                cycle.append(current)
                current = keys[current - 1]
            cycles.append(cycle)

    return cycles


def min_piggy_banks_to_break_and_example(n, keys):
    cycles = find_cycles(n, keys)
    result = len(cycles) - 1
    example = [cycle[0] for cycle in cycles]

    return result, example


def main():
    input_file = "input.txt"
    n, keys = read_input_file(input_file)
    result, example = min_piggy_banks_to_break_and_example(n, keys)
    print(f"Minimum number of piggy banks to break: {result}")
    print(f"Example of piggy banks to break: {example}")


if __name__ == "__main__":
    main()
