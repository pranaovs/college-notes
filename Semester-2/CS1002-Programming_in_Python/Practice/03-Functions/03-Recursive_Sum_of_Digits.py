#!/usr/bin/env python3


def sum_of_digits(n):
    if n == 0:
        return 0
    return n % 10 + sum_of_digits(n // 10)


def main():
    n = int(input("Enter a number to find the sum of its digits: "))
    print(sum_of_digits(n))


if __name__ == "__main__":
    main()
