#!/usr/bin/env python3


def get_matrix(m, n):
    matrix = []
    for i in range(m):
        row = list(
            map(int, input(f"Enter row {i + 1} values separated by space: ").split())
        )
        if len(row) != n:
            raise ValueError(f"Row {i + 1} must have exactly {n} values.")
        matrix.append(row)
    return matrix


def sum_of_rows(matrix):
    return [sum(row) for row in matrix]


def main():
    m = int(input("Enter the number of rows (m): "))
    n = int(input("Enter the number of columns (n): "))
    matrix = get_matrix(m, n)
    row_sums = sum_of_rows(matrix)
    for i, row_sum in enumerate(row_sums):
        print(f"Sum of row {i + 1}: {row_sum}")


if __name__ == "__main__":
    main()
