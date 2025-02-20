#!/usr/bin/env python3


def find_flavors(costs, money):
    cost_map = {}
    for i, cost in enumerate(costs):
        if money - cost in cost_map:
            return cost_map[money - cost] + 1, i + 1
        cost_map[cost] = i
    return None


def main():
    money = int(input("How much money do Sunny and Johnny have in total? "))
    n = int(input("How many flavors are available? "))
    costs = []
    for i in range(n):
        cost = int(input(f"Enter the cost of flavor {i + 1}: "))
        costs.append(cost)

    result = find_flavors(costs, money)
    if result:
        print(f"The indices of the two flavors are: {result[0]} and {result[1]}")
    else:
        print("No two flavors match the given amount.")


if __name__ == "__main__":
    main()
