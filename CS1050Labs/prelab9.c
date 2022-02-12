#include <stdio.h>

// function prototypes
void getstring( char * string );
int stringlength( char * string );
void reversestring( char * string, int size );

// main
int main ( void )
{
    // Initialization Phase
    char string[ 256 ]; // declaration of string
    int size = 0; // variable for use in stringlength function (to be assigned string length)

    // Welcome Statement
    printf( "*** Welcome to Pre-Lab 9 ***\n" );

    // Call function to get string from user
    getstring( string );

    // Call function to determine (and print) length of user-entered string
    size = stringlength( string );

    // Call function to reverse the order of (and print) user-entered string
    reversestring( string, size );

    // Call function to determine (and print) length of reversed string
    size = stringlength( string );

    // Thank You Statement
    printf( "*** Thank you for doing Pre-Lab 9 ***\n" );

    return 0;
} // end function main

void getstring( char * string )
{
    printf("Please enter a string: " ); // prompt user
    scanf( "%s", string ); // scan user-entered string
    printf( "You entered: %s", string ); // print user-entered string
} // end function getstring

int stringlength( char * string )
{
    int size = 0; // size of string

    // while loop that counts the size by incrementing string until the null character is reached
    while ( * string != '\0' ) {
        size++;
        string++;
    } // end while

    printf( "\nThat string is %d in length.\n", size );

    return size; // returns the length of the string
} // end function string length

void reversestring( char * string, int size )
{
    int i; // loop counter

    // statement
    printf( "The reversed string is: " );

    // for loop that prints the string character by character starting with the last non-null character
    for ( i = size - 1; i >= 0; i-- ) {
        printf( "%c", * (string + i) );
    } // end for 
} // end function reversestring
