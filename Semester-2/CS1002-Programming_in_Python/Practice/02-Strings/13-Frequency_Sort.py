#!/usr/bin/env python3


def sort_by_frequency(s):
    # Count the frequency of each character
    freq = {}
    for char in s:
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1
    # Sort characters by frequency and then alphabetically
    sorted_chars = sorted(freq, key=lambda x: (-freq[x], x))
    # Join the sorted characters into a single string
    return "".join(sorted_chars)


def main():
    # Get user input
    user_input = input("Enter a string: ")
    # Sort the string by character frequency
    sorted_string = sort_by_frequency(user_input)
    # Print the result
    print(f"Sorted string: {sorted_string}")


if __name__ == "__main__":
    main()
