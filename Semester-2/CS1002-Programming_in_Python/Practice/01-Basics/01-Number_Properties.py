#!/usr/bin/env python3


def calculate_sum(numbers):
    return sum(numbers)


def calculate_mean(numbers):
    return sum(numbers) / len(numbers)


def calculate_max(numbers):
    return max(numbers)


def calculate_min(numbers):
    return min(numbers)


def main():
    numbers = list(map(int, input("Enter 3 numbers separated by a space: ").split(" ")))

    if len(numbers) != 3:
        print(f"{len(numbers)} given. Expected 3 numbers")
        return

    total_sum = calculate_sum(numbers)
    mean_value = calculate_mean(numbers)
    max_value = calculate_max(numbers)
    min_value = calculate_min(numbers)

    print(f"Sum: {total_sum}")
    print(f"Mean: {mean_value}")
    print(f"Maximum: {max_value}")
    print(f"Minimum: {min_value}")


if __name__ == "__main__":
    main()
