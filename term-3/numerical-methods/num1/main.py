import matplotlib
import numpy as np
import matplotlib.pyplot as plt
from typing import Callable

matplotlib.rcParams.update(
    {
        "text.usetex": True,
    }
)


def approximate_derivative_a(x: float, h: float, fn: Callable) -> float:
    return (fn(x + h) - fn(x)) / h


def approximate_derivative_b(x: float, h: float, fn: Callable) -> float:
    return (fn(x + h) - fn(x - h)) / (2 * h)


def absolute_error(fn_1: Callable, fn_2: Callable, x: float) -> float:
    return abs(fn_1(x) - fn_2(x))


def draw_plot(x: float, h: float, fn: Callable, D_fn: Callable, filename: str) -> None:
    error_a = absolute_error(lambda i: approximate_derivative_a(i, h, fn), D_fn, x)
    error_b = absolute_error(lambda i: approximate_derivative_b(i, h, fn), D_fn, x)

    fig = plt.figure(dpi=800)
    axes = fig.gca()

    plt.plot(h, error_a, linewidth=1.5, color="red", label="Method (A)")
    plt.plot(h, error_b, linewidth=1.5, color="blue", label="Method (B)")

    axes.set_xscale("log")
    axes.set_yscale("log")

    axes.set_xlabel("Log scale of h", fontsize=12, fontweight="bold")
    axes.set_ylabel("Log scale of Error (x = 0.2)", fontsize=12, fontweight="bold")

    axes.legend()
    plt.grid()
    fig.savefig(filename)


if __name__ == "__main__":
    x_1 = np.float32(0.2)
    x_2 = np.float64(0.2)
    h_1 = np.float32(np.logspace(-16, 3, 1000))
    h_2 = np.float64(np.logspace(-32, 3, 1000))

    """sin(x)"""
    draw_plot(x_1, h_1, np.sin, np.cos, "./float32_sin.png")
    draw_plot(x_2, h_2, np.sin, np.cos, "./float64_sin.png")

    """exp(x)"""
    draw_plot(x_1, h_1, np.exp, np.exp, "./float32_exp.png")
    draw_plot(x_2, h_2, np.exp, np.exp, "./float64_exp.png")
