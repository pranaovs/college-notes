#!/usr/bin/env python3


def reverse_words(sentence):
    words = sentence.split()
    reversed_sentence = " ".join(reversed(words))
    return reversed_sentence


def list_unique_characters(sentence):
    unique_chars = "".join(sorted(set(sentence)))
    return unique_chars


def word_and_char_count(sentence):
    word_count = len(sentence.split())
    char_count = len(sentence)
    return word_count, char_count


def contains_substring(sentence, substring="ace"):
    return substring in sentence


def encode_string(sentence):
    encoded_chars = []
    for i, char in enumerate(sentence):
        if i % 2 == 0:
            new_char = sentence[(i + 1) % len(sentence)]
        else:
            new_char = sentence[(i + 2) % len(sentence)]
        encoded_chars.append(new_char)
    return "".join(encoded_chars)


def main():
    while True:
        print("\nMenu:")
        print("1. Reverse the sequence of words in the sentence")
        print("2. List the characters in the string, without duplicates")
        print("3. Find the word count and character count (including spaces)")
        print("4. Check if the string contains a given substring")
        print("5. Encode the string")
        print("6. Exit")

        choice = input("Enter your choice: ")

        if choice == "6":
            print("Exiting...")
            break

        sentence = input("Enter the sentence: ")

        if choice == "1":
            print("Reversed sentence:", reverse_words(sentence))
        elif choice == "2":
            print("Unique characters:", list_unique_characters(sentence))
        elif choice == "3":
            word_count, char_count = word_and_char_count(sentence)
            print(f"Word count: {word_count}, Character count: {char_count}")
        elif choice == "4":
            substring = input("Enter the substring (default is 'ace'): ")
            if not substring:
                substring = "ace"
            print(f"Contains '{substring}':", contains_substring(sentence, substring))
        elif choice == "5":
            print("Encoded string:", encode_string(sentence))
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()
