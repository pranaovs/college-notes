#!/usr/bin/env python3


def main():
    user_string = input("Enter a string: ")
    char_to_replace = input("Enter the character to replace: ")
    replacement_char = input("Enter the replacement character: ")

    new_string = user_string.replace(char_to_replace, replacement_char)
    print("Modified string:", new_string)


if __name__ == "__main__":
    main()
