#!/usr/bin/env python3

import cmath


def get_complex_number(real, imag):
    return complex(real, imag)


def perform_operations(c1, c2):
    print(f"Addition: {c1} + {c2} = {c1 + c2}")
    print(f"Subtraction: {c1} - {c2} = {c1 - c2}")
    print(f"Multiplication: {c1} * {c2} = {c1 * c2}")
    print(f"Division: {c1} / {c2} = {c1 / c2}")


def get_magnitude_and_phase(c):
    magnitude = abs(c)
    phase = cmath.phase(c)
    return magnitude, phase


def main():
    real1 = float(input("Enter the real part of the first complex number: "))
    imag1 = float(input("Enter the imaginary part of the first complex number: "))
    real2 = float(input("Enter the real part of the second complex number: "))
    imag2 = float(input("Enter the imaginary part of the second complex number: "))

    c1 = get_complex_number(real1, imag1)
    c2 = get_complex_number(real2, imag2)

    print(f"First complex number: {c1}")
    print(f"Second complex number: {c2}")

    perform_operations(c1, c2)

    mag1, phase1 = get_magnitude_and_phase(c1)
    mag2, phase2 = get_magnitude_and_phase(c2)

    print(f"Magnitude and phase of the first complex number: {mag1}, {phase1}")
    print(f"Magnitude and phase of the second complex number: {mag2}, {phase2}")


if __name__ == "__main__":
    main()
