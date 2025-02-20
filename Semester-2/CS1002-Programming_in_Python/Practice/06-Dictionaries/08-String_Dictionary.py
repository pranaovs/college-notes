#!/usr/bin/env python3


def get_char_count(s):
    char_count = {}
    for char in s:
        if char in char_count:
            char_count[char] += 1
        else:
            char_count[char] = 1
    return char_count


def main():
    user_input = input("Enter a string: ")
    char_count_dict = get_char_count(user_input)
    print(char_count_dict)


if __name__ == "__main__":
    main()
