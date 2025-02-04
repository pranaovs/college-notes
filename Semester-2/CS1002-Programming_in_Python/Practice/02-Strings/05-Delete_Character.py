#!/usr/bin/env python3


def delete_character(string, n):
    return string[:n] + string[n + 1 :]


def main():
    input_string = input("Enter a string: ")
    pos = int(input("Enter the position of the character to delete: "))

    if pos < 0 or pos >= len(input_string):
        print("Invalid position")
        exit(22)

    else:
        print("The new string is: ", delete_character(input_string, pos))


if __name__ == "__main__":
    main()
