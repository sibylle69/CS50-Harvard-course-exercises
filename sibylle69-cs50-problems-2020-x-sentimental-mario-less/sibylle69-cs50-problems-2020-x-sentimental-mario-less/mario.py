#!/usr/bin/python

h = input("Height:")

if int(h) > 8 or int(h) < 1:
    print("Height must be smaller than 8")
    h = input("Height:")

for i in range(int(h)):
        for j in range(int(h)-1-i):
            print(" ", end ="")
        for k in range(i+1):
            print("#", end ="")
        print()