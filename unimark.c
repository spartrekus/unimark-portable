
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[])
{

   FILE *source;
   int ch ; 
   int begin = 0 ; long mycount ; 
   float charpos = 1 ; 

   source = fopen( argv[ 1 ], "r");
   if( source == NULL )
   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }

   int nobegin ; 
   while( ( ch = fgetc(source) ) != EOF )
   {
      nobegin = 0;
      if ( begin == 1 )
      {
          if ( ch != '\n' )
           //printf( "%.0f: ", charpos++);   //for linecount
             printf( "<p>"); 
          else
             nobegin = 1;
      }

      if ( ch != '\n' ) putchar( ch );

      begin = 0;
      if ( ch == '\n' ) 
      { 
          begin = 1; mycount++; 
          if ( nobegin == 0 ) printf( "</p>\n"); 
      }
   }
   fclose(source);
   return 0;
}


