#!/usr/bin/env python3


def count_substrings(s, char):
    n = len(s)
    count = 0
    for i in range(n):
        for j in range(i, n):
            if s[i] == char and s[j] == char:
                count += 1
    return count


def main():
    user_input = input("Enter a string: ")
    char = input("Enter the character to check for substrings: ")
    result = count_substrings(user_input, char)
    print(
        f"Number of substrings with the character '{char}' as the first and last character: {result}"
    )


if __name__ == "__main__":
    main()
