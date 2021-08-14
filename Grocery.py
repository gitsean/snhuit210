import re
import string


def printsomething():
    print("Hello from python!")


def PrintMe(v):
    print("You sent me: " + v)
    return 100


def SquareValue(v):
    return v * v


def printItems():
    with open('Grocery.txt', "r") as file_object:
        # read file content
        data = file_object.read()
        # print file contents
        print(data)


def Histogram():
    with open('Grocery.txt', "r") as file_object:
        # read file content
        data = file_object.read().splitlines()
        items = {}
        # print file contents
        for line in data:
            if line in items:
                items[line] += 1
            else:
                items[line] = 1
        for key in items:
            print(f"{key:<15} " + "*" * items[key])
