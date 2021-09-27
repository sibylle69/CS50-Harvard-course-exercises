import sys
import csv
import re

def printFound(table, count):
    for line in table:
        suspect = line[0]
        # if the each rts we know matches each maximum
        rtss = [int(foundrts) for foundrts in line[1:]]
        if rtss == count:
            # print
            print(suspect)
        if count == 0:
            print("no match")

def maxRepetitions(dnasample, rts):
        # to count the reps we create a list
        # with an item for each char
        reps = [0] * len(dnasample)
        # we iterate through the helix
        for i in range(len(dnasample) - len(rts), -1, -1):
            # and if it matches we give it a number
            if dnasample[i: i + len(rts)] == rts:
                if i + len(rts) > len(dnasample) - 1:
                    reps[i] = 1
                # which increases
                else:
                    reps[i] = 1 + reps[i + len(rts)]
        # and return the maximum
        return max(reps)

def main():
    # first we check for valid number of inputs
    if len(sys.argv) != 3:
        print("no")
        sys.exit(1)
    # then we assign them
    tested = sys.argv[1]
    samples = sys.argv[2]

    # we open the table and separate the dnas
    csv_file = open(tested, "r")
    table = csv.reader(csv_file)
    seqs = next(table)[1:]

    # next we open the helix given
    txt_file = open(samples, "r")
    dnasample = txt_file.read()

    # and find maximum repetitions

    count = [maxRepetitions(dnasample, rts) for rts in seqs]
    printFound(table, count)

    csv_file.close()
    txt_file.close()

main()