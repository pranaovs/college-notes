#!/usr/bin/env python3


def break_string(s: str, k: int) -> list[str]:
    slist = []
    for i in range(0, len(s), k):
        slist.append(s[i : i + k])

    return slist


def main():
    inp_str = str(input("Enter a string: "))
    break_length = int(input("Enter the length of each substring: "))

    broken_strings = break_string(inp_str, break_length)

    for substr in broken_strings:
        print(substr)


if __name__ == "__main__":
    main()
