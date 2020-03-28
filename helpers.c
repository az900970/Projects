#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{   double average = 0;
    int final = 0;
    for ( int x = 0; x < height; x++ )
     {
         for ( int y = 0; y < width; y++)
         {
            average = (image[x][y].rgbtBlue + image[x][y].rgbtGreen + image[x][y].rgbtRed) / 3.0;
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
    double sepiared = 0;
    double sepiagreen = 0;
    double sepiablue = 0;

    for (int x = 0; x < height; x++)
    {
       for (int y = 0; y < width; y++)
        {
            sepiared = round ( (0.393 * image[x][y].rgbtRed) + (0.769 * image[x][y].rgbtGreen)
            + (0.189 * image[x][y].rgbtBlue) ) ;
            sepiagreen = round ( (0.349 * image[x][y].rgbtRed) + (0.686 * image[x][y].rgbtGreen)
            + (0.168 * image[x][y].rgbtBlue) ) ;
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
     {printf ("ERROR: Insufficient memory");
      return;
     }
    for ( int x = 0; x < height; x++)
      {
        for ( int z = 0; z < 2; z++)
        {
           for ( int y = 0; y < width; y++)
            { if ( z == 0 )
              temp[y] = image[x][y];

              if ( z == 1 )
              { count = (width - 1) - y;
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
    for ( int x = 0; x < height - 1; x ++ )
    {
       for (int y = 0; y < width - 1; y++ )
       {
          if ( x == 0 && y == 0 )  // Top Left Corner element
          {
              image[x][y].rgbtRed = round ( image[x][y].rgbtRed + image[x][y + 1].rgbtRed + image[x + 1 ][y].rgbtRed
              + image[x + 1][y + 1].rgbtRed ) / 4.0 ;
              image[x][y].rgbtBlue = round ( image[x][y].rgbtBlue + image[x][y + 1].rgbtBlue + image[x + 1 ][y].rgbtBlue
              + image[x + 1][y + 1].rgbtBlue ) / 4.0 ;
              image[x][y].rgbtGreen = round ( image[x][y].rgbtGreen + image[x][y + 1].rgbtGreen + image[x + 1 ][y].rgbtGreen
              + image[x + 1][y + 1].rgbtGreen ) / 4.0 ;
          }

          if ( x == 0 && y > 0 && y < width - 1 ) // Top Edge of picture
          {
              image[x][y].rgbtRed = round ( image[x][y - 1].rgbtRed +  image[x][y].rgbtRed + image[x][y + 1].rgbtRed
              + image[x + 1 ][y - 1].rgbtRed + image[x + 1][y].rgbtRed + image[x + 1][y + 1].rgbtRed ) / 6.0 ;
              image[x][y].rgbtBlue = round ( image[x][y - 1].rgbtBlue +  image[x][y].rgbtBlue + image[x][y + 1].rgbtBlue +
              image[x + 1 ][y - 1].rgbtBlue + image[x + 1][y].rgbtBlue + image[x + 1][y + 1].rgbtBlue ) / 6.0 ;
              image[x][y].rgbtGreen = round ( image[x][y - 1].rgbtGreen +  image[x][y].rgbtGreen + image[x][y + 1].rgbtGreen
              + image[x + 1 ][y - 1].rgbtGreen + image[x + 1 ][y].rgbtGreen + image[x + 1][y + 1].rgbtGreen ) / 6.0 ;
          }

          if ( x == 0 && y == width - 1 )  // Top Right Corner Element
          {
              image[x][y].rgbtRed = round ( image[x][y].rgbtRed + image[x][y - 1].rgbtRed + image[x + 1 ][y].rgbtRed
              + image[x + 1][y - 1].rgbtRed ) / 4.0 ;
              image[x][y].rgbtBlue = round ( image[x][y].rgbtBlue + image[x][y - 1].rgbtBlue + image[x + 1 ][y].rgbtBlue
              + image[x + 1][y - 1].rgbtBlue ) / 4.0 ;
              image[x][y].rgbtGreen = round ( image[x][y].rgbtGreen + image[x][y - 1].rgbtGreen + image[x + 1 ][y].rgbtGreen
              + image[x + 1][y - 1].rgbtGreen ) / 4.0 ;
          }

          if ( x > 0 && x < height - 1 && y == 0 )  // Left edge of picture
          {
              image[x][y].rgbtRed = round ( image[x - 1][y].rgbtRed +  image[x][y].rgbtRed + image[x + 1][y].rgbtRed
              + image[x - 1][y + 1].rgbtRed + image[x][y + 1].rgbtRed + image[x + 1][y + 1].rgbtRed ) / 6.0 ;
              image[x][y].rgbtBlue = round ( image[x - 1][y].rgbtBlue +  image[x][y].rgbtBlue + image[x + 1][y].rgbtBlue
              + image[x - 1][y + 1].rgbtBlue + image[x][y + 1].rgbtBlue + image[x + 1][y + 1].rgbtBlue ) / 6.0 ;
              image[x][y].rgbtGreen = round ( image[x - 1][y].rgbtGreen +  image[x][y].rgbtGreen + image[x + 1][y].rgbtGreen
              + image[x - 1][y + 1].rgbtGreen + image[x][y + 1].rgbtGreen + image[x + 1][y + 1].rgbtGreen ) / 6.0 ; ;
          }

           if ( x > 0 && x < height - 1 && y == width - 1 )  // Right edge of picture
          {
              image[x][y].rgbtRed = round ( image[x - 1][y].rgbtRed +  image[x][y].rgbtRed + image[x + 1][y].rgbtRed
              + image[x - 1][y - 1].rgbtRed + image[x][y - 1].rgbtRed + image[x + 1][y - 1].rgbtRed ) / 6.0 ;
              image[x][y].rgbtBlue = round ( image[x - 1][y].rgbtBlue +  image[x][y].rgbtBlue + image[x + 1][y].rgbtBlue
              + image[x - 1][y - 1].rgbtBlue + image[x][y - 1].rgbtBlue + image[x + 1][y - 1].rgbtBlue ) / 6.0 ;
              image[x][y].rgbtGreen = round ( image[x - 1][y].rgbtGreen +  image[x][y].rgbtGreen + image[x + 1][y].rgbtGreen
              + image[x - 1][y - 1].rgbtGreen + image[x][y - 1].rgbtGreen + image[x + 1][y - 1].rgbtGreen ) / 6.0 ; ;
          }

           if ( x == height - 1 && y == 0 )  // Bottom Left Corner element
          {
              image[x][y].rgbtRed = round ( image[x][y].rgbtRed + image[x][y + 1].rgbtRed + image[x - 1 ][y].rgbtRed
              + image[x - 1][y + 1].rgbtRed ) / 4.0 ;
              image[x][y].rgbtBlue = round ( image[x][y].rgbtBlue + image[x][y + 1].rgbtBlue + image[x - 1 ][y].rgbtBlue
              + image[x - 1][y + 1].rgbtBlue ) / 4.0 ;
              image[x][y].rgbtGreen = round ( image[x][y].rgbtGreen + image[x][y + 1].rgbtGreen + image[x - 1 ][y].rgbtGreen
              + image[x - 1][y + 1].rgbtGreen ) / 4.0 ;
          }

          if ( x == height - 1 && y > 0 && y < width - 1 ) // Bottom Edge of picture
          {
              image[x][y].rgbtRed = round ( image[x][y - 1].rgbtRed +  image[x][y].rgbtRed + image[x][y + 1].rgbtRed
              + image[x - 1 ][y - 1].rgbtRed + image[x - 1][y].rgbtRed + image[x - 1][y + 1].rgbtRed ) / 6.0 ;
              image[x][y].rgbtBlue = round ( image[x][y - 1].rgbtBlue +  image[x][y].rgbtBlue + image[x][y + 1].rgbtBlue +
              image[x - 1 ][y - 1].rgbtBlue + image[x - 1][y].rgbtBlue  + image[x - 1][y + 1].rgbtBlue ) / 6.0 ;
              image[x][y].rgbtGreen = round ( image[x][y - 1].rgbtGreen +  image[x][y].rgbtGreen + image[x][y + 1].rgbtGreen
              + image[x - 1 ][y - 1].rgbtGreen + image[x - 1][y].rgbtGreen + image[x - 1][y + 1].rgbtGreen ) / 6.0 ;
          }

           if ( x == height - 1 && y == width - 1 )  // Bottom Right Corner Element
          {
              image[x][y].rgbtRed = round ( image[x][y - 1].rgbtRed + image[x][y].rgbtRed + image[x - 1 ][y].rgbtRed
              + image[x - 1][y - 1].rgbtRed ) / 4.0 ;
              image[x][y].rgbtBlue = round ( image[x][y - 1].rgbtBlue + image[x][y].rgbtBlue + image[x - 1 ][y].rgbtBlue
              + image[x - 1][y - 1].rgbtBlue ) / 4.0 ;
              image[x][y].rgbtGreen = round ( image[x][y - 1].rgbtGreen + image[x][y].rgbtGreen + image[x - 1 ][y].rgbtGreen
              + image[x - 1][y - 1].rgbtGreen ) / 4.0 ;
          }
           if ( x != 0 && x < height - 1 && y != 0 && y < width - 1 )
          {
              image[x][y].rgbtRed = round ( image[x - 1][y - 1].rgbtRed +  image[x - 1][y].rgbtRed + image[x - 1][y + 1].rgbtRed
              + image[x][y - 1].rgbtRed + image[x][y].rgbtRed + image[x][y + 1].rgbtRed
              + image[x + 1][y - 1].rgbtRed + image[x + 1][y].rgbtRed + image[x + 1][y + 1].rgbtRed) / 9.0 ;
              image[x][y].rgbtBlue = round ( image[x - 1][y - 1].rgbtBlue +  image[x - 1][y].rgbtBlue + image[x - 1][y + 1].rgbtBlue
              + image[x][y - 1].rgbtBlue + image[x][y].rgbtBlue + image[x][y + 1].rgbtBlue
              + image[x + 1][y - 1].rgbtBlue + image[x + 1][y].rgbtBlue + image[x + 1][y + 1].rgbtBlue) / 9.0 ;
              image[x][y].rgbtGreen = round ( image[x - 1][y - 1].rgbtGreen +  image[x - 1][y].rgbtGreen + image[x - 1][y + 1].rgbtGreen
              + image[x][y - 1].rgbtGreen + image[x][y].rgbtGreen + image[x][y + 1].rgbtGreen
              + image[x + 1][y - 1].rgbtGreen + image[x + 1][y].rgbtGreen + image[x + 1][y + 1].rgbtGreen) / 9.0 ;
          }
       }
    }
    return;
}
