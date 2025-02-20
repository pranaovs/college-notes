#!/usr/bin/env python3


def print_square(n):
    for i in range(n):
        for j in range(n):
            if i == 0 or i == n - 1 or j == 0 or j == n - 1 or i == j or i + j == n - 1:
                print(i + 1, end=" ")
            else:
                print(" ", end=" ")
        print()


def main():
    n = int(input("Enter the number of rows: "))
    print_square(n)


if __name__ == "__main__":
    main()
