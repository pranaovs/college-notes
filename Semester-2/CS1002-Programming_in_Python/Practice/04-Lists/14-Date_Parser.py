#!/usr/bin/env python3


def get_month_name(month_number):
    months = [
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    ]
    return months[month_number - 1]


def format_date(date_str):
    month, day, year = date_str.split("/")
    month_name = get_month_name(int(month))
    return f"{month_name} {int(day)}, {year}"


def main():
    date_str = input("Enter a date (mm/dd/yyyy): ")
    formatted_date = format_date(date_str)
    print(formatted_date)


if __name__ == "__main__":
    main()
