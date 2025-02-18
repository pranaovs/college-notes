#!/usr/bin/env python3


def char_freq(inp: str) -> tuple[str, int]:

    if not inp:
        return "", 0
    freq = {}
    for char in inp:
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1
    max_char = max(freq, key=lambda k: freq[k])
    return max_char, freq[max_char]


def main():
    input_str: str = str(
        input("Enter the string to find the highest repetiting character: ")
    )
    max_char, freq = char_freq(input_str)
    print(f"Character {max_char} is repeated {freq} times")


if __name__ == "__main__":
    main()
