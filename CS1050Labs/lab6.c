/********************************
 * Author: Ethan Mick
 * Lab: Lab 6
 * Date: 8th October 2021
 * Course: CS 1050 - JimR
 * Semester: Fall 2021
*********************************/
#include <stdio.h>

/* function prototypes */
void MultArrays( int array1[], int array2[], int array3[], int size );
void printArray( int array1[], int array2[], int array3[], int size ); 
int InitFirstArray1( int array1[], int begin, int end, int increment ); 
int InitFirstArray2( int array2[], int begin, int end, int increment );
int InitSecondArray1( int array1[], int begin, int end, int increment );
int InitSecondArray2( int array2[], int begin, int end, int increment );

/* function main */
int main(void)
{
   int array1[ 100 ]; /* declaration of array 1 with 100 elements */
   int array2[ 100 ]; /* 2nd array */
   int array3[ 100 ]; /* 3rd array (1 and 2 multiplied) */
   int j; /* variable that will be assigned to the return value of InitFirstArray1 function */
   int i; /* variable that will be assigned to the return value of InitFirstArray2 function */
   int m; /* variable that will be assigned to the return value of InitSecondArray1 function */
   int r; /* variable that will be assigned to the return value of InitSecondArray2 function */

   printf( "First Arrays:\n"); /* print title for first arrays section */
      
       j = InitFirstArray1( array1, 1, 31, 3 ); /* assign # of elements returned from the function for first array1 to j */
       i = InitFirstArray2( array2, 2, 52, 5 ); /* assignment for the function for first array 2 elements */
       
            MultArrays( array1, array2, array3, j ); /* j is used because j is the amount of elements and the lab says we can assume j and i are equivalent (they should be anyways) */
    
            printArray( array1, array2, array3, i ); /* call printArray function to print the values for First Arrays */

   printf( "\n" ); /* spacing between the sections */         

   printf( "Second Arrays:\n"); /* print title for second arrays section */
      
       m = InitSecondArray1( array1, 22, 0, 2 ); /* assignment for for the function for second array1 elements */
       r = InitSecondArray2( array2, 84, 7, 7 ); /* assignment for for the function for second array2 elements */

           MultArrays( array1, array2, array3, m ); /* same situation as the call in First Arrays section */

           printArray( array1, array2, array3, r ); /* same as well, again since it is assumed/known that each array has the same # of elements, m and r should be equivalent sizes */
       
return 0;
}

/* Function used to initialize values for array1 */
int InitFirstArray1( int array1[], int begin, int end, int increment )
{
    int i; /* loop counter */ 
    int size = ( (end - begin) / (increment) ) + 1; /* determine the number of elements to initialize given begin, end, and increment */

    /* loop through the parameters until size is reached */
    for ( i = 0; i < size; i++ ) { 
        array1[i] = begin;
        begin += increment;
    }

    return size; /* returns the number of elements */        
}

/* Function used to initialize values for array2 */
int InitFirstArray2( int array2[], int begin, int end, int increment )
{ 
    int i; /* loop counter */ 
    int size = ( (end - begin) / (increment) ) + 1; /* determine the number of elements to initialize given begin, end, and increment */

    /* loop through the parameters until size is reached */
    for ( i = 0; i < size; i++ ) { 
        array2[i] = begin;
        begin += increment;
    } /* end for */

    return size; /* returns the number of elements */
}

int InitSecondArray1( int array1[], int begin, int end, int increment )
{
    int i; /* loop counter */ 
    int size = ( (begin - end) / (increment) ) + 1; /* determine the number of elements to initialize given begin, end, and increment */

    /* loop through the parameters until size is reached */
    for ( i = 0; i < size; i++ ) { 
        array1[i] = begin;
        begin -= increment;
    } /* end for */

    return size; /* returns the number of elements */
}

int InitSecondArray2( int array2[], int begin, int end, int increment )
{
    int i; /* loop counter */ 
    int size = ( (begin - end) / (increment) ) + 1; /* determine the number of elements to initialize given begin, end, and increment */

    /* loop through the parameters until size is reached */
    for ( i = 0; i < size; i++ ) { 
        array2[i] = begin;
        begin -= increment;
    } /* end for */

    return size; /* returns the number of elements */
}

/* Function used to multiply the values of array1 and array2 to form array3 */
void MultArrays( int array1[], int array2[], int array3[], int size )
{
    int i; /* loop counter */

    /* for loop that multiplies array1 and array2 to form array3 for the specified size */
    for ( i = 0; i < size; i++ ) {
        array3[i] = array1[i] * array2[i];
    } /* end for */
}

/* Print Function */
void printArray( int array1[], int array2[], int array3[], int size )
{
   int i; /* loop counter */

   /* loop through the arrays for each of their values */
   for  ( i = 0; i < size; i++ ) {
        printf( "        Array 1 Element %2d = %3d Array 2 Element %2d = %3d Array 3 Element %2d = %3d\n", i, array1[i], i, array2[i], i, array3[i] );
   } /* end for */    
}

/* End Note: I feel like there might've been a way to do this with less functions 
(i.e. at least grouping the InitArray functions to work for both array1 and array2
at the same time) but I wasn't sure how to go about this and after spending some
time trying I just decided to use what I learned from the prelab, because I didn't 
see anything in the lab description/rules that said I couldn't use functions for 
each array to get there. Hopefully that's okay. Thanks! - Ethan */
