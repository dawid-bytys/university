import sys
import warnings
from typing import Callable

import matplotlib
import matplotlib.pyplot as plt
import numpy as np

warnings.filterwarnings("ignore")
matplotlib.rcParams.update({"text.usetex": True, "font.size": 8})

axis_font = {"fontname": "Arial", "size": "12", "weight": "black"}


def discrete_derivative_a(x: float, h: float, fn: Callable[[float], float]) -> float:
    return (fn(x + h) - fn(x)) / h


def discrete_derivative_b(x: float, h: float, fn: Callable[[float], float]) -> float:
    return (fn(x + h) - fn(x - h)) / (2 * h)


def absolute_error(
    fn_1: Callable[[float], float], fn_2: Callable[[float], float], x: float
) -> float:
    return abs(fn_1(x) - fn_2(x))


def draw_plot(
    x: float,
    h: float,
    fn: Callable[[float], float],
    D_fn: Callable[[float], float],
    filename: str,
) -> None:
    error_a = absolute_error(
        lambda x_prim: discrete_derivative_a(x_prim, h, fn), D_fn, x
    )
    error_b = absolute_error(
        lambda x_prim: discrete_derivative_b(x_prim, h, fn), D_fn, x
    )

    fig = plt.figure(figsize=(10, 5), dpi=600)
    axes = fig.gca()

    plt.plot(h, error_a, linewidth=1.5, color="red", label="Method (A)")
    plt.plot(h, error_b, linewidth=1.5, color="blue", label="Method (B)")

    axes.set_xscale("log")
    axes.set_yscale("log")

    axes.set_xlabel("log(h)", **axis_font)
    axes.set_ylabel("log(E(h)) for x = 0.2", **axis_font)

    axes.legend()
    plt.grid()
    fig.savefig(filename)


if __name__ == "__main__":
    x_f32 = np.float32(0.2)
    x_f64 = np.float64(0.2)
    h_f32 = np.float32(np.logspace(start=-10, stop=1, num=1500))
    h_f64 = np.float64(np.logspace(start=-18, stop=1, num=1500))

    print("Drawing plots...")

    """sin(x)"""

    draw_plot(x_f32, h_f32, np.sin, np.cos, "./float32_sin.png")
    draw_plot(x_f64, h_f64, np.sin, np.cos, "./float64_sin.png")

    """exp(x)"""

    draw_plot(x_f32, h_f32, np.exp, np.exp, "./float32_exp.png")
    draw_plot(x_f64, h_f64, np.exp, np.exp, "./float64_exp.png")

    print("Plots have been successfully saved!")

    sys.exit(0)
