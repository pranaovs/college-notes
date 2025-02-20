#!/usr/bin/env python3


def create_array():
    return [[["*" for _ in range(2)] for _ in range(4)] for _ in range(3)]


def main():
    array = create_array()
    for layer in array:
        for row in layer:
            print(row)
        print()


if __name__ == "__main__":
    main()
