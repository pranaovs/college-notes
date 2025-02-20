#!/usr/bin/env python3


def is_valid_name(name):
    return name.isalpha()


def get_name():
    first_name = input("Enter your first name: ").strip()
    middle_name = input("Enter your middle name (optional): ").strip()
    last_name = input("Enter your last name: ").strip()

    if not is_valid_name(first_name) or not is_valid_name(last_name):
        print("Enter a valid name")
    else:
        print("Name is valid")


if __name__ == "__main__":
    get_name()
