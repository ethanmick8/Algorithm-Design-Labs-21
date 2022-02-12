#include <stdio.h>

// symbolic constants
#define MAXPLAYERS 10

// function prototypes
int FillArrays( char Names[][256], float Avgs[], char * FileName );
void PrintArrays( char Names[][256], float Avgs[], int count );

int main(void)
{
    char Names[MAXPLAYERS][256];
    float Avgs[MAXPLAYERS];
    int count = 0;

    // call function to fill arrays with data
    count = FillArrays( Names, Avgs, "prelabstats.dat" );
    
    // call function to print out the data
    PrintArrays( Names, Avgs, count );

    return 0;
} // end main

int FillArrays( char Names[][256], float Avgs[], char * FileName )
{
    FILE * fp;
    int count = 0;

    fp = fopen( FileName, "r" );

    if ( NULL != fp )
    {
        while ( !feof(fp) )
        {
            if ( 0 != fscanf( fp, "%s %f\n", Names[count], &Avgs[count] ) )
            {
                count++;
            } // end if
        } // end while
        fclose(fp);
    } // end if
    else
    {
        printf( "Unable to open file %s\n", FileName );
    } // end else

    return count;
} // end function FillArrays

void PrintArrays( char Names[][256], float Avgs[], int count )
{
    int i; // loop counter

    printf( "\n\nToday's Lineup:\n\n" );

    for ( i = 0; i < count; i++ )
    {
        printf ( "%s: %3.3f\n", Names[i], Avgs[i] );
    } // end for
    
    printf( "\n" );
} // end function PrintArrays