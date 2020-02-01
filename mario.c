#include <cs50.h>
#include <stdio.h>

int main(void)
{ int n;
do {
n = get_int("Enter height of pyramid \n");
    }
 while (n<1 || n>8);
   for (int x=1; x<=n; x++)
 {
       for (int y=1; y<=n; y++)
       { int z = y;
       if (z<=n-x)
                  {printf(" ");}
                    else {printf("#");}
               }
 
 printf("\n"); }
}
 
 
 
