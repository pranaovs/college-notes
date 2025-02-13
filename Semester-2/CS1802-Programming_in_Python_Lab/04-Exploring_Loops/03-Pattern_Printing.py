#!/usr/bin/env python3


def print_pattern(n: int, padding: str = " ") -> None:

    for i in range(1, n + 1):

        print(padding * (n - i) + (str(i) + padding) * i)

    for i in range(n - 1, 0, -1):
        print(padding * (n - i) + (str(i) + padding) * i)


def main():
    inp: int = int(input("Enter N for the 2N-1 rows pattern: "))

    print_pattern(inp)


if __name__ == "__main__":
    main()
