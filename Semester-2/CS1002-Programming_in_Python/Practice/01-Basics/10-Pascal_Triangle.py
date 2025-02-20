#!/usr/bin/env python3


def generate_pascals_triangle(rows):
    triangle = []
    for i in range(rows):
        row = [1] * (i + 1)
        for j in range(1, i):
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
        triangle.append(row)
    return triangle


def print_pascals_triangle(triangle):
    max_width = len(" ".join(map(str, triangle[-1])))
    for row in triangle:
        row_str = " ".join(map(str, row))
        print(row_str.center(max_width))


def main():
    rows = int(input("Enter the number of rows: "))
    triangle = generate_pascals_triangle(rows)
    print_pascals_triangle(triangle)


if __name__ == "__main__":
    main()
