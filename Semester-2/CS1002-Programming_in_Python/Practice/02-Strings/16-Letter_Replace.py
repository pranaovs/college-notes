#!/usr/bin/env python3


def replace_first_letter(sentence):
    words = sentence.split()
    new_words = []
    for word in words:
        if word[0].isalpha():
            new_letter = chr(ord(word[0]) + 1)
            new_word = new_letter + word[1:]
        else:
            new_word = word
        new_words.append(new_word)
    return " ".join(new_words)


if __name__ == "__main__":
    user_input = input("Enter a sentence: ")
    result = replace_first_letter(user_input)
    print(result)
