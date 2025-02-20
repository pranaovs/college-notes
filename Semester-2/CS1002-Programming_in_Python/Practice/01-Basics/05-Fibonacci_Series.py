#!/usr/bin/env python3


def generate_fibonacci(n):
    fib_series = [0, 1]
    while len(fib_series) < n:
        fib_series.append(fib_series[-1] + fib_series[-2])
    return fib_series[:n]


def main():
    try:
        n = int(input("Enter the value of N: "))
        if n <= 0:
            print("Please enter a positive integer.")
        else:
            fib_series = generate_fibonacci(n)
            print(f"Fibonacci series up to {n}: {fib_series}")
    except ValueError:
        print("Invalid input. Please enter an integer.")


if __name__ == "__main__":
    main()
