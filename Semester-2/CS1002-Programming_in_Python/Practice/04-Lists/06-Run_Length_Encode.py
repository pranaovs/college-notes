#!/usr/bin/env python3


def run_length_encode(input_list):
    if not input_list:
        return []

    encoded_list = []
    current_element = input_list[0]
    count = 1

    for element in input_list[1:]:
        if element == current_element:
            count += 1
        else:
            if count > 1:
                encoded_list.append([current_element, count])
            else:
                encoded_list.append(current_element)
            current_element = element
            count = 1

    if count > 1:
        encoded_list.append([current_element, count])
    else:
        encoded_list.append(current_element)

    return encoded_list


def main():
    user_input = input("Enter a list of integers separated by spaces: ")
    input_list = list(map(int, user_input.split()))
    encoded_list = run_length_encode(input_list)
    print("Run-length encoded list:", encoded_list)


if __name__ == "__main__":
    main()
