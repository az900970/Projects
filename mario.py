import string

spacer = 0
height = 0
while height < 1 or height > 8:
    height = int (input ("Height: \n"))

for x in range (1, height + 1, 1):
    for y in range (0 , height, 1):
        if height - y <= x:
            print ("#", end = '')
        else:
            print (" ", end = '')
    print ("")

