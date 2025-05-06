#!/usr/bin/env python3


def is_Palindromic(s: str) -> bool:
    return s == s[::-1]


def get_substrings(s: str) -> list:
    return [s[i:j] for i in range(len(s)) for j in range(i + 2, len(s) + 1)]


def main():
    inp_str = str(input("Enter a string: "))

    substrings = get_substrings(inp_str)
    for substr in substrings:
        if is_Palindromic(substr):
            print(substr)


if __name__ == "__main__":
    main()
