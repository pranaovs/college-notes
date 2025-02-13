#!/usr/bin/env python3


def table(m: int, n: int) -> tuple:
    multilpication_table: list[int] = list()
    for i in range(0, int(n) + 1):
        multilpication_table.append(m * i)

    return tuple(multilpication_table)


def main():
    m, n = map(
        int,
        input(
            "Enter the numbers you want the multiplication table for in the form of mxn: "
        ).split("x"),
    )

    result = table(m, n)

    for i in range(0, n + 1):
        print(f"{m} x {i} = {result[i]}")


if __name__ == "__main__":
    main()
