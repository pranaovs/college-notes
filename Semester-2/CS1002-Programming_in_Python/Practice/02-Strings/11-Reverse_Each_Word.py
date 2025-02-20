#!/usr/bin/env python3


def reverse_words(input_string):
    words = input_string.split()
    reversed_words = [word[::-1] for word in words]
    return " ".join(reversed_words)


def main():
    user_input = input("Enter a string: ")
    result = reverse_words(user_input)
    print("Reversed words string:", result)


if __name__ == "__main__":
    main()
