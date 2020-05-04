import sys
import csv

if len (sys.argv) != 3:                                        # if incorrect number of arguments
    print ("Please give only file name and DNA")
    exit()

with open (sys.argv[1]) as csvfile:                            # open the first command line argument as a CSV file
    readCSV = csv.DictReader (csvfile, delimiter = ',')        # store the data in variable "readCSV" as datatype dictionary
    database = []                                              # create a database of datatype list
    for row in readCSV:                                        # for each row in the dictionary
        database.append (row)                                  # add a new row in the database and store the row
keys = list (database[0].keys())                               # store the keys of the first row as a list
STRcount = len (keys)                                          # count the number of STR sequences in the file



with open (sys.argv[2], 'rt') as dnafile:                      # open the second commandline argument as a file named dnafile
    DNA = dnafile.read()                                       # read the contents of the file into a string
    STRmax = [0] * STRcount                                    # create a list of elements equal to the number of STRs
    STRcounter = [0] * len (DNA)                               # create a list of elements equal to the number of STRs


    for eachSTR in range (1, STRcount, 1):                      # iterate over each STR

        for x in range (0, len (DNA), 1):                       # iterate over each character of the string "DNA"
            substring = DNA[x:]                                 # create a substring which starts from the xth character
            STRcounter[x] = 0                                   # set the counter for the next STR to zero
            a = len (keys[eachSTR])                             # calculate the length of the STR to identify block size
            for y in range (0, len (substring) + 1, a) :        # iterate over the substring with block size 'a'
                block = substring [y : y + a]                   # store the substring block in a variable "block"
                if block == keys[eachSTR]:                      # compare the block to the STR
                    STRcounter[x] = STRcounter[x] + 1           # increase the counter of that STR
                else:                                           # if it does not match, break the loop.
                    break
            if STRmax[eachSTR] < STRcounter[x]:                 # check if the count is the highest so far
                    STRmax[eachSTR] = STRcounter[x]             # if it is, store it in the list for the max

for d in range (0, len (database), 1):                            # iterate over each row
    finalcount = [False] * (STRcount - 1)                         # counter for storing number of STR matches ( minus 1 for name)
    for c in range ( 1, STRcount, 1):                             # iterate over each entry in the row
        if STRmax[c] == int (database[d][str (keys[c])]) :        # compare the maximum STR against the value in the database
            finalcount[c - 1] = True                              # store the result; (c-1) since index 0 is for name
    if all (finalcount) == True:                                  # if all the comparisons are true
        print (database[d][str (keys[0])])                        # print the name (stored at index 0)
        sys.exit (0)                                              # and exit the program
print ("No match")                                                # if the loop ends, then there was no match


