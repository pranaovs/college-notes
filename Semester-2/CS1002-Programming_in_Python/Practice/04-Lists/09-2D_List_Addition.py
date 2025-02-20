#!/usr/bin/env python3


def get_2d_list():
    matrix = []
    while True:
        row = input("Enter a row (space-separated, or empty to finish): ")
        if not row:
            break
        matrix.append(list(map(int, row.split())))
    return matrix


def add_2d_lists(list1, list2):
    result = []
    for i in range(len(list1)):
        row = []
        for j in range(len(list1[0])):
            row.append(list1[i][j] + list2[i][j])
        result.append(row)
    return result


def main():
    print("Enter the first 2D list:")
    list1 = get_2d_list()
    print("Enter the second 2D list:")
    list2 = get_2d_list()

    if len(list1) != len(list2) or len(list1[0]) != len(list2[0]):
        print("Error: The two 2D lists must have the same dimensions.")
        return

    result = add_2d_lists(list1, list2)
    print("The result of adding the two 2D lists is:")
    for row in result:
        print(row)


if __name__ == "__main__":
    main()
