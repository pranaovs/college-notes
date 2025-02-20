#!/usr/bin/env python3


def remove_consecutive_duplicates(input_list):
    if not input_list:
        return []

    result = [input_list[0]]
    for item in input_list[1:]:
        if item != result[-1]:
            result.append(item)
    return result


def main():
    user_input = input("Enter a list of numbers separated by spaces: ")
    input_list = list(map(int, user_input.split()))
    result = remove_consecutive_duplicates(input_list)
    print("List after removing consecutive duplicates:", result)


if __name__ == "__main__":
    main()
