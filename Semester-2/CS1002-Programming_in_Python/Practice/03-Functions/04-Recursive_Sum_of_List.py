#!/usr/bin/env python3


def sum_of_list(lst: list[int]) -> int:
    if len(lst) == 0:
        return 0
    return lst[0] + sum_of_list(lst[1:])


def main():
    lst = list(
        map(int, input("Enter the elements of the list separated by space: ").split())
    )
    print(sum_of_list(lst))


if __name__ == "__main__":
    main()
