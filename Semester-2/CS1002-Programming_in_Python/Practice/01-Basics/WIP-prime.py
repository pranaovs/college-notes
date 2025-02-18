#!./.venv/bin/python


def list_primes_until(num: int) -> list[int]:

    primes = []

    for i in range(1, int(num)):
        print(i)
        for j in range(1, i):
            print(j)
            if i % j == 0:
                # break
                pass
            primes.append(i)

    return primes


def main():
    num = int(input("Enter a number to find all prime numbers until that number: "))
    for num in list_primes_until(num):
        print(num, end=" ")

    print()


if __name__ == "__main__":
    main()
