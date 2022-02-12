/********************************
 * Author: Ethan Mick
 * Lab: Lab 10
 * Date: 5th November 2021
 * Course: CS 1050 - JimR
 * Semester: Fall 2021
********************************/
// Includes
#include <stdio.h>
// Need any other includes? - yes, I've included them below
#include <string.h>
#include <stdlib.h>

// Symbolic Constants
#define CLEARTEXT \
"Haven't felt right in a week\n"\
"And I'm thinning out\n"\
"And it hurts bad\n"\
"I gotta get back\n"\
"\n"\
"Hot head and dreamless sleep\n"\
"I could just slip down\n"\
"And on the wrong track\n"\
"I gotta get back\n"\
"\n"\
"I wanna spend the entire year\n"\
"Just face down\n"\
"And on my own time\n"\
"I wanna waste mine\n"\
"\n"\
"And spend the rest of it asking myself\n"\
"\"Is this who you are?\"\n"\
"And I don't know\n"\
"It just feels gross\n"\
"\n"\
"I don't think there's anything wrong\n"\
"I don't think there's anything wrong\n"\
"And I don't think there's anything wrong\n"\
"I don't think there's anything wrong\n"\
"\n"\
"Sunlight on the back of my arms\n"\
"Just thins me out\n"\
"To a different time\n"\
"I wanna waste mine\n"\
"\"\\\?\n\n\t\t- Snail Mail"

// Function Prototypes
void Encrypt(const char * in, char * out, int displacement);
void Decrypt(char * out, char * decryptout, int displacement);


// Function Main
int main(void)
{
    const char in[ 1000 ] = { CLEARTEXT }; // declaration of input array, which holds the CLEARTEXT string
    char out[ 1000 ]; // output array (encryption)
    char decryptout[ 1000 ]; // output array for decryption
    int displacement = 5; // value of displacement specified to be used in this lab


    // Print original string
    printf( "************************************\n" );
    printf( "* Cleartext:                       *\n" );
    printf( "%s\n", in );
    printf( "************************************\n" );

    // print spacers for encrypted string
    printf( "\n************************************\n" );
    printf( "* CipherText using   5:            *\n" );

    // Call encrypt function to encrypt CLEARTEXT
    Encrypt( in, out, displacement );

    // Print the encrypted string
    printf( "%s\n", out );

    // more spacing
    printf( "************************************\n" );

    // spacing for decrypted string
    printf( "\n************************************\n" );
    printf( "* Decrypted CipherText:            *\n" );

    // Call to decrypt
    Decrypt( out, decryptout, displacement );

    // final spacer
    printf( "************************************\n" );

    return 0; // indicate successful termination of main
} // end Function Main

// Function implementations
void Encrypt(const char * in, char * out, int displacement)
{
    int i; // for loop counter

    // loop through the alphabet, encrypting by 5 and making sure to wrap back around at the end
    for(i = 0; i <= 1000; i++)
     {
         if (in[i] > 96 && in[i] < 123) // a - z
        { 
            * out = (in[i] + displacement); 
        }
         else if (in[i] > 64 && in[i] < 91) // A - Z
        {
            * out = (in[i] + displacement);      
        }
         else // other characters remain constant
        {   
            * out = in[i];
        }
     } // end for

} // end Function Encrypt

void Decrypt(char * out, char * decryptout, int displacement)
{
    int i; // loop counter

    for ( i = 0; i <= 1000; i++ )
    {
        if (out[i] > 96 && out[i] < 123) // a - z
        {   
            * out = (decryptout[i] - displacement); 
        }
        else if (decryptout[i] > 64 && decryptout[i] < 91) // A - Z
        {
            * out = (decryptout[i] - displacement);      
        }
        else // other characters remain constant
        {   
            * out = decryptout[i];
        }
    } // end for
} // end Function Decrypt

/* I really couldn't figure this one out. I know there's defintely a good amount of things I'm doing wrong 
but primarily, I just couldnt figure out how to encrypt correctly, especially with the const getting in the
way in some situations. Oh well */