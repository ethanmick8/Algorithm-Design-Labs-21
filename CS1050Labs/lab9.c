/********************************
 * Author: Ethan Mick
 * Lab: Lab 9
 * Date: 29th October 2021
 * Course: CS 1050 - JimR
 * Semester: Fall 2021
 ********************************/
#include <stdio.h>
#include <math.h>

/* function prototypes */
void getstring( char * string );
int stringlength( char * string );
int stringsegments( char * string, float length );
void reverse( char * string, int length, int split );

int main(void)
{
    /* Initialization Phase */
    char string[ 256 ]; /* declare character array string with 256 characters (ample space) */
    int length = 0; /* size variable (string length) for use in calculation */
    int split = 0; /* variable that holds the number of segments (returned from function) */

    /* Welcome Statement */
    printf( "*** Welcome to Lab 9 ***\n" );

    /* Call function to get string from user */
    getstring( string );

    /* Call function to determine length of user-entered string */
    length = stringlength( string );

    printf( "\n" ); /* spacing */

    /* Call function to calculate and return the number of segments in user-entered string */
    split = stringsegments( string, length );

    /* Call function to reverse order of segments and print the new string */
    reverse( string, length, split );

    // Thank You Statement
    printf( "\n*** Thank you for doing Lab 9 ***\n" );

    return 0;
} /* end function main */

/* function that gets a string from the user */
void getstring( char * string )
{
    printf("Please enter a string: " ); /* prompt user */
    scanf( "%s", string ); /* scan user-entered string */
    printf( "You entered: %s", string ); /* print user-entered string */
} /* end function getstring */

/* function that calculates the length of the string */
int stringlength( char * string )
{
    int length = 0; // size of string

    // while loop that counts the size by incrementing string until the null character is reached
    while ( * string != '\0' ) {
        length++;
        string++;
    } // end while

    return length; // returns the length of the string
} // end function string length

/* function that splits the string into segments of 5 */
int stringsegments( char * string, float length )
{
    int i = 0; /* loop counter */
    int split = 0; /* split variable (will hold the number of segments) */

    split = (int)(ceil(length/5)); /* divide length by 5, using ceil (math.h) to round to next integer */
    
    printf( "There are %d segments in the string.\n", split );

    return split; /* return the number of segments */
}

/* function that reverses the order of the string segments and prints the new string */
void reverse( char * string, int length, int split )
{
    int i; /* loop counter */
    int count = 0; /* variable for use in while statement to obtain first segment */
    int x = 0; /* variable that holds the value of temporary correctly so that loop functions right */


    printf( "The modified string is: " ); /* statement */

    /* for loop that prints the last element */
    for ( i = 5; i <= 10; i++ ) {
        printf( "%c", * (string + i ));
    }

    /* for loop that elements to prints the string elements backwards */
    for ( i = 0; i < split - 1; i++ ) {
        count = 1;

        /* print segment of 5 characters */
        while ( count != 6 ) {
            printf( "%c", * (string + x) );
            x++;
            count++;
        }
    }
}