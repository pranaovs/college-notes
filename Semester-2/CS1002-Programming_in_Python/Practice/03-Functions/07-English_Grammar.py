#!/usr/bin/env python3


def add_suffix(word):
    if len(word) > 3:
        if word.endswith("ing"):
            return word + "ly"
        else:
            return word + "ing"
    return word


def main():
    test_words = ["play", "playing", "do", "go"]
    for word in test_words:
        print(f"{word} -> {add_suffix(word)}")


if __name__ == "__main__":
    main()
