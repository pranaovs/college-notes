#!/usr/bin/env python3


def capitalize_words(sentence):
    return " ".join(word.capitalize() for word in sentence.split())


def main():
    user_input = input("Enter a sentence: ")
    capitalized_sentence = capitalize_words(user_input)
    print(capitalized_sentence)


if __name__ == "__main__":
    main()
