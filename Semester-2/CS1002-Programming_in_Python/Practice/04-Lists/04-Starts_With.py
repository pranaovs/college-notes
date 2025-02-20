#!/usr/bin/env python3


def find_items_starting_with(char, items):
    return [item for item in items if item.startswith(char)]


def main():
    items = input("Enter a list of items separated by commas: ").strip().split(",")
    items = [item.strip() for item in items]
    char = input("Enter the character to search for: ").strip()
    if len(char) != 1:
        print("Please enter a single character.")
        return

    result = find_items_starting_with(char, items)
    print(f"Items starting with '{char}': {result}")


if __name__ == "__main__":
    main()
