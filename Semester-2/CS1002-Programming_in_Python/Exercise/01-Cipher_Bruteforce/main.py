#!/usr/bin/env python3

"""
This code is licensed under the MIT License
Copyright 2025 Pranaov S
https://opensource.org/license/MIT
"""

"""Caesar Cipher Brute Force Tool"""


SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?."


class CaesarCipherBruteForce:
    def __init__(self, ciphertext: str, symbols: str):
        self.ciphertext = ciphertext
        self.symbols = symbols

    def decrypt(self, key: int) -> str:

        translated = ""
        for symbol in self.ciphertext:
            if symbol in self.symbols:
                symbolIndex = self.symbols.find(symbol)
                translatedIndex = (symbolIndex - key) % len(self.symbols)
                translated = translated + self.symbols[translatedIndex]
            else:
                translated = translated + symbol

        return translated

    def brute_force_user_input(self) -> int | None:
        print(
            "Press <Enter> to try using the next key, input y to confirm the key, input b to go to previous iteration, or input q to quit."
        )
        key: int = 0
        while key < (len(self.symbols)):
            translated = self.decrypt(key)
            inp = input(f"Key #{key}: {translated} ?: ")
            if inp == "y":
                print(f"Using key: {key}")
                return key
            elif inp == "b":
                print("Going back to the previous key.")
                if key > 0:
                    key -= 2
            elif inp == "q":
                print("Terminating user input key brute force strategy")
                return None

            key += 1

    def brute_force_check_spaces(self) -> int | None:
        candidates: list[dict[str, str | int]] = []
        for key in range(len(self.symbols)):
            translated = self.decrypt(key)
            if translated.count(" ") >= 2:
                candidates.append({"key": key, "text": translated})

        if len(candidates) == 0:
            print("Not enough spaces to determine a valid key.")
            return None

        candidates.sort(key=lambda x: str(x["text"]).count(" "), reverse=True)
        max_spaces = str(candidates[0]["text"]).count(" ")

        print(
            "Press <Enter> to try using the next key, input y to confirm the key, or input q to quit."
        )
        for candidate in candidates:
            if str(candidate["text"]).count(" ") >= max_spaces - 1:
                key = int(candidate["key"])
                translated = self.decrypt(key)
                inp = input(f"Key #{key}: {translated} ?: ")
                if inp == "y":
                    print(f"Confirming key: {key}")
                    return key
                elif inp == "q":
                    print("Terminating space checking brute force stretegy")
                    return None

    def decode(self) -> int | None:

        print("Trying strategy 1: Checking for spaces in the text.")
        key = self.brute_force_check_spaces()
        if key is not None:
            return key

        print("\nTrying strategy 2: User input")
        key = self.brute_force_user_input()
        if key is not None:
            return key


def main():

    ciphertexts: list[str] = []
    with open("ciphertext.txt", "r") as f:
        ciphertexts: list[str] = f.readlines()

    decoded: list[dict[str, str | int]] = []
    for ciphertext in ciphertexts:
        cipher = CaesarCipherBruteForce(ciphertext.strip(), SYMBOLS)
        key = cipher.decode()
        if key is not None:
            print(f"Decrypted text: {cipher.decrypt(key)}")
            decoded.append(
                {
                    "ciphertext": ciphertext.strip(),
                    "key": key,
                    "text": cipher.decrypt(key),
                }
            )
        else:
            print(f"No valid key found for {ciphertext.strip()}")

        print()

    print("\nDecoded messages:")
    for i, item in enumerate(decoded):
        print(
            f"Ciphertext {i + 1}: {item['ciphertext']}, Key: {item['key']}, Decrypted Text: {item['text']}"
        )


if __name__ == "__main__":
    main()
