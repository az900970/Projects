#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main (void)
{
    string s = get_string ("Input text:  ");
    int n = strlen (s);
    float letters = 0;
    float words = 1;
    float sentences = 0;
    for (int count = 0; count < n ; count ++)
{
   if ((s [count] >= 'A' && s [count] <= 'Z') || (s[count] >= 'a' && s[count] <='z'))
    {letters ++;}
   if ( s [count] == ' ')
    { words++;}
   if (s [count] == '.' || s [count] == '!'  || s [count] == '?' )
    {sentences++;}

}


float let = 0;
float sent = 0;

let = (letters/words)*100;
sent = (sentences/words)*100;
float index = round ((0.0588*let)-(0.296*sent)-15.8);
if (index <= 1)
{printf ("Before Grade 1\n");}
else if (index >=16)
{printf ("Grade 16+\n");}
else
{printf( "Grade %.0f\n", index);}




}
