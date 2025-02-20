#!/usr/bin/env python3


def remove_duplicates(list_of_lists):
    unique_lists = []
    for lst in list_of_lists:
        if lst not in unique_lists:
            unique_lists.append(lst)
    return unique_lists


def parse_input(input_str):
    input_str = input_str.strip()[1:-1]  # Remove the outer brackets
    list_of_lists = []
    for sublist in input_str.split("], ["):
        sublist = sublist.replace("[", "").replace("]", "")
        list_of_lists.append([int(x) for x in sublist.split(", ")])
    return list_of_lists


def main():
    input_str = input(
        "Enter a list of lists (e.g., [[10, 20], [40], [30, 56, 25], [10, 20], [33], [40]]): "
    )
    input_list = parse_input(input_str)
    result = remove_duplicates(input_list)
    print("Output:", result)


if __name__ == "__main__":
    main()
