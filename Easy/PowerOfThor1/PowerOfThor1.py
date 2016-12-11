import sys
import math

light_x, light_y, initial_tx, initial_ty = [int(i) for i in input().split()]

thor_pos_x = initial_tx
thor_pos_y = initial_ty

while True:
    remaining_turns = int(input())  # The remaining amount of turns Thor can move. Do not remove this line.

    move_dir = ""

    if(thor_pos_y > light_y):
        move_dir += "N"
        thor_pos_y -= 1
        
    else:
        if(thor_pos_y < light_y):
            move_dir += "S"
            thor_pos_y += 1
        
        
    if(thor_pos_x > light_x):
        move_dir += "W"
        thor_pos_x -= 1
    else:
        if(thor_pos_x < light_x):
            move_dir += "E"
            thor_pos_x += 1

    print(move_dir)
