#!/usr/bin/env python3


def is_symmetric(lst: list[int]) -> bool:
    """
    This function takes a list of numbers and returns True if the list is symmetric, False otherwise.
    A list is symmetric if the sum of first half of the list is equal to the sum of the second half of the list.
    """

    first_half = lst[: len(lst) // 2 + (1 if len(lst) % 2 != 0 else 0)]
    last_half = lst[len(lst) // 2 :]

    return sum(first_half) == sum(last_half)


def main():
    lst = list(map(int, input("Enter list of numbers separated by space: ").split()))

    print("The list {} symmetric".format("is" if is_symmetric(lst) else "is not"))


if __name__ == "__main__":
    main()
