#!/usr/bin/env python3


def combine_dicts(dict1, dict2):
    combined = dict1.copy()
    for key, value in dict2.items():
        if key in combined:
            combined[key] += value
        else:
            combined[key] = value
    return combined


def main():
    dict1 = {"a": 1, "b": 2, "c": 3}
    dict2 = {"b": 3, "c": 4, "d": 5}
    result = combine_dicts(dict1, dict2)
    print(result)


if __name__ == "__main__":
    main()
