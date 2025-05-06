#!/usr/bin/env python3


class SpellChecker:

    wordlist = []

    def __init__(self, filename: str = "words.txt"):
        """Initializes the SpellChecker object with a wordlist"""
        with open(filename, "r") as file:
            self.wordlist = file.read().strip().split("\n")

    def replace1(self, word: str):
        """Returns a list of all permutations of word which are 1 edit away from being word"""
        lexicon = "abcdefghijklmnopqrstuvwxyz"

        word = word.lower()
        wordlist = []

        # Insertion
        for i in range(len(word) + 1):
            for char in lexicon:
                new_word = word[:i] + char + word[i:]
                wordlist.append(new_word)

        # Deletion
        for i in range(len(word)):
            new_word = word[:i] + word[i + 1 :]
            wordlist.append(new_word)

        for i in range(len(word)):
            # Substitution
            for char in lexicon:
                new_word = word[:i] + char + word[i + 1 :]
                wordlist.append(new_word)

        return wordlist

    def replace2(self, word: str):
        """Returns permutations 2 edits away"""
        one_edit = self.replace1(word)
        two_edits = []
        for w in one_edit:
            two_edits.extend(self.replace1(w))
        return list(set(two_edits))  # Remove duplicates

    def known(self, combination: list) -> set:
        return set(w for w in combination if w in self.wordlist)

    def candidates(self, word: str) -> set:
        return (
            self.known([word])
            or self.known(self.replace1(word))
            or self.known(self.replace2(word))
            or {word}
        )


def main():
    checker = SpellChecker("words.txt")

    sentence = "Hello my neme is Jhon and I am a progrmmer i am aso a goud speler"

    for word in sentence.split():
        print(word, "->", checker.candidates(word))


if __name__ == "__main__":
    main()
