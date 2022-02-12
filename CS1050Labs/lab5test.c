/********************************
 * Author: Ethan Mick
 * Lab: Lab 5
 * Date: 1st October 2021
 * Course: CS 1050 - JimR
 * Semester: Fall 2021
 ********************************/
#include <stdio.h>

long double factorial ( int y ); /* efunc function prototype */

int main ( void ) /* function main begins program execution */
{
    /* Initialization Phase */
    int y = 100; /* value of n from efunc */

    /* printf calls efunc to approximate e and prints what efunc is returning */
    printf( "e=%.10Lf\n", factorial(y));

return 0;        
} /* end function main */

long double factorial ( int y )
{
    int fact = 1;
    int i;
    for( i=1; i<=y; i++ )
    {
        fact = fact * i;
        fact = 1 / fact;
    }
    
    return(fact);
}