#!/usr/bin/env python3


def split_string(input_string, n):
    return [input_string[i : i + n] for i in range(0, len(input_string), n)]


def main():
    input_string = input("Enter the string: ")
    n = int(input("Enter the number of characters per line: "))
    result = split_string(input_string, n)
    for line in result:
        print(line)


if __name__ == "__main__":
    main()
