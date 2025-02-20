#!/usr/bin/env python3


def get_list_of_lists():
    list_of_lists = []
    n = int(input("Enter the number of lists: "))
    for i in range(n):
        lst = list(
            map(
                int,
                input(f"Enter the elements of list {i+1} separated by space: ").split(),
            )
        )
        list_of_lists.append(lst)
    return list_of_lists


def find_highest_sum_list(list_of_lists):
    max_sum = float("-inf")
    max_list = []
    for lst in list_of_lists:
        current_sum = sum(lst)
        if current_sum > max_sum:
            max_sum = current_sum
            max_list = lst
    return max_list


def main():
    list_of_lists = get_list_of_lists()
    highest_sum_list = find_highest_sum_list(list_of_lists)
    print("The list with the highest sum of elements is:", highest_sum_list)


if __name__ == "__main__":
    main()
