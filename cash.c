#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{float input;
do 
{input = get_float("Please enter change owed: ");
}
while (input <=0) ;

int cents;
cents = round (input*100);
int coins = 0 ;

    if (cents>=25)
{coins = cents/25;
 cents = cents % 25 ;}
 if (cents>=10)
{coins = coins + cents/10;
 cents = cents % 10 ; }
if (cents>=5)
{coins = coins + cents/5;
 cents = cents % 5;}
if (cents>=1)
{coins = coins + cents/1;
 cents = cents % 1 ;}

printf ("%i \n", coins);
}
