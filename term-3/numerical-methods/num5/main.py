import sys

import numpy as np
from matplotlib import pyplot as plt
from numpy import ndarray

from band import BandMatrix


def jacobi(
    A: BandMatrix, b: list[float], x0: list[float], tol=1e-6, max_iter=1000
) -> ndarray:
    """Solves the linear system Ax = b using the Jacobi method.

    Args:
        A (BandMatrix): The matrix A.
        b (list[float]): The vector b.
        x0 (list[float]): The initial guess.
        tol (float, optional): The tolerance. Defaults to 1e-6.
        max_iter (int, optional): The maximum number of iterations. Defaults to 1000.

    Returns:
        list[float]: The solution vector.
    """
    x = x0
    N = len(x)
    for _ in range(max_iter):
        x_new = np.zeros_like(x)
        for i in range(N):
            x_new[i] = b[i]
            for j in range(N):
                if i != j:
                    x_new[i] -= A.at(i, j) * x[j]
            x_new[i] /= A.at(i, i)
        if np.linalg.norm(x_new - np.array(x)) < tol:
            break
        x = x_new

    return x


def gauss_seidel(
    A: BandMatrix, b: list[float], x0: list[float], tol=1e-6, max_iter=1000
) -> ndarray:
    """Solves the linear system Ax = b using the Gauss-Seidel method.

    Args:
        A (BandMatrix): The matrix A.
        b (list[float]): The vector b.
        x0 (list[float]): The initial guess.
        tol (float, optional): The tolerance. Defaults to 1e-6.
        max_iter (int, optional): The maximum number of iterations. Defaults to 1000.

    Returns:
        list[float]: The solution vector.
    """
    x = x0
    N = len(x)
    for _ in range(max_iter):
        x_new = np.zeros_like(x)
        for i in range(N):
            x_new[i] = b[i]
            for j in range(N):
                if j < i:
                    x_new[i] -= A.at(i, j) * x_new[j]
                elif j > i:
                    x_new[i] -= A.at(i, j) * x[j]
            x_new[i] /= A.at(i, i)
        if np.linalg.norm(x_new - np.array(x)) < tol:
            break
        x = x_new

    return x


def print_vector(x: list[float] | ndarray) -> None:
    """Prints a vector. Used for debugging.

    Args:
        x (list[float] | ndarray): The vector to print.
    """
    if isinstance(x, ndarray):
        x = x.tolist()
    if len(x) > 10:
        print(f"[{x[0]}, {x[1]}, {x[2]}, ..., {x[-3]}, {x[-2]}, {x[-1]}]")
    else:
        print(x)


def get_numpy_pentadiagonal_matrix(
    a: float, b: float, c: float, d: float, e: float, N: int
) -> np.ndarray:
    """Returns a pentadiagonal matrix with the given values.

    Args:
        a (float): The value of the first subdiagonal.
        b (float): The value of the second subdiagonal.
        c (float): The value of the main diagonal.
        d (float): The value of the second superdiagonal.
        e (float): The value of the first superdiagonal.
        N (int): The size of the matrix.

    Returns:
        np.ndarray: The matrix.
    """
    A = np.zeros((N, N))
    for i in range(N):
        A[i, i] = c
        if i > 0:
            A[i, i - 1] = b
        if i > 1:
            A[i, i - 2] = a
        if i < N - 1:
            A[i, i + 1] = d
        if i < N - 2:
            A[i, i + 2] = e
    return A


def get_vector_error(x: list[float] | ndarray, y: list[float] | ndarray) -> float:
    """Returns the error between two vectors.

    Args:
        x (list[float] | ndarray): The first vector.
        y (list[float] | ndarray): The second vector.

    Returns:
        float: The error.
    """
    return np.linalg.norm(np.array(x) - np.array(y))


def draw_error_plot(
    jacobi_error: list[float] | ndarray,
    gauss_error: list[float] | ndarray,
    iterations: list[int],
) -> None:
    """Draws the error plot.

    Args:
        jacobi_error (list[float] | ndarray): The error of the Jacobi method.
        gauss_error (list[float] | ndarray): The error of the Gauss-Seidel method.
        iterations (list[int]): The number of iterations.
    """
    fig = plt.figure(figsize=(10, 5), dpi=600)
    axes = fig.gca()

    # Plot the error
    axes.plot(iterations, jacobi_error, linewidth=1.5, color="red", label="Jacobi")
    axes.plot(
        iterations, gauss_error, linewidth=1.5, color="blue", label="Gauss-Seidel"
    )

    # Set the x and y axis labels.
    axes.set_xlabel("Iteration")
    axes.set_ylabel("Error")

    # Set the title
    axes.set_title("Error plot")

    # Set scale
    axes.set_yscale("log")

    # Set the legend
    axes.legend()

    # Save the figure
    plt.savefig("error.png")


def get_errors(
    A: BandMatrix,
    x0: list[float],
    b: list[float],
    exact_sol: ndarray,
    iterations: int,
) -> tuple[list[float], list[float], list[int]]:
    """Returns the errors of the Jacobi and Gauss-Seidel methods.

    Args:
        A (BandMatrix): The matrix A.
        x0 (list[float]): The initial guess.
        b (list[float]): The vector b.
        exact_sol (list[float]): The exact solution.
        iterations (int): The number of iterations.

    Returns:
        tuple[list[float], list[float], list[int]]: The errors of the Jacobi and Gauss-Seidel methods.
    """
    jacobi_error = []
    gauss_error = []
    for N in range(1, iterations + 1):
        jacobi_sol = jacobi(A, b, x0, max_iter=N)
        gauss_sol = gauss_seidel(A, b, x0, max_iter=N)
        jacobi_error.append(get_vector_error(jacobi_sol, exact_sol))
        gauss_error.append(get_vector_error(gauss_sol, exact_sol))

    return jacobi_error, gauss_error, list(range(1, iterations + 1))


def main():
    N = 100
    BANDS = [
        [0.2] * (N - 2),
        [1.0] * (N - 1),
        [3.0] * N,
        [1.0] * (N - 1),
        [0.2] * (N - 2),
    ]

    A = BandMatrix(BANDS, N, 2, 2)

    b = [float(i) for i in range(1, N + 1)]
    x0 = [0.0] * N

    x_jacobi = jacobi(A, b, x0)
    print("Jacobi solution:")
    print_vector(x_jacobi)

    x_seidel = gauss_seidel(A, b, x0)
    print("Gauss-Seidel solution:")
    print_vector(x_seidel)

    A_numpy = get_numpy_pentadiagonal_matrix(0.2, 1.0, 3.0, 1.0, 0.2, N)
    x_exact = np.linalg.solve(A_numpy, b)
    print("Exact solution:")
    print_vector(x_exact)

    # jacobi_error, gauss_error, iterations = get_errors(A, x0, b, x_exact, 300)
    # draw_error_plot(jacobi_error, gauss_error, iterations)

    sys.exit(0)


if __name__ == "__main__":
    main()
