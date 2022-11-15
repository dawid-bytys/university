from band import BandMatrix, solve_for_banded
import numpy as np
import matplotlib.pyplot as plt
import scipy.sparse as sps
import time
import sys


def lu_decomposition(
    A: list[list[float]],
) -> tuple[list[list[float]], list[list[float]]]:
    """Returns the lower and upper triangular matrices of the LU decomposition of A."""
    size = len(A)

    # allocate memory for the lower and upper triangular matrices
    L = [[0.0] * size for _ in range(size)]
    U = [[0.0] * size for _ in range(size)]

    for i in range(size):
        # calculate the upper triangular matrix
        for k in range(i, size):
            # sum the products of the lower and upper triangular matrices
            local_sum = sum(L[i][j] * U[j][k] for j in range(i))

            # calculate the element of the upper triangular matrix
            U[i][k] = A[i][k] - local_sum

        # calculate the lower triangular matrix
        for k in range(i, size):
            if i == k:
                L[i][i] = 1.0
            else:
                # sum the products of the lower and upper triangular matrices
                local_sum = sum(L[k][j] * U[j][i] for j in range(i))

                # calculate the element of the lower triangular matrix
                L[k][i] = (A[k][i] - local_sum) / U[i][i]

    return L, U


def forward_substitution(L: list[list[float]], b: list[float]) -> list[float]:
    """Returns the solution of the forward substitution Ly = b."""
    size = len(L)
    y = [0.0] * size

    for i in range(size):
        # sum the products of the lower triangular matrix and the solution vector
        local_sum = sum(L[i][j] * y[j] for j in range(i))

        # calculate the element of the solution vector
        y[i] = (b[i] - local_sum) / L[i][i]

    return y


def backward_substitution(U: list[list[float]], y: list[float]) -> list[float]:
    """Returns the solution of the backward substitution Ux = y."""
    size = len(U)
    x = [0.0] * size

    for i in range(size - 1, -1, -1):
        # sum the products of the upper triangular matrix and the solution vector
        local_sum = sum(U[i][j] * x[j] for j in range(i + 1, size))

        # calculate the element of the solution vector
        x[i] = (y[i] - local_sum) / U[i][i]

    return x


def scherman_morrison(
    lower: BandMatrix, upper: BandMatrix, u: list[float], v: list[float], b: list[float]
) -> list[float]:
    """Returns the solution of the Scherman-Morrison equation Ax = b."""
    size = lower.size

    # Calculate vectors z and x
    z = solve_for_banded(lower, upper, b)
    x = solve_for_banded(lower, upper, u)

    # Calculate the solution
    nominator = sum(v[i] * z[i] for i in range(size))
    denominator = 1 + sum(v[i] * x[i] for i in range(size))

    return [z[i] - x[i] * (nominator / denominator) for i in range(size)]


def standard_lu_solve(
    L: list[list[float]], U: list[list[float]], b: list[float]
) -> list[float]:
    """Returns the solution of the standard LU decomposition Ax = b."""
    y = forward_substitution(L, b)
    return backward_substitution(U, y)


def draw_plot(
    sizes: list[int],
    scherman_data: list[float],
    standard_lu_data: list[float],
    filename: str,
):
    fig = plt.figure(figsize=(10, 5), dpi=600)
    axes = fig.gca()

    plt.plot(
        sizes,
        scherman_data,
        linewidth=1.5,
        color="red",
        label="Scherman-Morrison with LU",
    )
    plt.plot(sizes, standard_lu_data, linewidth=1.5, color="blue", label="Standard LU")

    axes.set_xscale("linear")
    axes.set_yscale("linear")

    axes.set_xlabel("Size of the matrix")
    axes.set_ylabel("Time(s)")

    axes.legend()
    plt.grid()
    fig.savefig(filename)


def benchmark_scherman_morisson(size: int) -> float:
    bands = [
        [9.0] * size,
        [7.0] * (size - 1),
    ]

    A = BandMatrix(bands, size, 0, 1)
    u = [1.0] * size
    v = u
    b = [5.0] * size

    L, U = A.lu_decomposition()

    start = time.monotonic()
    scherman_morrison(L, U, u, v, b)
    end = time.monotonic()

    return end - start


def benchmark_standard_lu(size: int) -> float:
    data = np.array([np.full(size, 9), np.full(size, 7)])
    bandwidths = np.array([0, 1])
    A = sps.dia_matrix((data, bandwidths), shape=(size, size)).toarray()
    b = np.full(size, 5.0)

    L, U = lu_decomposition(A)

    start = time.monotonic()
    standard_lu_solve(L, U, b)
    end = time.monotonic()

    return end - start


def main():
    # Size of the matrix
    N = 50

    # Bands of the matrix
    bands = [
        [9.0] * N,
        [7.0] * (N - 1),
    ]

    # Create the matrix A of size N x N
    A = BandMatrix(bands, N, 0, 1)

    # Create vectors u, v and b.
    u = [1.0] * N
    v = [1.0] * N
    b = [5.0] * N

    # LU decomposition
    L, U = A.lu_decomposition()

    # Solve the Scherman-Morrison equation
    x = scherman_morrison(L, U, u, v, b)

    # sizes = list(range(0, 2001, 100))
    # print("Benchmarking Scherman-Morrison with LU...")
    # scherman_morisson_data = [benchmark_scherman_morisson(i) for i in sizes]

    # print("Benchmarking standard LU solve...")
    # standard_lu_data = [benchmark_standard_lu(i) for i in sizes]

    # draw_plot(sizes, scherman_morisson_data, standard_lu_data, "./plot.png")

    # Print the solution
    print(f"Solution of Ax = b using Scherman-Morisson with LU: {x}", end="\n\n")

    sys.exit(0)


if __name__ == "__main__":
    main()
