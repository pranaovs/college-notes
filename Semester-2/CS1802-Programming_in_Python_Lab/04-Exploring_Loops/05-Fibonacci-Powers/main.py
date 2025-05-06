#!/usr/bin/env python3


def fibonacci(until: int) -> tuple:

    series = list[int]()
    a = 1
    b = 1
    for i in range(1, until + 1):

        if i == 1:
            a, b = 1, 1
        else:
            a, b = b, a + b
        series.append(a)

    return tuple(series)


def main():
    num = int(input("Enter a number: "))

    sum = 0
    series = fibonacci(num)
    for i in range(0, num):
        sign = +1 if i % 2 == 0 else -1
        sum += (sign) * (series[i] ** (i + 1))

    print(f"The sum of the series is: {sum}")


if __name__ == "__main__":
    main()
