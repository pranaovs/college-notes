#!/usr/bin/env python


def isPerfect(num: int) -> bool:
    sum = 0
    for i in range(1, num):
        if num % i == 0:
            sum += i
    return sum == num


def isHappy(num: int) -> bool:
    while num > 9:
        sum = 0
        while num > 0:
            sum += (num % 10) ** 2
            num //= 10
        num = sum

    return num == 1


def main():
    num = int(input("Enter a number: "))
    if isPerfect(num):
        print(f"{num} is a perfect number.")
    if isHappy(num):
        print(f"{num} is a happy number.")


if __name__ == "__main__":
    main()
