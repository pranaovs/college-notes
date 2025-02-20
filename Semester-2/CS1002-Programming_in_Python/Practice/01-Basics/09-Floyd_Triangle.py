#!/usr/bin/env python3


def main():
    rows = int(input("Enter the number of rows: "))
    num = 1

    for i in range(1, rows + 1):
        for _ in range(1, i + 1):
            print(num, end=" ")
            num += 1
        print()


if __name__ == "__main__":
    main()
