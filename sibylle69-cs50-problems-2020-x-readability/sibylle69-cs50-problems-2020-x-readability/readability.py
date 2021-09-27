import math
from cs50 import get_string

def main():

    string = get_string("Text: \n");

    word = 0;
    ltrs = 0;
    stce = 0;
    i = 0;

    for i in range(len(string)):

        if string[i].isalpha():
            ltrs += 1

        elif string[i] == ' ':

            word += 1

        elif string[i] == '!' or string[i] == '.' or string[i] == '?':

            stce += 1

    ltrs = (ltrs / word) * 100
    stce = (stce / word) * 100

    formula = (0.0588 * ltrs - 0.296 * stce - 15.8)

    grade = int(round(formula))

    if grade > 16:
        print("Grade 16+")
    elif grade > 1:
        print(f"Grade {grade}")
    else:
        print("Before Grade 1")

main()
