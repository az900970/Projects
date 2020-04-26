import string

letters = 0
words = 1
sentences = 0
index = 0


text = str (input ("Input text:  "))
length = len (text)

for x in range (length):
    if (text[x] >= 'A' and text[x] <= 'Z') or (text[x] >= 'a' and text[x] <= 'z'):
        letters = letters + 1
    if text[x] == ' ' :
        words = words + 1
    if text[x] == '.' or text[x] == '?' or text[x] == '!':
        sentences = sentences + 1

let = 0
sent = 0

let = (letters / words ) * 100
sent = (sentences / words) * 100
index = round ( ( 0.0588 * let ) - ( 0.296 * sent ) - 15.8)

if index <= 1:
    print ("Before Grade 1 ")
elif index >= 16:
    print ("Grade 16+")
else:
    print (f" Grade {index}")