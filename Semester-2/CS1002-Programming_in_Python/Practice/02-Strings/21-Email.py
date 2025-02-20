#!/usr/bin/env python3


def is_valid_email(email):
    if "@" not in email or "." not in email:
        return False

    recipient, domain = email.split("@", 1)
    if not recipient or not domain:
        return False

    domain_name, top_level_domain = domain.rsplit(".", 1)
    if not domain_name or len(top_level_domain) < 2:
        return False

    allowed_recipient_chars = set(
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._-"
    )
    allowed_domain_chars = set(
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_"
    )

    if not all(char in allowed_recipient_chars for char in recipient):
        return False

    if not all(char in allowed_domain_chars for char in domain_name):
        return False

    if not top_level_domain.isalpha():
        return False

    return True


def main():
    email = input("Enter an email ID: ")
    if is_valid_email(email):
        print("Valid email ID")
    else:
        print("Invalid email ID")


if __name__ == "__main__":
    main()
