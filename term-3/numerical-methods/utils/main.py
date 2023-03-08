import numpy as np


def power_iteration(A, num_iterations: int):
    # Ideally choose a random vector
    # To decrease the chance that our vector
    # Is orthogonal to the eigenvector
    b_k = np.array([1, 1, 0])

    for _ in range(num_iterations):
        # calculate the matrix-by-vector product Ab
        b_k1 = np.dot(A, b_k)

        b_k = b_k1

    return b_k


print(power_iteration(np.array([[2, 1, -2], [1, 0, 0], [0, 1, 0]]), 105))
