import sys
from functools import reduce

from typing_extensions import Self


class BandMatrix:
    """A memory-efficient implementation of a square banded matrix."""

    def __init__(
        self: Self,
        bands: list[list[float]],
        size: int,
        lower_bandwidth: int,
        upper_bandwidth: int,
    ) -> None:
        if len(bands) != lower_bandwidth + upper_bandwidth + 1:
            raise ValueError("Invalid number of bands.")

        if size != len(bands[lower_bandwidth]):
            raise ValueError("Invalid size.")

        self._bands = bands
        self._size = size
        self._lower_bandwidth = lower_bandwidth
        self._upper_bandwidth = upper_bandwidth
        self._diagonal_idx = self._bands.index(max(self._bands, key=len))

    @property
    def bands(self: Self) -> list[list[float]]:
        return self._bands

    @property
    def size(self: Self) -> int:
        return self._size

    @property
    def lower_bandwidth(self: Self) -> int:
        return self._lower_bandwidth

    @property
    def upper_bandwidth(self: Self) -> int:
        return self._upper_bandwidth

    def __str__(self: Self) -> str:
        return str(self._bands)

    def get_band_position(self: Self, row: int, column: int) -> tuple[int, int] | None:
        """Returns the band and position of the given coordinates or None if the position is out of bounds."""
        if row < 0 or row >= self._size or column < 0 or column >= self._size:
            raise ValueError("Invalid position.")

        if not self.is_band_required(row, column):
            return None

        return column - row + self._diagonal_idx, min(row, column)

    def at(self: Self, row: int, column: int) -> float:
        """Returns the value at the given position."""
        band_position = self.get_band_position(row, column)
        if band_position is not None:
            band, position = band_position
            return self._bands[band][position]

        return 0.0

    def update(self: Self, row: int, column: int, value: float) -> None:
        """Updates the matrix with the given function value."""
        band_position = self.get_band_position(row, column)
        if band_position is not None:
            band, position = band_position
            self._bands[band][position] = value

    def is_band_required(self: Self, row: int, column: int) -> bool:
        """Returns True if the given position is required for the LU decomposition."""
        return not (
            (column < row - self._lower_bandwidth)
            or (column > row + self._upper_bandwidth)
        )

    def print(self: Self) -> None:
        """Prints the matrix in a human-readable format."""
        for row in range(self._size):
            for column in range(self._size):
                print(self.at(row, column), end=" ")
            print()

    def lu_decomposition(self: Self) -> tuple[Self, Self]:
        """Returns lower and upper triangular matrices.

        Unnecessary calculations and memory-efficient storage are taken into account.
        """
        # allocate memory for the lower and upper matrices
        lower = BandMatrix(
            bands=[
                [1.0] * (self._size - i) for i in range(self._lower_bandwidth, -1, -1)
            ],
            size=self._size,
            lower_bandwidth=self._lower_bandwidth,
            upper_bandwidth=0,
        )
        upper = BandMatrix(
            bands=[[0.0] * (self._size - i) for i in range(self._upper_bandwidth + 1)],
            size=self._size,
            lower_bandwidth=0,
            upper_bandwidth=self._upper_bandwidth,
        )

        # Modified Doolitle's algorithm
        for i in range(self._size):
            for j in range(i, self._size):
                # skip unnecessary calculations
                if not self.is_band_required(i, j):
                    continue

                # skip unnecessary calculations by reducing the range of summation
                reduced_range = range(max(i - self._lower_bandwidth, 0), j)
                local_sum = sum(lower.at(i, k) * upper.at(k, j) for k in reduced_range)
                upper.update(i, j, self.at(i, j) - local_sum)

            for j in range(i + 1, self._size):
                # skip unnecessary calculations
                if not self.is_band_required(j, i):
                    continue

                # avoid division by zero
                if upper.at(i, i) == 0:
                    raise ValueError("Division by zero.")

                # skip unnecessary calculations by reducing the range of summation
                reduced_range = range(max(j - self._upper_bandwidth, 0), i)
                local_sum = sum(lower.at(j, k) * upper.at(k, i) for k in reduced_range)
                lower.update(j, i, (self.at(j, i) - local_sum) / upper.at(i, i))

        return lower, upper


def solve_for_banded(
    lower: BandMatrix, upper: BandMatrix, b: list[float]
) -> tuple[list[float]]:
    """Returns the solution of the equation Ax = b.

    The solution is calculated using the forward and backward substitution reducing unnecessary calculations.
    """
    if lower.size != upper.size or lower.size != len(b) or lower.size != upper.size:
        raise ValueError("Invalid size.")

    size = lower.size

    # allocate memory for the solution
    y = [0.0] * size
    x = [0.0] * size

    # forward substitution
    for i in range(size):
        if i == 0:
            y[i] = b[i]
        else:
            # skip unnecessary calculations by reducing the range of summation
            reduced_range = range(max(0, i - lower.lower_bandwidth), i)
            local_sum = sum(lower.at(i, j) * y[j] for j in reduced_range)
            y[i] = b[i] - local_sum

    # backward substitution
    for i in range(size - 1, -1, -1):
        # avoid division by zero
        if upper.at(i, i) == 0.0:
            raise ValueError("Division by zero.")

        if i == size - 1:
            x[i] = y[i] / upper.at(i, i)
        else:
            # skip unnecessary calculations by reducing the range of summation
            reduced_range = range(i + 1, min(size, i + upper.upper_bandwidth + 1))
            local_sum = sum(upper.at(i, j) * x[j] for j in reduced_range)
            x[i] = (y[i] - local_sum) / upper.at(i, i)

    return x


def lu_determinant(upper: BandMatrix) -> float:
    """Returns the determinant of the matrix.

    The determinant is calculated using the diagonal elements of the upper matrix.
    """
    return reduce(lambda x, y: x * y, [upper.at(i, i) for i in range(upper.size)])


def main():
    # size of the matrix
    N = 100

    # create the matrix A of size N x N
    matrix_A = BandMatrix(
        bands=[
            [0.2] * (N - 1),
            [1.2] * N,
            [(0.1) / i for i in range(1, N)],
            [(0.4) / pow(i, 2) for i in range(1, N - 1)],
        ],
        size=N,
        lower_bandwidth=1,
        upper_bandwidth=2,
    )

    # create the vector x of size N
    vector_x = [i for i in range(1, N + 1)]

    # LU decomposition
    lower, upper = matrix_A.lu_decomposition()

    # solve the equation Ay = x
    vector_y = solve_for_banded(lower, upper, vector_x)

    # calculate the determinant of the matrix A
    determinant = lu_determinant(upper)

    # print the results
    print(f"Matrix A: {matrix_A}", end="\n\n")
    print(f"Vector x: {vector_x}", end="\n\n")
    print(f"Vector y: {vector_y}", end="\n\n")
    print(f"Determinant: {determinant}")

    sys.exit(0)


if __name__ == "__main__":
    main()
