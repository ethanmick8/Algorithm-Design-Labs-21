/*
 * CS1050
 * Fall 2021
 * Prelab 11 
 * by Jim Ries
 */
#include <stdio.h>

// Symbolic Constants
#define FILENAME "DnDMonsterScores.csv"

// Main
int main(void)
{

    FILE * fp;
    char name[256];
    int count = 0;

    fp = fopen(FILENAME,"r");
    // Only keep going if we are able to open the file
    if (NULL!=fp)
    {
        fgets(name,255,fp);
        name[255]='\0';
        printf("Header line was: %s\n",name);

        // Read some important data
        if (fp && !feof(fp))
        {
            int ac,hp,dummy,cha;

            // Only print if we can read all of the (9) fields we expect
            if (9==fscanf(fp," %[^,],%d,%d,%d,%d,%d,%d,%d,%d,",
                name,&ac,&hp,&dummy,&dummy,&dummy,&dummy,&dummy,&cha))
            {
                printf("\"%s\" : AC=%d,HP=%d,CHA=%d\n",name,ac,hp,cha);
            }
        }

        // If you successfully open a file, you had better close it
        fclose(fp);
    }
    else    // Print an error message if we can't open the file
    {
        printf("Unable to open file %s\n",FILENAME);
    }
}