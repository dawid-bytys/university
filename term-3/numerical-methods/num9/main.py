import math
import sys
from typing import Callable
import numpy as np


def bisection(
    f: Callable[[float], float], a: float, b: float, tol: float = 1e-10
) -> tuple[float, int]:
    """Bisection method for finding roots of f(x) = 0 on [a, b].

    Args:
        f (function): Function to find roots of.
        a (float): Lower bound of interval.
        b (float): Upper bound of interval.
        tol (float): Tolerance for stopping criterion.

    Returns:
        float: Approximate root of f(x) = 0 on [a, b].
        int: Number of iterations.

    Raises:
        ValueError: If f(a) and f(b) do not have opposite signs.
        ValueError: If f is not defined on [a, b].
        ValueError: If f is not monotonic on [a, b].
    """
    try:
        f(a)
        f(b)
    except:
        raise ValueError("f is not defined on [a, b]")

    if f(a) * f(b) >= 0:
        raise ValueError("f(a) and f(b) do not have opposite signs")

    if not ((f(a) < 0 and f(b) > 0) or (f(a) > 0 and f(b) < 0)):
        raise ValueError("f is not monotonic on [a, b]")

    steps = 0
    c = a
    while abs(b - a) > tol:
        steps += 1
        c = (a + b) / 2

        if f(c) == 0.0:
            break

        if f(c) * f(a) < 0:
            b = c
        else:
            a = c

    return c, steps


def falsi(
    f: Callable[[float], float], a: float, b: float, tol: float = 1e-10
) -> tuple[float, int]:
    """Falsi method for finding roots of f(x) = 0 on [a, b].

    Args:
        f (function): Function to find roots of.
        a (float): Lower bound of interval.
        b (float): Upper bound of interval.
        tol (float): Tolerance for stopping criterion.

    Returns:
        float: Approximate root of f(x) = 0 on [a, b].
        int: Number of iterations.

    Raises:
        ValueError: If f(a) and f(b) do not have opposite signs.
        ValueError: If f is not monotonic on [a, b].
        ValueError: If f is not differentiable on (a, b).
    """
    try:
        f(a)
        f(b)
    except:
        raise ValueError("f is not defined on [a, b]")

    if f(a) * f(b) >= 0:
        raise ValueError("f(a) and f(b) do not have opposite signs")

    if not ((f(a) < 0 and f(b) > 0) or (f(a) > 0 and f(b) < 0)):
        raise ValueError("f is not monotonic on [a, b]")

    for x in [a + tol, b - tol]:
        try:
            math.isclose(f(x + tol), f(x), rel_tol=tol, abs_tol=tol)
            math.isclose(f(x), f(x - tol), rel_tol=tol, abs_tol=tol)
        except:
            raise ValueError("f is not differentiable on (a, b)")

    c = a
    fa = f(a)
    fb = f(b)
    fc = fa
    steps = 0
    while True:
        steps += 1
        if abs(fc) < tol or abs(b - a) < tol:
            return c, steps

        c = (a * fb - b * fa) / (fb - fa)
        fc = f(c)

        if abs(fc) < tol or abs(b - a) < tol:
            return c, steps

        if fa * fc < 0:
            b = c
            fb = fc
        else:
            a = c
            fa = fc


def secant(
    f: Callable[[float], float], a: float, b: float, tol: float = 1e-10
) -> tuple[float, int]:
    """Secant method for finding roots of f(x) = 0 on [a, b].

    Args:
        f (function): Function to find roots of.
        a (float): Lower bound of interval.
        b (float): Upper bound of interval.
        tol (float): Tolerance for stopping criterion.

    Returns:
        float: Approximate root of f(x) = 0 on [a, b].
        int: Number of iterations.

    Raises:
        ValueError: If f(a) and f(b) do not have opposite signs.
        ValueError: If f is not defined on [a, b].
    """
    try:
        fa = f(a)
        fb = f(b)
    except:
        raise ValueError("f is not defined on [a, b]")

    if fa * fb >= 0:
        raise ValueError("f(a) and f(b) do not have opposite signs")

    c = a
    fc = fa
    steps = 0
    while abs(fc) > tol and abs(b - a) > tol:
        steps += 1
        d = (a * fb - b * fa) / (fb - fa)
        fd = f(d)
        if fd * fc < 0:
            b = c
            fb = fc
        else:
            a = c
            fa = fc
        c = d
        fc = fd
    return c, steps


def newton(
    f: Callable[[float], float],
    df: Callable[[float], float],
    x: float,
    tol: float = 1e-10,
) -> tuple[float, int]:
    """Newton's method for finding roots of f(x) = 0.

    Args:
        f (function): Function to find roots of.
        df (function): Derivative of f.
        x (float): Initial guess.
        tol (float): Tolerance for stopping criterion.

    Returns:
        float: Approximate root of f(x) = 0.
        int: Number of iterations.

    Raises:
        ValueError: If f is not defined at x.
        ValueError: If df is not defined at x.
        ValueError: If df(x) is too small.
    """
    try:
        fx = f(x)
    except:
        raise ValueError("f is not defined at x")

    steps = 0
    while abs(fx) > tol:
        steps += 1
        try:
            dx = df(x)
        except:
            raise ValueError("df is not defined at x")
        if abs(dx) < tol:
            raise ValueError("df(x) is too small")
        x = x - fx / dx
        fx = f(x)
    return x, steps


if __name__ == "__main__":
    fn = lambda x, n: (np.exp(x) - 2) ** n
    fn2 = lambda x: 4 * x**3 - 2 * x**2 + 8 * x + 6

    # Bisection method
    """
    print("Bisection method")
    for n in [1, 2, 3]:
        try:
            bisection_approx_root, bisection_steps = bisection(lambda x: fn(x, n), 0, 1)
            print(
                f"For n = {n} we find the root to be {bisection_approx_root} in {bisection_steps} steps."
            )
        except ValueError as e:
            print(f"For n = {n} we cannot use the bisection method, reason: {e}.")
            """

    bis, steps = secant(fn2, -2, 0, tol=1e-100)
    print(bis, steps)

    sys.exit(0)
