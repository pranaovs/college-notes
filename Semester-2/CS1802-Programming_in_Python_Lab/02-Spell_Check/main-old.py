#!./.venv/bin/python3


class SpellChecker:

    wordlist = []

    def load_words(self, filename: str):
        with open(filename, "r") as file:
            self.wordlist = file.read().strip().split("\n")

    def resembelance_factor(self, word, dictword):
        word = word.lower()
        dictword = dictword.lower()

        max_points: float = 100
        points: float = 0

        if word == dictword:
            points = max_points
            return points

        # 50% of the points for length similarity
        if len(word) == len(dictword):
            points += 0.5 * max_points

        elif abs(len(word) - len(dictword)) < 1:
            points += 0.25 * max_points

        elif abs(len(word) - len(dictword)) < 2:
            points += 0.175 * max_points

        # 25% of the points for first and last letter similarity
        if word[0] == dictword[0]:
            points += 0.175 * max_points

        if word[-1] == dictword[-1]:
            points += 0.175 * max_points

        sliced_word = word[1:-1]
        sliced_dictword = dictword[1:-1]
        for i in range(len(sliced_word)):
            try:
                if sliced_word[i] == sliced_dictword[i]:
                    points += 0.25 / len(sliced_word) * max_points

                elif sliced_word[i] == sliced_dictword[i + 1]:
                    points += 0.175 / len(sliced_word) * max_points

                elif sliced_word[i] == sliced_dictword[i - 1]:
                    points += 0.175 / len(sliced_word) * max_points

                elif sliced_word[i] == sliced_dictword[i + 2]:
                    points += 0.175 * 0.5 / len(sliced_word) * max_points

                elif sliced_word[i] == sliced_dictword[i - 2]:
                    points += 0.175 * 0.5 / len(sliced_word) * max_points
            except IndexError:
                pass

        return points


def main():
    checker = SpellChecker()
    checker.load_words("words.txt")

    sentence = "helo my naem is sometheng"

    for word in sentence.split():
        max_points = 0
        suggestion = ""
        for dictword in checker.wordlist:
            points = checker.resembelance_factor(word, dictword)
            if points > max_points:
                max_points = points
                suggestion = dictword
        if max_points > 80 and suggestion != word:
            print(f"{word} -> {suggestion}", max_points)


if __name__ == "__main__":
    main()
