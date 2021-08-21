"""
Python portion of the Grocery program
A number of functions that can be called to
access Grocery.txt

Author: Sean Reid
Date: 8/14/2021

"""

import re
import string


# Print all items in Grocery.txt
def printItems():
    with open('Grocery.txt', "r") as file_object:
        data = file_object.read()
        print(data)


# Count the occurences of an item in Groceries.txt
def counter(item):
    test = item.lower()
    matches = []
    with open('Grocery.txt', "r") as file_object:
        data = file_object.read().splitlines()
        matches = [line for line in data if line.lower() == test]
        count = len(matches)
        return count


# Display a histogram of the number of times each item occurs in Groceries.txt
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
