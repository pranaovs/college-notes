#!/usr/bin/env python3


def find_tuples(numbers):
    product_map = {}
    result = []

    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):
            product = numbers[i] * numbers[j]
            if product in product_map:
                for a, b in product_map[product]:
                    if (
                        a != numbers[i]
                        and a != numbers[j]
                        and b != numbers[i]
                        and b != numbers[j]
                    ):
                        result.append((a, b, numbers[i], numbers[j]))
            else:
                product_map[product] = []
            product_map[product].append((numbers[i], numbers[j]))

    return result


def main():
    user_input = input(
        "Enter a list of distinct positive integers separated by spaces: "
    )
    numbers = list(map(int, user_input.split()))
    tuples = find_tuples(numbers)
    for t in tuples:
        print(t)


if __name__ == "__main__":
    main()
