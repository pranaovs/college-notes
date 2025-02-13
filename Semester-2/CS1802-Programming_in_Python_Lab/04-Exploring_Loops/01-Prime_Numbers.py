#!/usr/bin/env python3

import math


def is_prime(num: int) -> bool:
    if num <= 1:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True


def main():
    inp = input("Enter a number to find primes until it: ")

    for i in range(2, int(inp)):
        if is_prime(i):
            print(i, end=" ")
    print()


if __name__ == "__main__":
    main()
