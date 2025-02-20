#!/usr/bin/env python3


def rename_key(d, old_key, new_key):
    if old_key in d:
        d[new_key] = d.pop(old_key)
    return d


def main():
    # Get dictionary input from user
    user_input = input("Enter dictionary items (key:value pairs separated by commas): ")
    my_dict = dict(item.split(":") for item in user_input.split(","))

    print("Original dictionary:", my_dict)

    old_key = input("Enter the key to rename: ")
    new_key = input("Enter the new key name: ")

    updated_dict = rename_key(my_dict, old_key, new_key)
    print("Updated dictionary:", updated_dict)


if __name__ == "__main__":
    main()
