import numpy as np
import sys


def qr_algorithm(M: np.ndarray) -> np.ndarray:
    """
    Compute the eigenvalues of a matrix using the QR algorithm.

    Args:
        M (np.ndarray): The matrix to compute the eigenvalues of.

    Returns:
        np.ndarray: The eigenvalues of the matrix.
    """
    # Make a copy of M so we don't modify the original matrix
    A = np.array(M, dtype=float)

    # Set a threshold for the maximum number of iterations
    max_iter = 1000

    # Set a threshold for the tolerance of the eigenvalue approximation
    tolerance = 1e-12

    # Iterate until the matrix has converged (or until the maximum number of iterations has been reached)
    for _ in range(max_iter):
        # Compute the QR decomposition of A
        Q, R = np.linalg.qr(A)

        # Compute the next approximation for A
        A_new = R.dot(Q)

        # Check if the matrix has converged (i.e., if the eigenvalues have stopped changing)
        if np.allclose(A, A_new, rtol=tolerance):
            # The matrix has converged, so break out of the loop
            break

        # Update A to the new approximation
        A = A_new

    # Compute the eigenvalues of A
    eigenvalues = np.diag(A)
    return eigenvalues


def power_iteration(
    B: np.ndarray, num_iterations: int, tol=1e-6
) -> tuple[float, np.ndarray]:
    """
    Compute the dominant eigenvalue and eigenvector of a matrix using the power iteration method.

    Args:
        B (np.ndarray): The matrix to compute the dominant eigenvalue and eigenvector of.
        num_iterations (int): The number of iterations to perform.

    Returns:
        tuple[float, np.ndarray]: The dominant eigenvalue and eigenvector of the matrix.
    """
    # Start with a random eigenvector
    eigenvector = np.random.rand(B.shape[1])

    for _ in range(num_iterations):
        # Calculate the matrix-by-vector product Ab
        Bb = B.dot(eigenvector)

        # Calculate the norm of the matrix-by-vector product
        eigenvalue = np.linalg.norm(Bb)

        # Re-normalize the eigenvector
        eigenvector = Bb / eigenvalue

    return eigenvalue, eigenvector


def print_eigenvalues(eigenvalues: np.ndarray) -> None:
    """
    Print the eigenvalues of a matrix.

    Args:
        eigenvalues (np.ndarray): The eigenvalues of a matrix.
    """
    for i, eigenvalue in enumerate(eigenvalues):
        print(f"λ_{i + 1} = {eigenvalue}")


if __name__ == "__main__":
    # Define a matrix
    M = np.array([[3, 6, 6, 9], [1, 4, 0, 9], [0, 0.2, 6, 12], [0, 0, 0.1, 6]])
    B = np.array([[3, 4, 2, 4], [4, 7, 1, -3], [2, 1, 3, 2], [4, -3, 2, 2]])

    # Compute the eigenvalues using the QR algorithm
    eigenvalues = qr_algorithm(M)

    print("(A)")
    print("QR Eigenvalues: ")
    print_eigenvalues(eigenvalues)

    # Compute the eigenvalues using NumPy
    numpy_eigenvalues = np.linalg.eig(M)[0]

    print("\nNumPy eigenvalues: ")
    print_eigenvalues(numpy_eigenvalues)

    # Compute the largest eigenvalue and eigenvector of B using the power iteration method
    largest_eigenvalue, largest_eigenvector = power_iteration(B, num_iterations=100)
    print("\n(B)")
    print(f"Largest eigenvalue: {largest_eigenvalue}")
    print(f"Largest eigenvector: {largest_eigenvector}")

    sys.exit(0)
