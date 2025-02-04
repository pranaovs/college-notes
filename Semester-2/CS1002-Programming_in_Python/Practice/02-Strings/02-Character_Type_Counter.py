#!/usr/bin/env python3


def count_char_types(text) -> dict[str, int]:
    upper: int = 0
    lower: int = 0
    digits: int = 0
    special: int = 0
    space: int = 0

    for char in text:
        if char.isupper():
            upper += 1
        elif char.islower():
            lower += 1
        elif char.isdigit():
            digits += 1
        elif char.isspace():
            space += 1
        else:
            special += 1

    return {
        "upper": upper,
        "lower": lower,
        "digits": digits,
        "special": special,
        "space": space,
    }


def main():
    text = input("Enter a string: ")
    char_types = count_char_types(text)
    print(f"Uppercase: {char_types['upper']}")
    print(f"Lowercase: {char_types['lower']}")
    print(f"Digits: {char_types['digits']}")
    print(f"Special: {char_types['special']}")
    print(f"Spaces: {char_types['space']}")


if __name__ == "__main__":
    main()
