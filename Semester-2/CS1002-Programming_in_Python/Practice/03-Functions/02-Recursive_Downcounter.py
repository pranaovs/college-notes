#!/usr/bin/env python3

from time import sleep


def downcounter(n):
    if n == 0:
        print("Blastoff!")
    else:
        sleep(0.1)
        print(n)
        downcounter(n - 1)


def main():
    num = int(input("Enter a number to countdown from: "))
    downcounter(num)


if __name__ == "__main__":
    main()
