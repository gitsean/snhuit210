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
        data = file_object.read()
        print(data)


def counter(item):
    test = item.lower()
    matches = []
    with open('Grocery.txt', "r") as file_object:
        data = file_object.read().splitlines()
        matches = [line for line in data if line.lower() == test]
        count = len(matches)
        return count


def histogram():
    with open('Grocery.txt', "r") as file_object:
        data = file_object.read().splitlines()
        items = {}
        for line in data:
            if line in items:
                items[line] += 1
            else:
                items[line] = 1
        for key in items:
            print(f"{key:<15} " + "*" * items[key])
