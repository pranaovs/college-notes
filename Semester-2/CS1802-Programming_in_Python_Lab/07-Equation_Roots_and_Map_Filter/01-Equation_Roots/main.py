#!/usr/bin/env python3

import math

import numpy as np

lexicon = "abcdefghijklmnopqrstuvwxyz"


def calculate_polynomial(coeffs: list[float, ...], x: float) -> float:
    sum: float = 0
    order: float = len(coeffs) - 1
    for i in range(0, len(coeffs)):
        sum += coeffs[i] * math.pow(x, order - i)

    return sum


def find_roots(coeffs: list[float, ...]) -> list[float, ...]:

    roots = np.roots(coeffs)

    # Filter for real roots
    real_roots = roots[np.isreal(roots)]

    return real_roots


def find_root_bisection(
    coeffs: list[float, ...],
    a: float,
    b: float,
    tolerance: float = 1e-6,
    max_iterations: int = 100,
) -> float:
    """
    Uses bisection method to find c such that f(c) = 0 where f(a) < 0 and f(b) > 0.

    Args:
        coeffs: Coefficients of the polynomial function
        a, b: Initial interval where f(a) < 0 and f(b) > 0
        tolerance: Acceptable error margin
        max_iterations: Maximum number of iterations

    Returns:
        c: Value where f(c) = 0
    """
    fa = calculate_polynomial(coeffs, a)
    fb = calculate_polynomial(coeffs, b)

    if fa * fb > 0:
        raise ValueError("Function must have opposite signs at a and b")

    for i in range(max_iterations):
        # Calculate midpoint
        c = (a + b) / 2
        fc = calculate_polynomial(coeffs, c)

        # Check if we've found the root within tolerance
        if abs(fc) < tolerance:
            return c

        # Update interval
        if fa * fc < 0:  # Root is in [a, c]
            b = c
            fb = fc
        else:  # Root is in [c, b]
            a = c
            fa = fc

    # Return best approximation after max iterations
    return (a + b) / 2


def main():
    n = int(input("Enter the order of the function: "))

    if n < 2 or n > 26:
        print("Order should be between 2 and 26")
        return

    fancy_polynomial_string = "f(x) = "
    for i in range(0, n + 1):
        fancy_polynomial_string += lexicon[i] + (f"x^{n-i} + " if i < n else "")

    coeffs = list(
        map(
            float,
            input(
                f"Enter the coeffiecients separated by spaces for the polynomial\n{fancy_polynomial_string}:\n"
            ).split(" "),
        )
    )
    if len(coeffs) != n + 1:
        print(
            f"Number of coefficients given does not satisfy the variables in the polynomial. Expected {n + 1}, given {len(coeffs)}"
        )
        return

    a = float(input("Enter the value of a for f(a): "))
    b = float(input("Enter the value of b for f(b): "))

    if not a < b:
        print(f"a should be lesser than b. Got: a = {a}, b = {b}")
        return

    fa = calculate_polynomial(coeffs, a)
    fb = calculate_polynomial(coeffs, b)

    print(f"f(a) = {fa} and f(b) = {fb}")

    if (not fa < 0) or (not fb > 0):
        print(
            f"f(a) needs to be less than 0, and f(b) needs to be greater than 0.\nReenter your coefficients\nGot: f(a) = {fa}, f(b) = {fb}; for a = {a}, b = {b}"
        )

    # Show all roots for reference
    roots = find_roots(coeffs)

    print(f"All real roots: {roots}")
    if len(roots) == 1:
        print("1 root only")
    elif not (np.min(roots) * np.max(roots) > 0):
        print(
            "Function's extreme roots do not have opposing signs. f(c) = 0 may or may not exist"
        )

    # Find the root using bisection method
    try:
        c = find_root_bisection(coeffs, a, b)
        print(f"Root found at c = {c}")
        print(f"f({c}) = {calculate_polynomial(coeffs, c)}")
    except ValueError as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
