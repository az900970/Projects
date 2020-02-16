#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[])
{   int digit = 0;
    int alpha = 0;
    int cipher = 0;
    if (argc == 2)
     {printf ("success \n");
      for (int i=0, n = strlen (argv[1]); i<n; i++ )
      {
       if (isdigit(argv[1][i]) != 0)
        {        digit++;
        }
       else if (isdigit(argv[1][i]) == 0)
        {        alpha++;
        }
      }
      if (alpha >0)
       {printf ("Usage: ./caesar key\n");
       }
      else if (alpha == 0)
       { int key = atoi (argv[1]) % 26;
         string input = get_string ("plaintext: ");
         printf ("ciphertext: ");
         for (int c =0, a = strlen (input); c<a; c++)
          { if (isalpha(input[c]) !=0 && input[c] <=90)
             {
               cipher = input[c] + key;
               if (cipher <= 90)
               {printf ("%c", cipher);
               }
               else if (cipher > 90)
               { cipher = 64 + (cipher % 90) ;
                printf ("%c", cipher) ;
               }

             }
            if (isalpha(input[c]) !=0 && input [c] >90)
             { cipher = input[c] + key;
               if (cipher <= 122)
               { printf ("%c", cipher);
               }
               else if (cipher > 122)
               { cipher = 96 + (cipher % 122);
                 printf ("%c", cipher);
               }
             }
            else if ( isalpha(input[c]) == 0)
             { printf ("%c", input [c]) ;
             }



          }

         printf ("\n");
       }

     }




     else if (argc !=2)
     {printf ("Usage: ./caesar key\n") ;
      return 1 ;

     }






}


