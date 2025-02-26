#!/usr/bin/env python3

import sys


def collatz_steps(num: int, show_steps: bool = True):

    tmpnum: int = int(num)
    steps: int = 0
    steps_list: list[int] = []
    max_value: int = 0

    while tmpnum != 1:
        steps += 1

        if tmpnum % 2 == 0:
            (
                print(f"Step {steps}: {tmpnum} / 2 = {tmpnum//2}")
                if show_steps
                else None
            )  # Conditional print
            tmpnum //= 2
        else:
            (
                print(f"Step {steps}: {tmpnum} * 3 + 1 = {tmpnum*3 + 1}")
                if show_steps
                else None
            )  # Conditional print
            tmpnum = tmpnum * 3 + 1

        steps_list.append(tmpnum)

        # Set max identified intermediate value
        if tmpnum > max_value:
            max_value = tmpnum

    return steps, max_value, steps_list


def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <num>")
        return

    collatz_props = collatz_steps(int(sys.argv[1]))

    print(
        f"""
Steps taken to reach 1 from {sys.argv[1]} = {collatz_props[0]}
Maximum value reached = {collatz_props[1]}
"""
    )


if __name__ == "__main__":
    main()
