#!/usr/bin/env python3


def combine_lists_to_dict(keys, values):
    combined_dict = {}
    for i in range(len(keys)):
        combined_dict[keys[i]] = values[i]
    return combined_dict


def main():
    list1 = input("Enter the first list of keys (comma-separated): ").split(",")
    list2 = input("Enter the second list of values (comma-separated): ").split(",")

    if len(list1) != len(list2):
        print("Error: Both lists must be of the same length.")
        return

    combined_dict = combine_lists_to_dict(list1, list2)
    print(combined_dict)


if __name__ == "__main__":
    main()
