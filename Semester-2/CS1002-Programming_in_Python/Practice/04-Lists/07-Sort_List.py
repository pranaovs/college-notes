#!/usr/bin/env python3


def sort_nested_list(nested_list):
    return sorted(nested_list, key=lambda x: x[-1])


def main():
    user_input = input("Enter a nested list (e.g., [[1,2], [3,4,5], [1,1], [3,4,9]]): ")
    nested_list = [
        list(map(int, item.strip("[]").split(",")))
        for item in user_input.strip("[]").split("],[")
    ]
    sorted_list = sort_nested_list(nested_list)
    print("Sorted list:", sorted_list)


if __name__ == "__main__":
    main()
