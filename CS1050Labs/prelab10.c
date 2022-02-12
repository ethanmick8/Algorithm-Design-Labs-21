/*
 * CS1050
 * Fall 2021
 * Prelab 10 Starter File
 * by Jim Ries
 */

// includes
#include <stdio.h>
#include <ctype.h>

// Symbolic Constants
#define S1 "Once there was a way to get back homeward"
#define S2 "\n\n\tYou get killed just for      \tlivin' in your\nAmerican skin."
#define S3 "In  these days, you can get no rice.  No razor blades, but you can get knife."
#define S4 "Now some guys they just give up living.  And start dying little by little, piece by piece.      "
#define STRINGCOUNT 4

////////////////
// Prototypes //
////////////////

// KillWhiteSpace should take a string, remove the whitespace from that string in-place,
// and return a pointer to the beginning of the resultant string (which really should
// be the same thing that was passed in originally - i.e., s).
char * KillWhiteSpace( char * s );


// Main
int main(void)
{
    char s[STRINGCOUNT][256]={S1,S2,S3,S4};

    printf("**** Original Strings ****\n");
    for ( int i = 0; i < STRINGCOUNT; i++ )
    {
        printf( "#%d: %s\n", i, s[i] );
    }

    printf( "\n\n**** Strings without whitespace ****\n" );
    for ( int i = 0; i < STRINGCOUNT; i++ )
    {
        printf( "#%d: %s\n", i, KillWhiteSpace( s[i] ) );
    }
}

char * KillWhiteSpace( char * s )
{
    int i = 0; // counter for for loop
    int j = 0; // counter for "copy" string

    // for loop that loops through the elements of a string, deleting all whitespace possiblities
    for ( int i = 0; s[i]; i++ ) 
    {
        if ( s[i] != ' ' && s[i] != '\t' && s[i] != '\n' ) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
    return s; // return the modified string
} // end function KillWhiteSpace