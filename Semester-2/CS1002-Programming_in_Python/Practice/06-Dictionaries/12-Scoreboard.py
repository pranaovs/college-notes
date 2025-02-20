#!/usr/bin/env python3


def get_player_data():
    players = {}
    n = int(input("Enter the number of players: "))
    for _ in range(n):
        name = input("Enter player name: ")
        score = int(input(f"Enter score for {name}: "))
        players[name] = score
    return players


def filter_scores(players, a, b):
    return {name: score for name, score in players.items() if a <= score <= b}


def main():
    players = get_player_data()
    a = int(input("Enter the lower bound of the score range: "))
    b = int(input("Enter the upper bound of the score range: "))
    filtered_players = filter_scores(players, a, b)
    print("Filtered players:", filtered_players)


if __name__ == "__main__":
    main()
