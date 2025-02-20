#!/usr/bin/env python3


def sort_dict_by_keys(input_dict):
    return dict(sorted(input_dict.items()))


def main():
    user_input = input("Enter a dictionary (e.g., {'a': 1, 'c': 3, 'b': 2}): ")
    try:
        input_dict = eval(user_input)
        if not isinstance(input_dict, dict):
            raise ValueError
    except:
        print("Invalid input. Please enter a valid dictionary.")
        return

    sorted_dict = sort_dict_by_keys(input_dict)
    print("Sorted dictionary:", sorted_dict)


if __name__ == "__main__":
    main()
