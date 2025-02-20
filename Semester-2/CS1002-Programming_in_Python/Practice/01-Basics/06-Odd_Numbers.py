#!/usr/bin/env python3


def get_odd_numbers(numbers):
    return [num for num in numbers if num % 2 != 0]


def main():
    numbers = list(map(int, input("Enter numbers separated by space: ").split()))

    odd_numbers = get_odd_numbers(numbers)
    print("Odd numbers:", ", ".join(map(str, odd_numbers)))


if __name__ == "__main__":
    main()
