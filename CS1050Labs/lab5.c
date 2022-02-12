/********************************
 * Author: Ethan Mick
 * Lab: Lab 5
 * Date: 1st October 2021
 * Course: CS 1050 - JimR
 * Semester: Fall 2021
 ********************************/
#include <stdio.h>

long double efunc ( int n, long double x ); /* efunc function prototype */

int main ( void ) /* function main begins program execution */
{
    /* Initialization Phase */
    int n = 200; /* value of n from efunc (I used a very high value to ensure precision) */
    long double x = 1.0f;

    /* printf calls efunc to approximate e and prints what efunc is returning */
    printf( "e=%.10Lf\n", efunc( n, x ));

return 0;        
} /* end function main */

/* function efunc  defintion */
long double efunc ( int n, long double x )
{
   double result = 1.0f; /* intitialize result for series below */

    for ( int i = n - 1; i > 0; --i ) {
        result = 1 + x * result / i; /* use the sum of the first n terms of Taylor series */
    } /* end for */

    return result; /* return the result for use in main */
} /* end function efunc */

