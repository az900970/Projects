#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{   float average = 0;
    int final = 0;
    for ( int x = 0; x < height; x++ )
     {
         for ( int y = 0; y < width; y++)
         {
            average = (image[x][y].rgbtBlue + image[x][y].rgbtGreen + image[x][y].rgbtRed) / 3;
            final = round (average);
            image[x][y].rgbtBlue = final;
            image[x][y].rgbtGreen = final;
            image[x][y].rgbtRed = final;
         }

     }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiared = 0;
    int sepiagreen = 0;
    int sepiablue = 0;

    for (int x = 0; x < height; x++)
    {
       for (int y = 0; y < width; y++)
        {
            sepiared = round ( (0.393 * image[x][y].rgbtRed) + (0.769 * image[x][y].rgbtGreen)
            + (0.189 * image[x][y].rgbtBlue) ) ;
            sepiagreen = round ( (0.349 * image[x][y].rgbtRed) + (0.686 * image[x][y].rgbtGreen)
            + (0.1168 * image[x][y].rgbtBlue) ) ;
            sepiablue = round ( (0.272 * image[x][y].rgbtRed) + (0.534 * image[x][y].rgbtGreen)
            + (0.131 * image[x][y].rgbtBlue) ) ;

            if ( sepiared > 255)
            sepiared = 255;
            if ( sepiagreen > 255)
            sepiagreen = 255;
            if ( sepiablue > 255)
            sepiablue = 255;

            image[x][y].rgbtBlue = sepiablue;
            image[x][y].rgbtGreen = sepiagreen;
            image[x][y].rgbtRed = sepiared;
        }


    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int count = 0;
     RGBTRIPLE *temp = calloc (width, sizeof (RGBTRIPLE) ) ;
     if (temp == NULL)
     {printf ("ERROR");
      return ;
     }
    for ( int x = 0; x < height; x++)
      {
        for ( int z = 0; z < 2; z++)
        {
           for ( int y = 0; y < width; y++)
            { if ( z == 0 )
              temp[y] = image[x][y];

              if ( z == 1 )
              { count = width - y;
              image[x][y] = temp[count];
              }
            }
        }


      }
    free (temp);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
