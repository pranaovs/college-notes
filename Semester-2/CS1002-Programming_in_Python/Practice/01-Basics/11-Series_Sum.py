#!/usr/bin/env python3


def series_sum(x, N):
    sum = 0
    for i in range(N):
        term = x ** (2 * i + 1)
        if i % 2 == 0:
            sum += term
        else:
            sum -= term
    return sum


def main():
    x = float(input("Enter the value of x: "))
    N = int(input("Enter the number of terms N: "))
    result = series_sum(x, N)
    print(f"The sum of the series up to {N} terms is: {result}")


if __name__ == "__main__":
    main()
