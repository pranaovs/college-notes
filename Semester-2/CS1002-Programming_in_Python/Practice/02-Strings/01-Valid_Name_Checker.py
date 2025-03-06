#!/usr/bin/env python3


def check_name(name: str):
    for i in name:
        if not (i.isalpha() or i == "." or i.isspace()):
            return False

    return True


def main():

    name = input("Enter your name: ")
    if check_name(name):
        print("Valid Name")
    else:
        print("Invalid Name")


if __name__ == "__main__":
    main()
