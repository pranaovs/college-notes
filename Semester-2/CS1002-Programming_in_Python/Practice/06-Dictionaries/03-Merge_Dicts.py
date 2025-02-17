#!/usr/bin/env python3


def combine_dicts(dict1, dict2):
    combined_dict = dict1.copy()  # Start with a copy of the first dictionary
    combined_dict.update(dict2)  # Update with the second dictionary
    return combined_dict


def main():
    dict1 = {"a": 1, "b": 2, "c": 3}
    dict2 = {"b": 4, "d": 5}

    combined_dict = combine_dicts(dict1, dict2)
    print("Combined Dictionary:", combined_dict)


if __name__ == "__main__":
    main()
