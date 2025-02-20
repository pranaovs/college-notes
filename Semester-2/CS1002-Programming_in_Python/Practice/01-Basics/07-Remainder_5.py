#!/usr/bin/env python3


def find_numbers_with_remainder(n, m):
    numbers = [i for i in range(1, n + 1) if i % m == 5]
    return numbers


def compute_average(numbers):
    if not numbers:
        return 0
    return sum(numbers) / len(numbers)


def main():
    n = int(input("Enter the value of N: "))
    m = int(input("Enter the value of M: "))

    numbers = find_numbers_with_remainder(n, m)
    count = len(numbers)
    average = compute_average(numbers)

    print(f"Numbers: {numbers}")
    print(f"Count: {count}")
    print(f"Average: {average}")


if __name__ == "__main__":
    main()
