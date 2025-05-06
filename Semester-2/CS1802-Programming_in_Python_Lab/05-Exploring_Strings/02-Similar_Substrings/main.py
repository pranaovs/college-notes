#!/usr/bin/env python3


def similar_substring(s1: str) -> bool:
    return s1[0] == s1[-1]


def get_substrings(s: str) -> list:
    return [s[i:j] for i in range(len(s)) for j in range(i + 2, len(s) + 1)]


def main():
    inp_str1 = str(input("Enter a string: "))

    substrings = get_substrings(inp_str1)
    print("Substrings with same starting and ending characters are:")
    for substr in substrings:
        print(substr) if similar_substring(substr) else None


if __name__ == "__main__":
    main()
