#include <stdio.h>

/* function prototypes */
void printArray(int array[], int size);
int InitializeArray(int array[], int begin, int end, int increment);

/* function main begins program execution */
int main(void)
{
   /* Intitialization Phase */ 
   int array[ 256 ];
   int j; /* variable used to hold passed InitializeArray value */

   j = InitializeArray( array, 2, 20, 2 ); /* Assign the number of elements returned from InitializeArray to j */
  
      printf( "First Array:\n" ); /* Print title for first array section */
      printArray( array, j );

   j = InitializeArray( array, 1, 97, 3 ); /* Assign the number of elements returned from InitializeArray to j */
  
      printf( "Second Array:\n" ); /* Print title for first array section */
      printArray( array, j );

return 0;
}

int InitializeArray(int array[], int begin, int end, int increment)
{
    int i; /* loop counter */ 
    int size = ( (end - begin) / (increment) ) + 1; /* determine the number of elements to initialize given begin, end, and increment */

    /* loop through the parameters until size is reached */
    for ( i = 0; i < size; i++ ) { 
           array[i] = begin;
           begin += increment;
    }

return size; /* returns the number of initialized elements */
}

void printArray(int array[], int size)
{
    int i; /* loop counter */

    /* loop through the array */
    for  ( i = 0; i < size; i++ ) {
        printf( "           Element %d = %d\n", i, array[i] );
    }
}
