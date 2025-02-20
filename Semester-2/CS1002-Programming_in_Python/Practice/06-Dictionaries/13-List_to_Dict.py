#!/usr/bin/env python3


def convert(input_dict):
    keys = list(input_dict.keys())
    length = len(input_dict[keys[0]])
    result = []

    for i in range(length):
        temp_dict = {}
        for key in keys:
            temp_dict[key] = input_dict[key][i]
        result.append(temp_dict)

    return result


def main():
    input_dict = {}

    # Get user input for the dictionary
    num_keys = int(input("Enter the number of keys: "))

    for _ in range(num_keys):
        key = input("Enter the key: ")
        values = input(f"Enter the list of values for {key} (comma-separated): ").split(
            ","
        )
        input_dict[key] = [int(value.strip()) for value in values]

    # Convert dictionary of lists to list of dictionaries
    result = convert(input_dict)

    # Print the result
    print(result)


if __name__ == "__main__":
    main()
