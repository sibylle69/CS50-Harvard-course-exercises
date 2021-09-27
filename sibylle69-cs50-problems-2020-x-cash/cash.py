from cs50 import get_float

def main():

    dollars = get_positive_int()
    print(f"Change owed: {dollars}\n")

    cents = int(dollars * 100)
    number_of_coins = 0

    if cents % 25 >= 0:

        number_of_coins += cents // 25
        cents = cents % 25

    if cents % 10 >= 0:

        number_of_coins += cents // 10
        cents = cents % 10


    if cents % 5 >= 0:

        number_of_coins += cents // 5
        cents = cents % 5

    number_of_coins += cents
    print(f"{number_of_coins}\n")

def get_positive_int():
    while True:
        n = get_float("Positive float: ")
        if n > 0:
            break
    return n

main()
