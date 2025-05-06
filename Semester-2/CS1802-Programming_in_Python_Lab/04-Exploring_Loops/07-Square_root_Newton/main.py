#!/usr/bin/env python3


def square_root(num: float, limit: float = 0.00001) -> float:

    tmpnum = num
    root = 1

    while True:

        root = 0.5 * (tmpnum + (num / tmpnum))

        if abs(root - tmpnum) < limit:
            break

        tmpnum = root

    return root


def main():
    num, limit = map(
        float,
        input("Enter the number to find sqrt and limit separated by a space: ").split(),
    )

    print(f"The square root of {num} is {square_root(num, limit)}")


if __name__ == "__main__":
    main()
