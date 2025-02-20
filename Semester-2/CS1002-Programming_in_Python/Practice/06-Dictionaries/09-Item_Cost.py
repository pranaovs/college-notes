#!/usr/bin/env python3


def get_item_prices(n):
    prices = {}
    for _ in range(n):
        item = input("Enter item name: ")
        price = float(input(f"Enter price for {item}: "))
        prices[item] = price
    return prices


def get_top_k_items(prices, k):
    sorted_items = sorted(prices.items(), key=lambda x: x[1], reverse=True)
    return sorted_items[:k]


def main():
    n = int(input("Enter the number of items: "))
    k = int(input("Enter the number of top priciest items to display: "))

    prices = get_item_prices(n)
    top_k_items = get_top_k_items(prices, k)

    print("\nTop {} priciest items:".format(k))
    for item, price in top_k_items:
        print(f"{item}: ${price:.2f}")


if __name__ == "__main__":
    main()
