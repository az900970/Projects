import string

card = 0
digits = []
temp = 0
total = 0
total2 = 0
checksum = 0

while True:
    try:
        card = int (input ("Number: "))
    except ValueError:
        print ("", end = '')

    break

  # AMEX

if ( card > 340000000000000 and card < 350000000000000 ) or ( card > 370000000000000 and card < 38000000000000000 ) :
    raw = card // 10
    for x in range (0, 14, 2):
        temp = raw % 10
        temp = temp * 2
        temp = temp // 10 + temp % 10
        total = total + temp
        digits.append (temp)
        raw = raw // 100

    raw2 = card
    for x in range (0, 15, 2):
        temp = raw2 % 10
        total2 = total2 + temp
        raw2 = raw2 // 100

    checksum = total + total2
    if checksum % 10 == 0:
        print('AMEX \n')

 # VISA

if ( card > 4000000000000 and card < 5000000000000 ) or ( card > 4000000000000000 and card < 5000000000000000 ):
    total = 0
    total2 = 0
    raw = card // 10
    for x in range (0, 15, 2):
        temp = raw % 10
        temp = temp * 2
        temp = temp // 10 + temp % 10
        total = total + temp
        digits.append (temp)
        raw = raw // 100

    raw2 = card
    for x in range (0, 16, 2):
        temp = raw2 % 10
        total2 = total2 + temp
        raw2 = raw2 // 100

    checksum = total + total2
    if checksum % 10 == 0:
        print('VISA \n')

# MASTERCARD

if ( card > 5100000000000000 and card < 5600000000000000 ) :
    total = 0
    total2 = 0
    raw = card // 10
    for x in range (0, 15, 2):
        temp = raw % 10
        temp = temp * 2
        temp = temp // 10 + temp % 10
        total = total + temp
        digits.append (temp)
        raw = raw // 100

    raw2 = card
    for x in range (0, 16, 2):
        temp = raw2 % 10
        total2 = total2 + temp
        raw2 = raw2 // 100

    checksum = total + total2
    if checksum % 10 == 0:
        print('MASTERCARD \n')

else:
    print ('INVALID \n')