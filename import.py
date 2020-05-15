# TODO

from cs50 import SQL
import csv
import sys

if len (sys.argv) != 2:
    print ("Please only give the name of the file")
    exit()

db = SQL ( "sqlite:///students.db")

with open (sys.argv[1]) as csvfile:
    readCSV = csv.DictReader (csvfile, delimiter = ',')
    for row in readCSV:
        name = row['name'].split ( " ", 2 )
        if len (name) == 2:
            name.append ( name[1])
            name[1] = "None"
        db.execute (" INSERT INTO students ( first, middle, last, house, birth ) VALUES (?, ?, ?, ?, ?)", name[0], name[1], name[2], row['house'], row['birth'])
