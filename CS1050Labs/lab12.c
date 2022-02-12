/*********************************
 * Name: Ethan Mick
 * Pawprint: ejmcmk
 * Date: November 19th 2021
 * Course: CS 1050 (JIMR)
 * Lab: Lab 12
*********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #define FILENAME "movies.dat"
#define MAXLINES 15 */

// structure definition for movie info
typedef struct {
    char moviename[256];
    long double grossrevenue;
    long double year;
} movieinfo;

// function prototypes
void readmovies( movieinfo array[], char * filename ); // read data from the file into an array of structures (movieinfo)
void printmovies( movieinfo array[], char * filename, int linescount ); // print the read data from the file out in a pretty lil organized format
void moviesort( movieinfo array[], int linescount, char * sortfield ); // sort the data in order of year of movie's release in descending order, then print

int main( int argc, char * argv[] )
{
    int linescount = 0; // counter for number of lines in the specified file
    char ch = 0; // character checker for line-counter while loop
    
    // open the file that is specified on the command line
    FILE * fp = fopen( argv[1], "r" );

    //read character by character and check for new line
    while( (ch = fgetc( fp ) ) != EOF ) 
    {
        if( ch == '\n' )
        {
        linescount++;
        }
    } // end while

    // tell the program what to do in situation in which a sorting parameter is given on the command line
    if ( argc == 3 )
    {
        if ( strcmp(argv[2], "Title\0" ) != 0 || strcmp( argv[2], "Gross\0" ) != 0 || strcmp( argv[2], "Year\0") != 0 ) // error check
        {
            printf( "Sort field must be one of Title, Gross, or Year if specified.\n" );
        } // end if
    } // end if
    
    // dynamically allocate memory for the array of strctures based on the size of the specified file
    // movieinfo * array = malloc( linescount * sizeof * array );
    movieinfo array[ 256 ];

    // call read function to read data from the file
    readmovies( array, argv[1] );

    // call function to sort the data accordingly
    moviesort( array, linescount, argv[2] );
    
    // call print function to write the sorted data into the file
    printmovies( array, argv[1], linescount );
    
    return 0;
} // end main

// function that reads data in the specified file
void readmovies( movieinfo array[], char * filename )
{
    FILE * fp;
    int i = 0;

    fp = fopen ( filename, "r" ); // open the file for reading

    if ( fp == NULL )
    {
        printf( "File could not be opened.\n" );
    } // end if

    /* char buffer[256];
    fgets( buffer, 256, fp ); */

    // loop through the file, reading all of the data into the array of structs
    while ( !feof(fp) )
    {
        fscanf( fp, "%s %Lf %Lf", array[i].moviename, &array[i].grossrevenue, &array[i].year );
        i++;
    } // end while
    
    /* loop through the file, reading all of the data into the array of structs
    while ( !feof(fp) )
    {
        movieinfo * x = array + i;
        sscanf( buffer, "%s %Lf %Lf", x->moviename, &x->grossrevenue, &x->year );
        fgets( buffer, 256, fp );
        printf("%s\n", array[i].moviename );
        i++; 
    } // end while */

    fclose( fp ); // close the file
} // end function readmovies

// function that writes in the data that was read from the specified file and prints it
void printmovies( movieinfo array[], char * filename, int linescount )
{
    int i = 0;

    // Header information variables
    char title[] = { "Title" };
    char gross[] = { "Gross" };
    char yeara[] = { "Year" };

    FILE *fp;

    fp = fopen ( filename, "w" );

    if ( fp == NULL )
    {
        printf( "File could not be opened.\n" );
    } // end if
    else if ( fp && !feof(fp) )
    {
        // column headers/title
        fprintf( fp, "Sorted movies:\n" );
        fprintf( fp, "%50s%21s%21s\n", title, gross, yeara );

        // write all the data into the file from the array of structures
        for ( i = 0; i <= (linescount-1); i++ )
        {
            fprintf( fp, "%50s %20.0Lf %20.0Lf\n", array[i].moviename, array[i].grossrevenue, array[i].year );
        } // end for

        fclose( fp );
    } // end else
} // end function printmovies

// function that sorts the data in the spcified file based on the specified sort argument
void moviesort( movieinfo array[], int linescount, char * sortfield ) 
{
    int i = 0;
    int j = 0;
    
    // dynamically allocate memory for the temporary holder in bubble sort
    movieinfo * temp = malloc( linescount * sizeof * array );

    // sort the data according to the Year the movie was released
    if ( strcmp( sortfield, "Year\0" ) == 0 )
    {
for (i = 0; i < linescount; i++) {   // loop n times - 1 per element
for (j = 0; j < linescount - i - 1; j++) { // last i elements are sorted already
if (array[j].year > array[j + 1].year ) {  // swap if order is broken
* temp = array[j];
array[j] = array[j + 1];
array[j + 1] = * temp;
}
}
}
}

// sort the data according to the Gross revenue
else if ( strcmp(sortfield, "Gross\0" ) == 0 ) 
{
for (i = 0; i < linescount; i++) {   // loop n times - 1 per element
for (j = 0; j < linescount - i - 1; j++) { // last i elements are sorted already
if (array[j].grossrevenue > array[j + 1].grossrevenue ) {  // swap if order is broken
* temp = array[j];
array[j] = array[j + 1];
array[j + 1] = * temp;
}
}
}
}

// sort the data alphabetically according to title (Whether sortfield is "title" or nonexisitent)
else
{
for (i = 0; i < linescount; i++) {   // loop n times - 1 per element
for (j = 0; j < linescount - i - 1; j++) { // last i elements are sorted already
if ( strcmp( array[j].moviename, array[j + 1].moviename ) > 0 ) {  // swap if order is broken
* temp = array[j];
array[j] = array[j + 1];
array[j + 1] = * temp;
}
}
}
}

    /* int x = 0;

    // Header information variables
    char title[] = { "Title" };
    char gross[] = { "Gross" };
    char yeara[] = { "Year" };
    

    FILE *fp;

    fp = fopen ( FILENAME, "a" );

    if ( fp == NULL )
    {
        printf( "File could not be opened.\n" );
    } // end if
    else if ( fp && !feof(fp) )
    {
        // column headers
        fprintf( fp, "\nYear:\n" ); // print header for new data
        fprintf( fp, "%50s%21s%21s\n", title, gross, yeara );

        for ( x = 0; x <= (MAXLINES-1); x++ )
        {
            fprintf( fp, "%50s %20.0Lf %20.0Lf\n", array[x].moviename, array[x].grossrevenue, array[x].year );
        } // end for

        fclose( fp );
    } // end else */
} // end function moviesort


