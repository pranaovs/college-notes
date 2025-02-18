#!/usr/bin/env python3


def main():
    name: str = ""
    marks: list[tuple[str, int]] = []

    print(
        "Enter the name and marks of the students separated by a space. Type 'done' when finished."
    )

    while True:
        input_str = input().split()
        if len(input_str) != 2 and input_str[0] != "done":
            print("Invalid input. Please try again.")
            continue
        if input_str[0] == "done":
            break
        marks.append((str(input_str[0]), int(input_str[1])))

    # Sort the marks in descending order
    marks.sort(key=lambda x: x[1], reverse=True)
    print(marks)

    print(
        f"The student with the highest mark is: {marks[0][0]} with a mark of {marks[0][1]}"
    )

    while True:
        pos: int = int(input("Enter the place to find the student's mark: "))
        if pos < 1 or pos > len(marks) - 1:
            print("Invalid position. Please try again.")
        if pos == 0:
            break

        print(
            f"The student in position {pos} is {marks[pos-1][0]} with a mark of {marks[pos-1][1]}"
        )


if __name__ == "__main__":
    main()
