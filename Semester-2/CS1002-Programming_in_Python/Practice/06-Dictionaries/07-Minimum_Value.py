#!/usr/bin/env python3


def get_min(d):
    return min(d, key=d.get)


def main():
    user_input = input("Enter dictionary items (key:value pairs separated by commas): ")
    user_dict = dict(item.split(":") for item in user_input.split(","))
    min_key = get_min(user_dict)
    print(f"The key with the minimum value is: {min_key}")


if __name__ == "__main__":
    main()
