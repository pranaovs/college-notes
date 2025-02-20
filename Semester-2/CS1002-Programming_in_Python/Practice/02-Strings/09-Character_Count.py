#!/usr/bin/env python3


def find_odd_characters(s):
    char_count = {}
    for char in s:
        if char in char_count:
            char_count[char] += 1
        else:
            char_count[char] = 1
    odd_chars = [char for char, count in char_count.items() if count % 2 != 0]
    return odd_chars


def main():
    odd_characters = find_odd_characters(input("Enter the string: "))
    print("Characters that appear an odd number of times:", odd_characters)


if __name__ == "__main__":
    main()
