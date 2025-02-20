#!/usr/bin/env python3


def rotate_string(s, n):
    return s[n:] + s[:n]


def get_rotated_strings(strings, n):
    return [rotate_string(s, n) for s in strings]


def main():
    strings = input("Enter a list of strings separated by commas: ").split(",")
    n = int(input("Enter the number of rotations: "))
    rotated_strings = get_rotated_strings(strings, n)
    print("Rotated strings:", rotated_strings)


if __name__ == "__main__":
    main()
