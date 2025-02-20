#!/usr/bin/env python3


def rotations_to_right(original, rotated):
    n = len(original)
    for i in range(n):
        if original == rotated[i:] + rotated[:i]:
            return i
    return -1


def rotations_to_left(original, rotated):
    n = len(original)
    for i in range(n):
        if original == rotated[-i:] + rotated[:-i]:
            return i
    return -1


def main():
    original = input("Enter the original string: ")
    rotated = input("Enter the rotated string: ")

    right_rotations = rotations_to_right(original, rotated)
    left_rotations = rotations_to_left(original, rotated)

    if right_rotations != -1:
        print(f"Right rotations needed: {right_rotations}")
    else:
        print("The rotated string cannot be obtained by right rotations.")

    if left_rotations != -1:
        print(f"Left rotations needed: {left_rotations}")
    else:
        print("The rotated string cannot be obtained by left rotations.")


if __name__ == "__main__":
    main()
