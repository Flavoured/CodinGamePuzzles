import sys
import math

while True:
    tallest_index = -1
    tallest_height = -1
    
    for i in range(8):
        mountain_h = int(input())  # represents the height of one mountain.

        if(tallest_height != -1):
            if(mountain_h > tallest_height):
                tallest_index = i
                tallest_height = mountain_h
        else:
            tallest_index = i
            tallest_height = mountain_h

    print(tallest_index)
