import sys


def is_valid(board, row, col, num):
    for i in range(4):
        if board[row][i] == num or board[i][col] == num:
            return False

    start_row, start_col = 2 * (row // 2), 2 * (col // 2)

    for i in range(2):
        for j in range(2):
            if board[start_row + i][start_col + j] == num:
                return False

    return True


def solve_sudoku(board):
    empty_cell = find_empty_cell(board)

    if not empty_cell:
        return True

    row, col = empty_cell

    for num in range(1, 5):
        if is_valid(board, row, col, num):
            board[row][col] = num

            if solve_sudoku(board):
                return True

            board[row][col] = 0

    return False


def find_empty_cell(board):
    for i in range(4):
        for j in range(4):
            if board[i][j] == 0:
                return (i, j)
    return None


def print_board(board):
    for i in range(4):
        for j in range(4):
            print(board[i][j], end=" ")
        print()


if __name__ == "__main__":
    puzzle = [[0, 0, 0, 0], [0, 3, 4, 0], [4, 0, 0, 0], [0, 2, 0, 0]]

    if solve_sudoku(puzzle):
        print("Solution:")
        print_board(puzzle)
    else:
        print("No solution exists.")

    sys.exit(0)
