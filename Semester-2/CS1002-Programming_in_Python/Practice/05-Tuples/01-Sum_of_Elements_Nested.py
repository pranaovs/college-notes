#!/usr/bin/env python3


def sum_of_tuple(tpl: tuple[int, ...]) -> int:

    return sum(i for i in tpl)


def main():
    input_str = input(
        "Enter the list of tuples with lists separated by spaces and tuple elements separated by comma: "
    )
    lst = [tuple(map(int, t.split(","))) for t in input_str.split()]

    result = [sum_of_tuple(t) for t in lst]

    print(result)


if __name__ == "__main__":
    main()
