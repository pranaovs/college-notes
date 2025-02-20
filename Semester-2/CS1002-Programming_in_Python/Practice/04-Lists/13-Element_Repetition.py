#!/usr/bin/env python3


def get_common_indices(lists):
    if not lists:
        return []

    common_indices = []
    for i in range(len(lists[0])):
        element = lists[0][i]
        if all(i < len(lst) and lst[i] == element for lst in lists):
            common_indices.append(i)
    return common_indices


def main():
    n = int(input("Enter the number of lists: "))
    lists = []
    for _ in range(n):
        lst = input("Enter the list elements separated by spaces: ").split()
        lists.append(lst)

    common_indices = get_common_indices(lists)
    print("Indices with common elements:", common_indices)


if __name__ == "__main__":
    main()
