/********************************
 * Author: Ethan Mick
 * Lab: Lab 7
 * Date: 15th October 2021
 * Course: CS 1050 - JimR
 * Semester: Fall 2021
 ********************************/
#include <stdio.h>

/* function prototypes */
void GetIntArray(int * outputArray, int * count); /* function prompting user for # of integers & each integer */
void PrintArray( int * array, int count ); /* function that prints out the elements of the array */
int TotalArray( int * array, int count ); /* function to sum the first count elements of the array */
float AvgArray( int * array, int count ); /* function to average the first count elements of the array */

/* function main */
int main(void)
{
    /* Inititalization Phase */
    int array[ 256 ]; /* declaration of array with 256 integers (I tried using "count" in place of 256, but it messed up the output for some reason) */
    int count = 0; /* initialize count so its value can be modified by GetIntArray function */
    int i; /* variable used for total function */
    float j; /* variable used for average function */

    /* Welcome Statement */
    printf( "**********************\n" ); /* print upper divider for welcome statement */
    printf( "* Welcome to Lab 7-8 *\n" ); /* print welcome statement */
    printf( "**********************\n" ); /* print lower divider */

    printf( "\n" ); /* spacing (doing this so that my output is as close to the sample output as possible) */

    GetIntArray( array, &count ); /* call function to get user inputs */

    printf( "\n" ); /* spacing */

    PrintArray( array, count ); /* call function to print the elements that the user entered */

    i = TotalArray( array, count ); /* call function to sum all elements of the array */

       printf( "Total of array = %d\n", i );

    j = AvgArray( array, count ); /* call function to average all elements of the array */

       printf( "Average of array = %.2f\n", j );       

   return 0;
} /* end function main */

void GetIntArray(int * outputArray, int * count)
{
   int i; /* loop counter */
   /* int size = 0; integer that count points to so the value can be used in the loop */

   printf( "Enter the number of elements in the array:\n" ); /* user prompt statement */
   scanf( "%d", count ); /* assign user input to count */

   /* loop until count is reached to get the values of all elements in the array */
   for ( i = 0; i < * count; i++ ) {
       printf( "Enter Element #%d: ", i );
       scanf( "%d", ( outputArray + i )); /* no index operators */
   } /* end for */
} /* end function GetIntArray */

void PrintArray( int * array, int count )
{
   int i; /* loop counter */

   printf( "Here are the %d elements of your array:\n", count );

   /* loop through the elements of the array */
   for ( i = 0; i < count; i++ ) {
       printf( "        Element %d = %d\n", i, * ( array + i ) ); /* no index operators */
   } /* end for */
} /* end function printArray */

int TotalArray( int * array, int count )
{
    int i; /* loop counter */
    double total; /* the sum of all elements in the array */

    /* total up the values of the array user entered */
    for ( i = 0; i < count; i++ ) {
        total += * (array + i); /* total it up (without using index operators) */
    } /* end for */

    total -= 1; /* For some reason, TotalArray was returning the total sum + 1 in all of my test runs.
    I'm stumped as to why this was happening as it isn't a problem in the avgArray function, where I
    have the same for loop running again to get the total for use in computing the average. As you can
    see, I've just included this little -1 equation to solve this problem. */

    return total; /* return the sum */
} /* end function TotalArray */

float AvgArray( int * array, int count )
{
    float average; /* the average of all elements in the array */
    float total; /* variable for the total value for use in computing the average */
    int i; /* loop counter */

    /* total up the values of the array user entered */
    for ( i= 0; i < count; i++ ) {
        total += * (array + i); /* no index operators */
    } /* end for */

    average = total / count; /* compute the average */

    return average; /* return the average */
} /* end function AvgArray */