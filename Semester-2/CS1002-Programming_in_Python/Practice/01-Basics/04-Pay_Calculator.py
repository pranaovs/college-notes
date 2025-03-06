#!./.venv/bin/env python3


def calculate_pay(hours: float, rate: int = 40):

    base_hours = 40

    if hours > base_hours:
        pay: float = base_hours * rate
        pay += (hours - base_hours) * rate * 1.5

    else:
        pay: float = hours * rate

    return pay


def main():
    hours = float(input("Enter hours clocked in a week: "))
    print("Pay for {} hours in a week is: {:.2f}".format(hours, calculate_pay(hours)))


if __name__ == "__main__":
    main()
