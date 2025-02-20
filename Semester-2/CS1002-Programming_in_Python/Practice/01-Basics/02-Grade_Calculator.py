#!./.venv/bin/python


def grade(mark):

    if mark not in range(0, 101):
        raise ValueError("Mark should be between 0 and 100")

    if mark == 100:
        return "outstanding"

    mark = mark // 10

    switcher = {
        9: "outstanding",
        8: "excellent",
        7: "good",
        6: "average",
        5: "below average",
    }

    return switcher.get(mark, "fail")


def main():
    mark = int(input("Enter your mark: "))
    print("Grade for {} is {}".format(mark, grade(mark)))


if __name__ == "__main__":
    main()
