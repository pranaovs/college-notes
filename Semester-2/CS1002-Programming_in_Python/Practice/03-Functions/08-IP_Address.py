#!/usr/bin/env python3


def is_valid_ip(ip):
    parts = ip.split(".")
    if len(parts) != 4:
        return False
    for part in parts:
        if not part.isdigit():
            return False
        num = int(part)
        if num < 0 or num > 255:
            return False
    return True


def main():
    ip = input("Enter an IP address: ")
    if is_valid_ip(ip):
        print(f"{ip} is a valid IP address.")
    else:
        print(f"{ip} is not a valid IP address.")


if __name__ == "__main__":
    main()
