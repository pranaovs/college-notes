#!/usr/bin/env python3


def sum_of_digits(num: int) -> int:
    sum: int = 0

    tmpnum = int(num)
    while tmpnum != 0:
        sum += tmpnum % 10
        tmpnum //= 10

    return sum


def main():
    num = int(input("Enter a number to find the sum of its digits: "))

    print(f"Sum of digits of {num} is {sum_of_digits(num)}")


if __name__ == "__main__":
    main()
