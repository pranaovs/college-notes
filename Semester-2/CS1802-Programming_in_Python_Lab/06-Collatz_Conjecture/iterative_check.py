#!/usr/bin/env python3

import sys

from collatz import collatz_steps


def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <max_num>")
        return

    # Try getting max values until specified number
    for i in range(1, int(sys.argv[1]) + 1):
        try:
            _, max_value, _ = collatz_steps(i, show_steps=False)
            print(f"{i}: {max_value}")
        except Exception as e:
            print(f"Exception: {e}")
            break


if __name__ == "__main__":
    main()
