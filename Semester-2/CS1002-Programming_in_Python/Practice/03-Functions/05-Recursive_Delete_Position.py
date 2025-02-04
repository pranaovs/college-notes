#!/usr/bin/env python3


def delete_item(
    lst: list[int], delete_position: int, current_position: int = 0
) -> list[int]:
    if delete_position == current_position:
        return lst[0:current_position] + lst[current_position + 1 :]
    else:
        return delete_item(lst, delete_position, current_position + 1)


def main():
    input_lst: list[int] = list(
        map(int, input("Enter the elements of the list: ").split())
    )
    position: int = int(input("Enter the position to delete: "))

    if position < 0 or position >= len(input_lst):
        raise ValueError("Invalid position")

    print(
        "New list after deleting the element at position",
        position,
        "is",
        delete_item(input_lst, position),
    )


if __name__ == "__main__":
    main()
