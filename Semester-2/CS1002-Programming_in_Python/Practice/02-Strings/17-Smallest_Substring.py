#!/usr/bin/env python3


def find_smallest_substring(s):
    def contains_all_chars(window_count, target_count):
        for char in target_count:
            if window_count.get(char, 0) < target_count[char]:
                return False
        return True

    target_count = {}
    for char in s:
        target_count[char] = target_count.get(char, 0) + 1

    window_count = {}
    left = 0
    min_length = float("inf")
    min_substring = ""

    for right in range(len(s)):
        window_count[s[right]] = window_count.get(s[right], 0) + 1

        while contains_all_chars(window_count, target_count):
            if right - left + 1 < min_length:
                min_length = right - left + 1
                min_substring = s[left : right + 1]

            window_count[s[left]] -= 1
            if window_count[s[left]] == 0:
                del window_count[s[left]]
            left += 1

    return min_substring


def main():
    user_input = input("Enter a string: ")
    result = find_smallest_substring(user_input)
    print(f"The smallest substring containing all characters is: {result}")


if __name__ == "__main__":
    main()
