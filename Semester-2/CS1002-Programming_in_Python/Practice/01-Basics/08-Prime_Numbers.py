#!/usr/bin/env python3


def list_primes_until(num: int) -> list[int]:
    primes = []
    for i in range(2, num + 1):
        is_prime = True
        for j in range(2, int(i**0.5) + 1):
            if i % j == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(i)
    return primes


def main():
    num = int(input("Enter a number to find all prime numbers until that number: "))
    for prime in list_primes_until(num):
        print(prime, end=" ")
    print()


if __name__ == "__main__":
    main()
