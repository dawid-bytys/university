import sys


class BandMatrix:
    """A memory-efficient implementation of a square banded matrix."""

    def __init__(
        self,
        bands: list[list[float]],
        size: int,
        lower_bandwidth: int,
        upper_bandwidth: int,
    ) -> None:
        self._bands = bands
        self._size = size
        self._lower_bandwidth = lower_bandwidth
        self._upper_bandwidth = upper_bandwidth

        assert len(bands) == lower_bandwidth + upper_bandwidth + 1
        assert size == len(bands[lower_bandwidth])

    @property
    def bands(self) -> list[list[float]]:
        return self._bands

    @property
    def size(self) -> int:
        return self._size

    @property
    def lower_bandwidth(self) -> int:
        return self._lower_bandwidth

    @property
    def upper_bandwidth(self) -> int:
        return self._upper_bandwidth

    def get_band_position(self, row: int, column: int) -> tuple[int, int] | None:
        """Returns the band and position of the given coordinates or None if the position is out of bounds."""
        assert row >= 0 and column >= 0
        assert row < self._size and column < self._size

        diff = row - column
        if diff > self._lower_bandwidth or -diff > self._upper_bandwidth:
            return None

        diagonal_band = max(self._bands, key=len)
        diagonal_idx = self._bands.index(diagonal_band)
        return column - row + diagonal_idx, min(row, column)

    def at(self, row: int, column: int) -> float:
        """Returns the value at the given position."""
        band_position = self.get_band_position(row, column)
        if band_position is not None:
            band, position = band_position
            return self._bands[band][position]

        return 0.0

    def update(self, row: int, column: int, value: float) -> None:
        """Updates the matrix with the given function value."""
        band_position = self.get_band_position(row, column)
        if band_position is not None:
            band, position = band_position
            self._bands[band][position] = value

    def print(self) -> None:
        """Prints the matrix in a human-readable format."""
        for row in range(self._size):
            for column in range(self._size):
                print(self.at(row, column), end=" ")
            print()


def lu_decomposition(matrix: BandMatrix) -> tuple[BandMatrix, BandMatrix]:
    """Returns lower and upper triangular matrices.

    Unnecessary calculations and memory-efficient storage are taken into account.
    """
    size = matrix.size
    lower_bandwidth = matrix.lower_bandwidth
    upper_bandwidth = matrix.upper_bandwidth

    # allocate memory for the lower and upper matrices
    lower = BandMatrix(
        bands=[[0.0] * (size - i) for i in range(lower_bandwidth, -1, -1)],
        size=size,
        lower_bandwidth=lower_bandwidth,
        upper_bandwidth=0,
    )
    upper = BandMatrix(
        bands=[[0.0] * (size - i) for i in range(upper_bandwidth + 1)],
        size=size,
        lower_bandwidth=0,
        upper_bandwidth=upper_bandwidth,
    )

    # Crout's algorithm
    for i in range(size):
        # fill the diagonal of the lower matrix with 1s
        lower.update(i, i, 1.0)

        for j in range(i, size):
            # skip if the element is zero to avoid unnecessary calculations
            if matrix.at(i, j) != 0.0:
                local_sum = sum([lower.at(i, k) * upper.at(k, j) for k in range(i)])
                upper.update(i, j, matrix.at(i, j) - local_sum)

        for j in range(i + 1, size):
            # skip if the element is zero to avoid unnecessary calculations
            if matrix.at(j, i) != 0.0:
                assert upper.at(i, i) != 0.0
                local_sum = sum([lower.at(j, k) * upper.at(k, i) for k in range(i)])
                lower.update(j, i, (matrix.at(j, i) - local_sum) / upper.at(i, i))

    return lower, upper


def solve_equation(lower: BandMatrix, upper: BandMatrix, b: list[float]) -> list[float]:
    """Returns the solution of the equation Ax = b.

    The solution is calculated using the forward and backward substitution reducing unnecessary calculations.
    """
    size = lower.size

    # allocate memory for the solution
    y = [0.0] * size
    x = [0.0] * size

    # forward substitution
    for i in range(size):
        y[i] = b[i] - sum([lower.at(i, k) * y[k] for k in range(i)])

    # backward substitution
    for i in range(size - 1, -1, -1):
        assert upper.at(i, i) != 0.0
        x[i] = (
            y[i] - sum([upper.at(i, k) * x[k] for k in range(i + 1, size)])
        ) / upper.at(i, i)

    return x


def lu_determinant(upper: BandMatrix) -> float:
    """Returns the determinant of the matrix.

    The determinant is calculated using the diagonal elements of the upper matrix.
    """
    from functools import reduce

    return reduce(lambda x, y: x * y, [upper.at(i, i) for i in range(upper.size)])


if __name__ == "__main__":
    # size of the matrix
    N = 100

    # create the matrix A of size N x N
    matrix_A = BandMatrix(
        bands=[
            [0.2 for _ in range(N - 1)],
            [1.2 for _ in range(N)],
            [(0.1) / i for i in range(1, N)],
            [(0.4) / pow(i, 2) for i in range(1, N - 1)],
        ],
        size=N,
        lower_bandwidth=1,
        upper_bandwidth=2,
    )

    # create the vector x of size N
    vector_x = [i for i in range(1, N + 1)]

    lower, upper = lu_decomposition(matrix_A)
    vector_y = solve_equation(lower, upper, vector_x)
    determinant = lu_determinant(upper)

    sys.exit(0)
