import sys
import numpy as np
import matplotlib.pyplot as plt


def lagrange_interpolation(n: int, knots: list[float], f: callable) -> callable:
    """Returns a function that evaluates the Lagrange interpolating polynomial of degree n
    with knots at the points in knots and function values f at the knots.

    Args:
        n (int): The degree of the polynomial.
        knots (list[float]): The knots of the polynomial.
        f (callable): The function whose values are known at the knots.

    Returns:
        callable: The Lagrange interpolating polynomial.
    """

    def L(x, i):
        result = 1
        for j in range(n + 1):
            if j != i:
                result *= (x - knots[j]) / (knots[i] - knots[j])
        return result

    def P(x):
        result = 0
        for i in range(n + 1):
            result += f(knots[i]) * L(x, i)
        return result

    return P


def draw_plot(f: callable, knots: list[float], id: int) -> None:
    """Draws a plot of the Lagrange interpolating polynomial of degree n with knots at the
    points in knots and function values f at the knots.

    Args:
        f (callable): The function whose values are known at the knots.
        knots (list[float]): The knots of the polynomial.
        id (int): The id of the plot.
    """
    DEGREE = len(knots) - 1
    X_VALUES = np.linspace(-1, 1, 1000)
    Y_VALUES = [lagrange_interpolation(DEGREE, knots, f)(x) for x in X_VALUES]

    plt.title(f"Degree {DEGREE}")
    plt.plot(X_VALUES, Y_VALUES, label=f"P_{DEGREE}(x)", color="red")
    plt.plot(X_VALUES, [f(x) for x in X_VALUES], label="f(x)", color="green")
    plt.scatter(knots, [f(x) for x in knots], label="Knots")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid()
    plt.legend()
    plt.show()
    # plt.savefig(f"degree_{DEGREE}_{id}.png")
    plt.close()


if __name__ == "__main__":
    f_1 = lambda x: 1 / (1 + 25 * (x) ** 2)
    f_2 = lambda x: abs(3 * x)

    a_knots = lambda n: [-1 + 2 * i / (n + 1) for i in range(n + 1)]
    b_knots = lambda n: np.cos(
        [((2 * i + 1) / (2 * (n + 1))) * np.pi for i in range(n + 1)]
    )

    for N in [2, 4, 8, 16]:
        draw_plot(f_1, a_knots(N), 1)
        draw_plot(f_2, a_knots(N), 2)
        draw_plot(f_1, b_knots(N), 3)
        draw_plot(f_2, b_knots(N), 4)

    sys.exit(0)
