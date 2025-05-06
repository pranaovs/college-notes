#!/usr/bin/env python3


def alternate_concatenate(str1: str, str2: str) -> str:
    return "".join([str1[i] + str2[i] for i in range(len(str1))])


def main():
    str1 = str(input("Enter the first string: "))
    str2 = str(input("Enter the second string: "))

    if len(str1) != len(str2):
        print("Strings are not of equal length.")
        return

    print(alternate_concatenate(str1, str2))


if __name__ == "__main__":
    main()
