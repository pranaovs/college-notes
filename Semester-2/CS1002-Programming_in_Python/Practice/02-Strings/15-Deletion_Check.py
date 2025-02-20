#!/usr/bin/env python3


def can_be_made_empty(s, sub):
    while sub in s:
        s = s.replace(sub, "")
    return s == ""


def main():
    s = input("Enter the main string: ")
    sub = input("Enter the substring to delete: ")
    if can_be_made_empty(s, sub):
        print("The string can be made empty by recursively deleting the substring.")
    else:
        print("The string cannot be made empty by recursively deleting the substring.")


if __name__ == "__main__":
    main()
