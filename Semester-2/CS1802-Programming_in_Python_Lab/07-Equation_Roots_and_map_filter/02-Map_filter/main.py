#!/usr/bin/env python3


def main():
    print(
        "Enter a list (of numbers) consisting of lists (sub-lists). The sublists need to be separated by commas (,) and the list of lists be separated by spaces"
    )
    inputlst = [ele.split(",") for ele in input().split(" ")]

    print("Input list", inputlst)

    flatlst = []

    for sublit in inputlst:
        for ele in sublit:
            flatlst.append(ele)

    print("Flattened list:", flatlst)

    print(
        "Performing int function on each element of the flattened list:\n",
        list(map(int, flatlst)),
    )
    print(
        "Performing float function on each element of the flattened list:\n",
        list(map(float, flatlst)),
    )

    filter_num = int(
        input(
            "Enter a number to filter out all numbers lesser than and greater than the given number from the flattened list: "
        )
    )

    print(
        f"Numbers lesser than {filter_num} from the flattened list are:\n",
        list(filter(lambda x: float(x) < filter_num, flatlst)),
    )
    print(
        f"Numbers greater than {filter_num} from the flattened list are:\n",
        list(filter(lambda x: float(x) > filter_num, flatlst)),
    )


if __name__ == "__main__":
    main()
