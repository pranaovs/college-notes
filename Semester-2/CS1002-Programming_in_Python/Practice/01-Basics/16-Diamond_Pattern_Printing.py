#!/usr/bin/env python3


def print_diamond(n):
    # Upper part of the diamond
    for i in range(1, n + 1):
        print(" " * (n - i) + " ".join(str(x) for x in range(1, i + 1)))

    # Lower part of the diamond
    for i in range(n - 1, 0, -1):
        print(" " * (n - i) + " ".join(str(x) for x in range(1, i + 1)))


def main():
    try:
        n = int(input("Enter the value of N: "))
        if n <= 0:
            print("Please enter a positive integer.")
        else:
            print_diamond(n)
    except ValueError:
        print("Invalid input. Please enter an integer.")


if __name__ == "__main__":
    main()
