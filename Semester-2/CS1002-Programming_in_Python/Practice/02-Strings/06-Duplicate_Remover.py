#!/usr/bin/env python3


def character_frequency(word) -> dict[str, int]:
    frequency = {}
    for char in word:
        frequency[char] = frequency.get(char, 0) + 1

    return frequency


def remove_duplicates_string(word) -> str:
    return "".join(set(word))


def main():
    input_string = input("Enter a string: ")
    print("Frequency of characters in the string: ", character_frequency(input_string))
    print("String after removing duplicates: ", remove_duplicates_string(input_string))


if __name__ == "__main__":
    main()
