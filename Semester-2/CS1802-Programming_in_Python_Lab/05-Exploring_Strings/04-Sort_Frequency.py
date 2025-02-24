#!/usr/bin/env python3


def main():
    inp_str = str(input("Enter a string: "))

    sorted_str = sorted(inp_str, key=inp_str.count, reverse=True)
    deduplicated_sorted_str = list(dict.fromkeys(sorted_str))

    print("".join(deduplicated_sorted_str))


if __name__ == "__main__":
    main()
