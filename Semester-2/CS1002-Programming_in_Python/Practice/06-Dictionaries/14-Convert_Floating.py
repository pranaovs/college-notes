#!/usr/bin/env python3


def convert_value(value):
    try:
        if "." in value:
            return float(value)
        else:
            return int(value)
    except ValueError:
        return value


def convert_dict(input_dict):
    return {
        k: (
            convert_value(v)
            if isinstance(v, str) and v.replace(".", "", 1).isdigit()
            else v
        )
        for k, v in input_dict.items()
    }


def main():
    user_input = input("Enter a dictionary: ")
    input_dict = eval(user_input)
    converted_dict = convert_dict(input_dict)
    print("Converted dictionary:", converted_dict)


if __name__ == "__main__":
    main()
