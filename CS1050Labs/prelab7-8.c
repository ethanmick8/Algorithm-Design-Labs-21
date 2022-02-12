#include <stdio.h>

/* function prototypes */
void getCount(int * outputInt);
void getIntegerArray(int * outputIntArray, int count);
void printArray(int array[], int size);

/* function main */
int main(void)
{
    /* Initialization */
    int outputInt = 0; /* number of integers in the array as specified by user input */
    int array[ 256 ]; /* declaration of array a */
    int outputIntArray; /* output from function that get's array values from user input */

    /* Welcome Statement */
    printf( "*************************\n" ); /* print upper divider for welcome statement */
    printf( "* Welcome to Prelab 7-8 *\n" ); /* print welcome statement */
    printf( "*************************\n" ); /* print lower divider */

    printf( "\n" ); /* spacing */

    getCount( &outputInt ); /* call function that asks user how many integers they want to use */

    getIntegerArray( array, outputInt ); /* call function that gets values for each element of the array from user input */


    printf( "\n" ); /* spacing */
    printf( "*************************\n" ); /* divider */

    printArray( array, outputInt );

    return 0;
} /* end function main */

void getCount( int * outputInt )
{
   printf( "How many integers would you like to enter?\n"); /* prompt user */
   scanf( "%d", outputInt); /* scan user input */
}

void getIntegerArray(int * outputIntArray, int count)
{
   int i; /* loop counter */

   /* loop through until the number of integers user entered has been reached */
   for ( i = 0; i < count; i++ ) {
       printf( "        Enter Integer #%d: ", i+1 );
       scanf( "%d", ( outputIntArray + i ));
   }
}

void printArray(int array[], int size)
{
   int i; /* loop counter */

   printf( "You entered an array with %d elements:\n", size );

   /* loop through the elements of the array */
   for ( i = 0; i < size; i++ ) {
       printf( "        array[%d]=%d\n", i, array[i] );
   }

}
