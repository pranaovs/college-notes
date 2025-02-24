#!/usr/bin/env python3


def cipher(s: str, k: int) -> str:
    final_str = ""

    for i in range(len(s)):

        if s[i].isalpha():
            shift = k % 26
            final_str += chr((ord(s[i]) + shift - 97) % 26 + 97)
        else:
            final_str += s[i]

    return final_str


def main():
    inp_str = str(input("Enter a string: "))
    shift = int(input("Enter the shift value: "))

    print(cipher(inp_str, shift))


if __name__ == "__main__":
    main()
