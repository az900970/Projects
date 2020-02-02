#include <cs50.h>
#include <stdio.h>

int main(void)
{
int n;
do{
    n = get_int ("enter height of pyramid \n") ;
    } 
    while (n<1 || n>8) ;
    for (int x = 1; x<=n; x++)
    {
        for (int y = 1; y<=2*n+2; y++){
            int z=y;
            if (z<=n-x)
                {printf(" ");}
                else if (z>n-x  && z<=n)
                {printf("#");}
                else if (z>n && z<=n+2)
                {printf(" ");}
                else if (z>n+2 && z<=n+2+x)
                {printf("#");}
                else if (z>n+2 && z<=2*n+2)
                {printf(" ");}

        }
   printf("\n");
    }

}
