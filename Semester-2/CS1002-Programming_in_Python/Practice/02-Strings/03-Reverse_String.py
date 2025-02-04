#!/usr/bin/env python3


def reverse_string(word) -> str:
    return word[::-1]


def main():
    input_word = input("Enter a word: ")
    print(reverse_string(input_word))


if __name__ == "__main__":
    main()
