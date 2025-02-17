#!/usr/bin/env python3


def generate_dict(n):
    result = {x: x**2 / 4 for x in range(1, n + 1)}
    return result


def main():
    n = int(input("Enter a number: "))
    result_dict = generate_dict(n)
    print(result_dict)


if __name__ == "__main__":
    main()
