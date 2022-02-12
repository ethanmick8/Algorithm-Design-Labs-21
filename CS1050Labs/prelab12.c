#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "movies.dat"
#define MAXLINES 15
#define MAXTITLE 30

// structure definition for movie info
typedef struct {
    char moviename[256];
    long double grossrevenue;
    long double year;
} movieinfo;

// function prototypes
void readmovies( movieinfo array[] ); // read data from the file into an array of structures (movieinfo)
void printmovies( movieinfo array[] ); // print the read data from the file out in a pretty lil organized format
void moviesort( movieinfo array[] ); // sort the data in order of year of movie's release in descending order, then print

int main(void)
{

    movieinfo * array = malloc( MAXLINES * sizeof * array );
    int i = 0;

    // call read function to read data from the file
    readmovies( array );

    // call print function to print original data file
    printmovies( array );
    
    // call function to sort and print the movies in order of most recent to least recent
    moviesort( array );

    return 0;
} // end main

void readmovies( movieinfo array[] )
{
    FILE *fp;
    int i = 0;

    fp = fopen ( FILENAME, "r" ); // open the file for reading

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

void printmovies( movieinfo array[] )
{
    int i = 0;

    // Header information variables
    char title[] = { "Title" };
    char gross[] = { "Gross" };
    char yeara[] = { "Year" };

    FILE *fp;

    fp = fopen ( FILENAME, "w" );

    if ( fp == NULL )
    {
        printf( "File could not be opened.\n" );
    } // end if
    else if ( fp && !feof(fp) )
    {
        // column headers
        fprintf( fp, "Original:\n" );
        fprintf( fp, "%50s%21s%21s\n", title, gross, yeara );

        for ( i = 0; i <= (MAXLINES-1); i++ )
        {
            fprintf( fp, "%50s %20.0Lf %20.0Lf\n", array[i].moviename, array[i].grossrevenue, array[i].year );
        } // end for

        fclose( fp );
    } // end else
} // end function printmovies

void moviesort( movieinfo array[] ) 
{
    int i = 0;
    int j = 0;
    movieinfo * temp = malloc( MAXLINES * sizeof * array );
    for (i = 0; i < MAXLINES; i++) {   // loop n times - 1 per element
        for (j = 0; j < MAXLINES - i - 1; j++) { // last i elements are sorted already
            if (array[j].year < array[j + 1].year ) {  // swap if order is broken
                * temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = * temp;
            }
        }
    }

    int x = 0;

    // Header information variables
    char title[] = { "Title" };
    char gross[] = { "Gross" };
    char yeara[] = { "Year" };
    
    /* disclaimer: the rest of this function is just essentially the "printmovies()" function,
    i just didn't have time to make printmovies() universal and also I could've probably
    just called that function here and it would've worked just fine with about 20 less lines
    of code. It works tho so fuck it */

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
    } // end else    
} // end function moviesort
