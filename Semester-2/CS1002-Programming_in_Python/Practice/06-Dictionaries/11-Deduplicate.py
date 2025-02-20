#!/usr/bin/env python3


def remove_duplicates(input_dict):
    seen_values = set()
    result_dict = {}
    for key, value in input_dict.items():
        if value not in seen_values:
            seen_values.add(value)
            result_dict[key] = value
    return result_dict


def main():
    user_input = input("Enter a dictionary (e.g., {'a': 1, 'b': 2, 'c': 1}): ")
    try:
        input_dict = eval(user_input)
        if not isinstance(input_dict, dict):
            raise ValueError
    except:
        print("Invalid input. Please enter a valid dictionary.")
        return

    result_dict = remove_duplicates(input_dict)
    print("Dictionary after removing duplicates:", result_dict)


if __name__ == "__main__":
    main()
