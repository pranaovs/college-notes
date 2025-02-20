#!/usr/bin/env python3


def sort_string(s):
    return "".join(sorted(s))


def main():
    input_string = input("Enter a string: ")
    sorted_string = sort_string(input_string)
    print(f"Sorted string: {sorted_string}")


if __name__ == "__main__":
    main()
