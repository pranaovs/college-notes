#!/usr/bin/env python3


def count_words(input_string):
    words = input_string.split()
    return len(words)


def main():
    user_input = input("Enter a string: ")
    word_count = count_words(user_input)
    print(f"Number of words: {word_count}")


if __name__ == "__main__":
    main()
