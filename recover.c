#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
  int count = 0;
  char filename[15] ;
  FILE *outptr;

  if ( argc != 2 )
  {
   printf ("Please select only one file \n") ;
   return 1;
  }

  char *infile = argv[1];
  FILE *raw = fopen (infile, "r" ) ;
  if (raw == NULL)
  {
   printf("Could not open file \n");
   return 1;
  }

  fseek (raw, 0, SEEK_END) ;
  long size = ftell (raw) / 512;
  fseek(raw, 0, SEEK_SET) ;
  BYTE (*buffer) = calloc (512, sizeof(BYTE) ) ;

  for ( long x = 0; x < size; x++)
    {
      fread (buffer, sizeof(BYTE), 512, raw);
      if ( count == 0 &&
            (buffer [0] != 0xff ||
            buffer [1] != 0xd8 ||
            buffer [2] != 0xff ||
            (buffer[3] & 0xf0) != 0xe0)
         )
         continue ;
      else if ( count == 0 &&
            buffer [0] == 0xff &&
            buffer [1] == 0xd8 &&
            buffer [2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0
         )
         {  sprintf (filename,"%03i.jpg", count);
            outptr = fopen (filename, "w");
            fwrite (buffer, sizeof(BYTE), 512, outptr ) ;
            count++;
         }
      else if ( count > 0 &&
            (buffer [0] != 0xff ||
            buffer [1] != 0xd8 ||
            buffer [2] != 0xff ||
            (buffer[3] & 0xf0) != 0xe0)
         )
           fwrite (buffer, sizeof(BYTE), 512, outptr) ;
      else if ( count > 0 &&
                 buffer [0] == 0xff &&
                 buffer [1] == 0xd8 &&
                 buffer [2] == 0xff &&
                 (buffer[3] & 0xf0) == 0xe0
              )
            {  fclose (outptr) ;
               count++;
               sprintf (filename,"%03i.jpg", count);
               outptr = fopen (filename, "w");
               fwrite (buffer, sizeof(BYTE), 512, outptr ) ;
         }

    }
fclose (outptr);
free (buffer) ;
return 0;
}
