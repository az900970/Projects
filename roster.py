# TODO

from cs50 import SQL
import csv
import sys

if len (sys.argv) != 2:
    print ("Please only give the name of the house")
    exit()

house = sys.argv[1]

db = SQL ( "sqlite:///students.db")

result = db.execute ("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last ASC", house)

for x in range (0, len (result), 1):
    if result[x]['middle'] == 'NULL':
        name = result[x]['first'] + " " + result[x]['last']
    else:
        name = result[x]['first'] + " " + result[x]['middle'] + " " + result[x]['last']
    year = str (result[x]['birth'])
    print (""+name+", born "+year+"")