#!./.venv/bin/env python3


def celsius_to_fahrenheit(celsius):
    return celsius * 9 / 5 + 32


def main():
    print("Celsius to Fahrenheit converter")
    celsius = float(input("Enter the temperature in Celsius: "))
    fahrenheit = celsius_to_fahrenheit(celsius)
    print(f"{celsius}°C is {fahrenheit}°F")


if __name__ == "__main__":
    main()
