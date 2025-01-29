#!./.venv/bin/python3


from spellcheck import SpellChecker


class AutoComplete(SpellChecker):

    def __init__(self, filename: str = "words.txt"):
        SpellChecker.__init__(self, filename)

    def autocomplete_candidates(self, prefix: str):

        candidates: set = set()

        corrected_prefix: set = self.candidates(prefix)

        for word in corrected_prefix:
            for dict_word in self.wordlist:
                if dict_word.startswith(word):
                    candidates.add(dict_word)

        return candidates


def main():
    AC = AutoComplete("words.txt")

    print("Enter a prefix: ")

    while True:
        prefix = input()
        if prefix == "exit":
            break
        candidates = AC.autocomplete_candidates(prefix)
        print(f"Autocomplete suggestions for {prefix}: {candidates}")


if __name__ == "__main__":
    main()
