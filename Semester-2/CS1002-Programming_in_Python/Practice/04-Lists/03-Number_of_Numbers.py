#!/usr/bin/env python3


def calculate_fractions(numbers):
    total_count = len(numbers)
    positive_count = sum(1 for x in numbers if x > 0)
    negative_count = sum(1 for x in numbers if x < 0)
    zero_count = sum(1 for x in numbers if x == 0)

    positive_fraction = positive_count / total_count
    negative_fraction = negative_count / total_count
    zero_fraction = zero_count / total_count

    return positive_fraction, negative_fraction, zero_fraction


def main():
    numbers = list(map(int, input("Enter the numbers separated by space: ").split()))
    positive_fraction, negative_fraction, zero_fraction = calculate_fractions(numbers)

    print(f"Positive fraction: {positive_fraction:.3f}")
    print(f"Negative fraction: {negative_fraction:.3f}")
    print(f"Zero fraction: {zero_fraction:.3f}")


if __name__ == "__main__":
    main()
