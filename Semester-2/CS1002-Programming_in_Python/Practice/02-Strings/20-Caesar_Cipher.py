#!/usr/bin/env python3


def caesar_cipher(text, shift):
    result = ""
    for char in text:
        if char.isalpha():
            shift_amount = 65 if char.isupper() else 97
            result += chr((ord(char) - shift_amount + shift) % 26 + shift_amount)
        else:
            result += char
    return result


def main():
    text = input("Enter the text to be encrypted: ")
    shift = int(input("Enter the shift value: "))
    encrypted_text = caesar_cipher(text, shift)
    print(f"Encrypted text: {encrypted_text}")


if __name__ == "__main__":
    main()
