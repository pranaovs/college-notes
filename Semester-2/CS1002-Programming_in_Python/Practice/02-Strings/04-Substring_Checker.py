#!/usr/bin/env python3


def substring_checker(string, substring):
    if substring in string:
        return True
    else:
        return False


def main():
    input_string = input("Enter a string: ")
    substring = input("Enter a substring: ")

    print(
        f"The substring {substring} is {'' if substring_checker(input_string, substring) else 'not '}present in the string {input_string}."
    )


if __name__ == "__main__":
    main()
