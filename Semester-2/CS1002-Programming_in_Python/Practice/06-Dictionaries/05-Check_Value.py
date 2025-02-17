#!/usr/bin/env python3


def find_keys_with_value(user_dict, value_to_check):
    keys_with_value = [
        key for key, value in user_dict.items() if value == value_to_check
    ]
    return keys_with_value


def main():
    user_input = input("Enter dictionary items (key:value) separated by commas: ")
    user_dict = dict(item.split(":") for item in user_input.split(","))
    value_to_check = input("Enter the value to check: ")

    keys_with_value = find_keys_with_value(user_dict, value_to_check)

    if keys_with_value:
        print(f"Keys with value '{value_to_check}': {', '.join(keys_with_value)}")
    else:
        print(f"No keys found with value '{value_to_check}'")


if __name__ == "__main__":
    main()
