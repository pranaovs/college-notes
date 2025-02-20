#!/usr/bin/env python3


def is_valid_name(name):
    for char in name:
        if not (char.isalpha() or char.isspace() or char == "."):
            return False
    return True


def is_valid_employee_id(employee_id):
    return len(employee_id) == 5 and employee_id[0] == "2" and employee_id[1:].isdigit()


def is_valid_pan(pan):
    return (
        len(pan) == 10
        and pan[:5].isalpha()
        and pan[:5].isupper()
        and pan[5:9].isdigit()
        and pan[9].isalpha()
        and pan[9].isupper()
    )


def is_valid_account_number(account_number):
    return (
        len(account_number) == 10
        and account_number.startswith("120")
        and account_number[3:].isdigit()
    )


def main():
    name = input("Enter your name: ")
    if not is_valid_name(name):
        print("Invalid name")
        return

    employee_id = input("Enter your employee ID: ")
    if not is_valid_employee_id(employee_id):
        print("Invalid employee ID")
        return

    pan = input("Enter your PAN: ")
    if not is_valid_pan(pan):
        print("Invalid PAN")
        return

    account_number = input("Enter your account number: ")
    if not is_valid_account_number(account_number):
        print("Invalid account number")
        return

    print("All inputs are valid")


if __name__ == "__main__":
    main()
