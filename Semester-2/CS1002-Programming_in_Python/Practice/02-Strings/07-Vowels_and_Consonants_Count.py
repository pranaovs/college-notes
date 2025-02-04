#!/usr/bin/env python3

vowels = "aeiou"


def vowel_count(input_string: str) -> int:
    input_string = input_string.replace(" ", "").lower()
    return len([char for char in input_string if char in vowels])


def consonant_count(input_string: str) -> int:
    input_string = input_string.replace(" ", "").lower()
    return len([char for char in input_string if char not in vowels])


def main():
    input_string = input("Enter a string: ")

    for char in input_string:
        if not (char.isalpha() or char.isspace()):
            print("Invalid input")
            exit(22)

    print(f"Vowels: {vowel_count(input_string)}")
    print(f"Consonants: {consonant_count(input_string)}")


if __name__ == "__main__":
    main()
