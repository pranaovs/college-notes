#!/usr/bin/env python3


def gcd(m: int, n: int) -> int:
    val = 1

    for i in range(2, min(m, n) + 1):
        if m % i == 0 and n % i == 0:
            val = i

    return val


def main():

    m, n = map(
        int, input("Enter two numbers seperated by a space to find their GCD: ").split()
    )
    print(f"The GCD of {m} and {n} is {gcd(m,n)}")


if __name__ == "__main__":
    main()
