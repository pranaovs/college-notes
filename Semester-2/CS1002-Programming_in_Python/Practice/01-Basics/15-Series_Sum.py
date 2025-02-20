#!/usr/bin/env python3


def sum_of_natural_numbers(n):
    return n * (n + 1) // 2


def sum_of_series(N):
    total_sum = 0
    for i in range(1, N + 1):
        total_sum += sum_of_natural_numbers(i)
    return total_sum


def main():
    N = int(input("Enter the number of elements in the series: "))
    result = sum_of_series(N)
    print(f"The sum of the series is: {result}")


if __name__ == "__main__":
    main()
